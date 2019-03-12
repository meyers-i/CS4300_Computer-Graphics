#include "Terrain.h"
#include "Image.h"

// Constructor for our object
// Calls the initialization method
Terrain::Terrain(unsigned int xSegs, unsigned int zSegs, std::string fileName) : 
                xSegments(xSegs), zSegments(zSegs) {
	std::cout << "(Terrain.cpp) Constructor called \n";
    // Load up some image data
    Image heightMap(fileName);
    heightMap.loadPPM(true);
    // Set the height data for the image
    // TODO: Currently there is a 1-1 mapping between a pixel and a segment
    // You might consider interpolating values if there are more segments
    // than pixels. 
    float scale = 5.0f; // Note that this scales down the values to make
                        // the image a bit more flat.
    // Create height data
    heightData = new int[xSegments*zSegments];
    // Set the height data equal to the grayscale value of the heightmap
    // Because the R,G,B will all be equal in a grayscale iamge, then
    // we just grab one of the color components.
    

    // TODO: (Inclass) Implement populate heightData!
	for (unsigned int z = 0; z < zSegments; ++z) {
		for (unsigned int x = 0; x < xSegments; ++x) {
			heightData[x + z * xSegments] = (float)heightMap.getPixelR(z, x) / scale;
		}
	}


    init();
}

Terrain::Terrain(unsigned int xSegs, unsigned int zSegs, unsigned int seed) : 
	xSegments(xSegs), zSegments(zSegs), width(xSegs), height(zSegs) {

	std::cout << "(Terrain.cpp) Constructor 2 called \n";
	p.resize(256);
	std::iota(p.begin(), p.end(), 0);
	std::default_random_engine engine(seed);
	std::shuffle(p.begin(), p.end(), engine);
	p.insert(p.end(), p.begin(), p.end());
	drawPPM();
	Image heightMap("terrain3.ppm");
	heightMap.loadPPM(true);
	float scale = 5.0f; // Note that this scales down the values to make
						// the image a bit more flat.
						// Create height data
	heightData = new int[xSegments*zSegments];
	// Set the height data equal to the grayscale value of the heightmap
	// Because the R,G,B will all be equal in a grayscale iamge, then
	// we just grab one of the color components.


	// TODO: (Inclass) Implement populate heightData!
	for (unsigned int z = 0; z < zSegments; ++z) {
		for (unsigned int x = 0; x < xSegments; ++x) {
			heightData[x + z * xSegments] = (float)heightMap.getPixelR(z, x) / scale;
		}
	}
	init();
	drawColorMap();
}

float Terrain::noise(float x, float y, float z) {
	int X = (int)floor(x) & 255;
	int Y = (int)floor(y) & 255;
	int Z = (int)floor(z) & 255;

	x -= floor(x);
	y -= floor(y);
	z -= floor(z);

	float u = fade(x);
	float v = fade(y);
	float w = fade(z);

	int A = p[X] + Y;
	int AA = p[A] + Z;
	int AB = p[A + 1] + Z;
	int B = p[X + 1] + Y;
	int BA = p[B] + Z;
	int BB = p[B + 1] + Z;

	float res = lerp(w, lerp(v, lerp(u, grad(p[AA], x, y, z), grad(p[BA], x - 1, y, z)), lerp(u, grad(p[AB], x, y - 1, z), 
		grad(p[BB], x - 1, y - 1, z))), lerp(v, lerp(u, grad(p[AA + 1], x, y, z - 1), grad(p[BA + 1], x - 1, y, z - 1)), 
			lerp(u, grad(p[AB + 1], x, y - 1, z - 1), grad(p[BB + 1], x - 1, y - 1, z - 1))));
	return (res + 1.0) / 2.0;
}

float Terrain::fade(float t) {
	return t * t * t * (t * (t * 6 - 15) + 10);
}

float Terrain::lerp(float t, float a, float b) {
	return a + t * (b - a);
}

float Terrain::grad(int hash, float x, float y, float z) {
	int h = hash & 15;
	double u = h < 8 ? x : y,
		v = h < 4 ? y : h == 12 || h == 14 ? x : z;
	return ((h & 1) == 0 ? u : -u) + ((h & 2) == 0 ? v : -v);
}

// Destructor
Terrain::~Terrain(){
    if(heightData!=nullptr){
        delete heightData;
    }
}

