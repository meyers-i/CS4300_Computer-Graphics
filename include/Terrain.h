/** @file Terrain.h
 *  @brief Create a terrain
 *  
 *  More...
 *
 *  @author Mike
 *  @bug No known bugs.
 */
#ifndef TERRAIN_H
#define TERRAIN_H

#include "Object.h"
#include "Texture.h"
#include "Shader.h"
#include "Image.h"
#include <vector>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <numeric>
#include <random>

class Terrain : public Object {
public:
    // Takes in a Terrain and a filename for the heightmap.
    Terrain (unsigned int xSegs, unsigned int zSegs, std::string fileName);
	// Takes in a seed and creates a new Terrain for the heightmap
	Terrain(unsigned int xSegs, unsigned int zSegs, unsigned int seed);
	// Destructor
    ~Terrain ();
    // override the initilization routine.
    void init();
    // Loads a heightmap based on a PPM image
    // This then sets the heights of the terrain.
    void loadHeightMap(Image image);
	// Creates a new ppm to be used for the heightmap
	void drawPPM();
	// Uses Perlin noise algorithm
	float noise(float x, float y, float z);
	// Creates a new ppm to be used as the color map
	void drawColorMap();

private:
    // data
    unsigned int xSegments;
    unsigned int zSegments;

    // Store the height in a multidimensional array
    int* heightData;

    // Textures for the terrain
    // Terrains are often 'multitextured' and have multiple textures.
    std::vector<Texture> textures;
	// Permutation vector for seeding
	std::vector<int> p;
	// Fading
	float fade(float t);
	// Linear interpolation
	float lerp(float t, float a, float b);
	// Gradient
	float grad(int hash, float x, float y, float z);
	// Stores the noise value after Perlin noise calculation
	float _noise;
	// width
	int width;
	// height
	int height;
};

#endif
