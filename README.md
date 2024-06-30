# Pacman-AI
- An improvement upon my previous pacman project in python. This project is written in C++ for higher control of memory and preformance
- In the future, you will be able to play as Pacman, or watch Pacman's AI sweep the board
- I have plans to implement multithreading for fast, real-time decision making by Pacman's AI

## What I've done on this Project
- All C++ and header files have been fully written by me, with the exception of TextureManager.h, TextureManager.cpp, Game.h, Game.cpp, and main.cpp. I have made slight to significant changes to the last three. The TextureManager files are unaltered.
- This project uses the SDL2 and SDL_Image C libraries. I decided to watch a tutorial on YouTube for learning these libraries. All files listed above are from this tutorial. You can find it here: https://www.youtube.com/watch?v=44tO977slsU&t=418s. The tutorial serves as a guide for developing general game structure, not specific to Pacman.

## Compiling and Running
- If you are on a Windows machine, you should not have to change anything in this repository to compile and run this project.
- Have your operating system point to the project directory. Open a terminal and run the `make` command to compile.
- After you've compiled the project, enter `make run`.
- If you are not on Windows, all necesary files are here, but you must change the Makefile and location of SDL library files as appropriate for your operating system and environment.

## Downloading SDL
Download SDL2: https://github.com/libsdl-org/SDL/releases/tag/release-2.30.3<br>
Download SDL_image: https://github.com/libsdl-org/SDL_image/releases

## At a Glance
All C++ game files are in the /include/Game directory. This project takes advantage of precise memory control given by C++. We want to avoid heap allocated memory as much as possible using the `new` keyword. Stack allocated memory has less overhead and tends to be cached in the CPU. Because the game runs at 60fps, we only have 1/60th of a second for each frame. Speed is crucial, espically for scaling up the project in the future.

The object oriented design is made to be intuitive. The Game class has an EntityManager object, which has Entity objects. Entities are all things the game needs to keep track of. Entity has 2 derived classes, Agent and Item. Agents move, Items are stationary. The Agent class has two derived classes, Player and Ghost. The power of polymorphism allows us to reference all of these classes as Entities while giving each of them unique members and behavior. the Entity class implements the Axis Aligned Bounding Box algorithm, or AABB. This algorithm determines if two rectangular sprites overlap, prefect for 2D Entity collision.

## What's Next
- Give the Agent class a Sector object. A Sector contains all Entities within a small region of the game board. When implementing collision checks, we only want to check entities within an Agent's sector instead of every entity in the game.
- Implement wall colision in the Agent class. If an Agent collides with a wall, push it out and set it's speed to zero.
- Assign each Agent a grid position. This is the (x,y) coordinate of the Agent's tile and can be calculated with integer division.
