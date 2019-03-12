# Final Project - Computer Graphics

*TODO*: Please edit the following information in your assignment

* Name and partners name(At most 1 partner for this project!)
  * Ian Meyers
* How many hours did it take you to complete this lab? 20
* Did you collaborate or share ideas with any other students/TAs/Professors?
* Did you use any external resources? 
  * Note it is fair to find some tutorials--but you must cite them!
  * https://www.scratchapixel.com/lessons/procedural-generation-virtual-worlds/perlin-noise-part-2
  * http://flafla2.github.io/2014/08/09/perlinnoise.html
  *
  * (Optional) What was the most interesting part of the Final Assignment? How would you improve this assignment?

* Video Overview: https://youtu.be/EQ60CBeHunc
 
## Description

An important part of any computer graphics course in my opinion, is having the opportunity to build a project that showcases your creativity and can be used as a portfolio piece for future internship, co-op, and full-time job opportunities.  We have covered enough OpenGL now that you are ready to design and create a project from scratch.
  
## Expectations

You can work on any idea you want that is within the scope of graphics.  You may explore areas that we did not cover heavily in class (Animation, particles, different rendering techniques, advanced shaders, etc.).  Your final project should be on the order of the difficulty beyond the homeworks (You will the rest of the term to work on this project with a partner).  

## Project Ideas

I am going to list a few project ideas that I think are within the scope of this class.

* Procedural generation
  * Terrain rendering [https://www.youtube.com/watch?v=QjTPIbJNO6I]
  * City [https://www.youtube.com/watch?v=-d2-PtK4F6Y]
  * Continuous LOD [https://www.youtube.com/watch?v=DUxAyfuJULc]
* Rendering 
  * Photon maps [https://www.youtube.com/watch?v=GckOkpeJ3BY]
  * Radiosity [https://www.youtube.com/watch?v=8i2M255Zw9I]
* Constructive Solid Geometry
  * [https://www.youtube.com/watch?v=-nWPZgxYW-k]
* Extend Ray Tracer(Our final homework): [https://www.youtube.com/watch?v=ijqaBhyXN98]
  * Depth of field
  * Motion blur
* Modeling
  * Progressive Mesh https://www.youtube.com/watch?v=CcomX9UQO1w
  * Subdivision of surfaces [https://www.youtube.com/watch?v=g1M2y1bZOPw]
  * Or the opposite decimation (mesh simplification) [https://www.youtube.com/watch?v=AvSgHhA9yP4]
  * Deformable mesh [https://www.youtube.com/watch?v=r_rkSi8VZj0]
* Volume rendering
  * Example [https://www.youtube.com/watch?v=nmdlGlJ-2G0]
* Animation
  * Flocking behavior [https://www.youtube.com/watch?v=1svKGmGCdXk]
  * Inverse kinematics [https://www.youtube.com/watch?v=uN_pR9fH-WY]
  * Physics-based simulation (e.g. pinball)
  * Collision detection [https://www.youtube.com/watch?v=ZU5PKXxTv8k]
* Particle Simulation [https://www.youtube.com/watch?v=RMfsdUKEmDo]
* Games
  * Build a little First person perspective(shooter, advenutre, etc.) or other interactive environment
  * Racing game [https://www.youtube.com/watch?v=SVzFWnadOdY]
* Shaders
  * Create a world with many different shaders
    * Cel / Toon shaders [https://www.youtube.com/watch?v=RWTQuvXm2HU]
    * Bump / Normal / Parallax / Relief mapping [Example]
  * Deferred rendering [https://www.youtube.com/watch?v=HIrq4sF5QO8]

### Assignment strategy

My suggested strategy for this project is to:

* You will have plenty of time to think about the project you want to deliver.
  * One of the labs while I am away from GDC is when you will submit your final proposal.
* You can get feedback from me ahead of time on nearly any graphics related topic, do so!
  * I will otherwise provide feedback for our lab (i.e. you will get a thumbs up if the project has potential to be in the A/A- range).
* Find your teammates early if you choose to work in a team!
  * Piazza is a good resource, and the week I am gone from GDC will be the time to get started!
  
### How to run your program

I recommend for the final project you use some of our code from the labs or in-class assignments to get started.

*TODO*: You need to include directions on how to run your program here. 
(Pretend you are deploying this software to someone who has no idea what your code does and needs to be able to run it. You can assume your user has SDL2 setup however)

* Step 1:from a command line window in the project directory, run the build file. ("~ python macbuild.py" for mac and "~ python linuxbuld.py" for linux)
* Step 2:from the same directory, run "./lab"
* Step 3: If on Windows, download the soure code and load it in Microsoft Visual Studio
* Step 4: In Terrain.cpp, comment out lines 174 and 221. Uncomment lines 175 and 222.
* Step 5: In SDLGraphicsProgram.cpp, comment out lines 102, 105, and 106. Uncomment lines 103, 107, and 108
* Step 6: Program should run properly now. If it doesn't, find the directory where Visual Studio stores source code and drag the terrain3.ppm and color2.ppm into your project repository. Alternatively, undo steps 4 and 5, but change the filepath to the path of your project repository.

### Deliverables

* You need to commit your code to this repository.
* You need to have a makefile, compile script, visual studio project, or Xcode project and directions on how to run your program. If your program does not compile and run, you get a zero!

### Rubric

* (33.3%) Project Complection
  * Was the proposed project completed?
  * Does the project compile and run
  * Is it polished without any bugs (No weird visual artifacts)
* (33.3%) Technical
  * Was the implementaiton of the project challenging?
    * Even if you followed some tutoral, it should not be trivial, and have some personal touches to it.
  * Did you have to organize/process a sufficient amount of data.
  * Was it clear you consulted some outside resources that go above and beyond the scope of this class?
* (33.4%) Creativity
  * How visually appealing is the scene?
    * Note: There should be some 'wow' factor.
  * How original is the project
    * Again, did you enhance a tutorial and do something unique or just go by the book?
    
## More Resources

* N/A

## Other FAQ

* N/A