// Creates a grid of segments
// This article has a pretty handy illustration here:
// http://www.learnopengles.com/wordpress/wp-content/uploads/2012/05/vbo.png
// of what we are trying to do.
void Terrain::init(){
    // Create the initial grid of vertices.

    // TODO: (Inclass) Build grid of vertices!
	for (unsigned int z = 0; z < zSegments; ++z) {
		for (unsigned int x = 0; x < xSegments; ++x) {
			geometry.addVertex(x, heightData[x + z * xSegments], z);

			float u = 1.0f - ((float)x / (float)xSegments);
			float v = 1.0f - ((float)z / (float)zSegments);
			geometry.addTexture(u, v);
		}
	}
    

    // Figure out which indices make up each triangle
    // By writing out a few of the indicies you can figure out
    // the pattern here. Note there is an offset.
    
    // TODO: (Inclass) Build triangle strip
	for (unsigned int z = 0; z < zSegments - 1; ++z) {
		for (unsigned int x = 0; x < xSegments - 1; ++x) {
			geometry.addIndex(x + (z * zSegments));
			geometry.addIndex(x + (z * zSegments) + xSegments);
			geometry.addIndex(x + (z * zSegments) + 1);

			geometry.addIndex(x + (z * zSegments) + 1);
			geometry.addIndex(x + (z * zSegments) + xSegments);
			geometry.addIndex(x + (z * zSegments) + xSegments + 1);
		}
	}
   



   // Finally generate a simple 'array of bytes' that contains
   // everything for our buffer to work with.
   geometry.gen();  
   // Create a buffer and set the stride of information
   myBuffer.CreateBufferNormalMapLayout(14,
                                            geometry.getSize(),
                                            geometry.getIndicesSize(),
                                            geometry.getData(),
                                            geometry.getIndicesData());

}

// Loads an image and uses it to set the heights of the terrain.
void Terrain::loadHeightMap(Image image){

}

void Terrain::drawPPM() {
	// Create a file for which to draw our output to.
	std::ofstream myFile;
	myFile.open("C:\\Users\\Ian\\Documents\\CS4300\\inclass8-meyers-i\\terrain3.ppm");
	//myFile.open("terrain3.ppm");

	// Dimensions of the image in X and Y for the "window".
	int nx = width;
	int ny = height;
	int size = nx * ny;
	myFile << "P3\n" << "# CREATOR: IAN MEYERS\n" << nx << " " << ny << "\n255\n";
	std::cout << "header written\n";

	std::vector<float> r;
	std::vector<float> g;
	std::vector<float> b;

	r.resize(size);
	g.resize(size);
	b.resize(size);
	std::cout << "RGB vectors initialized\n";

	unsigned int ii = 0;
	
	for (int j = ny - 1; j >= 0; j--) {
		for (int i = 0; i < nx; i++) {
			float u = (float)i / (float)nx;
			float v = (float)j / (float)ny;

			//_noise = 20 * noise(u, v, 0.8);
			//_noise = _noise - floor(_noise);
			_noise = noise(10 * u, 10 * v, 0.8);

			r[ii] = floor(255 * _noise);
			g[ii] = floor(255 * _noise);
			b[ii] = floor(255 * _noise);
			ii++;
		}
	}
	
	for (unsigned int i = 0; i < size; i++) {
		myFile << r[i] << "\n" << g[i] << "\n" << b[i] << "\n";
	}
	
	// Always remember to close your file!
	myFile.close();
}

void Terrain::drawColorMap() {
	std::ofstream myFile;
	myFile.open("C:\\Users\\Ian\\Documents\\CS4300\\inclass8-meyers-i\\color2.ppm");
	//myFile.open("color2.ppm");

	int nx = width;
	int ny = height;
	int size = nx * ny;
	myFile << "P4\n" << "# CREATOR: IAN MEYERS\n" << nx << " " << ny << "\n255\n";
	std::cout << heightData;

	Image heightMap("terrain3.ppm");
	heightMap.loadPPM(true);

	std::vector<int> arr;
	arr.resize(size);

	int k = 0;
	int arr_size = 0;

	for (int j = 0; j < nx; j++) {
		for (int i = 0; i < nx; i++) {
			arr[k] = heightMap.getPixelR(j, i);
			k++;
		}
	}
	arr_size = arr.size();

	for (unsigned int i = 0; i < size; i++) {
		// sea level
		if (arr[i] <= 110) {
			myFile << 66 << "\n" << 182 << "\n" << 244 << "\n";
		}
		// sand
		else if (arr[i] <= 115) {
			myFile << 237 << "\n" << 225 << "\n" << 166 << "\n";
		}
		// dirt
		else if (arr[i] <= 120) {
			myFile << 122 << "\n" << 82 << "\n" << 30 << "\n";
		}
		// grass
		else if (arr[i] <= 140) {
			myFile << 28 << "\n" << 175 << "\n" << 67 << "\n";
		}
		// lighter grass
		else if (arr[i] <= 145) {
			myFile << 57 << "\n" << 186 << "\n" << 91 << "\n";
		}
		// more dirt
		else if (arr[i] <= 150) {
			myFile << 189 << "\n" << 214 << "\n" << 164 << "\n";
		}
		// almost at the peak
		else if (arr[i] <= 155) {
			myFile << 221 << "\n" << 155 << "\n" << 93 << "\n";
		}
		// snowcap
		else {
			myFile << 211 << "\n" << 229 << "\n" << 216 << "\n";
		}
	}
	myFile.close();
}
