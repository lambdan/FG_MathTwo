# Davids Math Playground

- Unreal Engine 5.2.1
- Complete game loop (you can start the game, there are objectives, you can die, you can restart)
- Build available in [Releases](https://github.com/lambdan/FG_MathTwo/releases/tag/turn-in)
- ...or look at the nice README below :)

## 1. State and Context

Relevant files: [MathLibrary.h](https://github.com/lambdan/FG_MathTwo/blob/main/Source/FG_MathsBoogaloo/MathLibrary.h), [MathLibrary.cpp](https://github.com/lambdan/FG_MathTwo/blob/main/Source/FG_MathsBoogaloo/MathLibrary.cpp)

- Implemented as Function Library (takes in 2 actors) so it can be used from anywhere
- Guards can see you if you are in front of them
- You can stealth kill them from behind
- If you jump into the "Mario Blocks" from below they break
- If you stand on the lava pools you take damage

![Screenshot](https://djsimg.org/iOhp5UCCVazfE2oT2Uu5.jpg)

## 2. Interpolation

Relevant files: [EasingFunctions.h](https://github.com/lambdan/FG_MathTwo/blob/main/Source/FG_MathsBoogaloo/EasingFunctions.h), [EasingFunctions.cpp](https://github.com/lambdan/FG_MathTwo/blob/main/Source/FG_MathsBoogaloo/EasingFunctions.cpp)

- Implemented as Function Library (takes in a T value) so it can be used from anywhere
- All easing functions from [easings.net](https://easings.net) implemented/converted to C++
- I set up a bunch of cubes that use the different ones to demonstrate them
- The coins also rotate using a random easing function

![GIF](https://djsimg.org/CWyaicpShkoS3XRbA9Ow.gif)

## 3. Intersection

Relevant files: [IntersectionLibrary.h](https://github.com/lambdan/FG_MathTwo/blob/main/Source/FG_MathsBoogaloo/IntersectionLibrary.h), [IntersectionLibrary.cpp](https://github.com/lambdan/FG_MathTwo/blob/main/Source/FG_MathsBoogaloo/IntersectionLibrary.cpp)

- Implemented as Function Library (takes in two actors, two boxes or two spheres) so it can be used from anywhere
- Coins use AABB to determine if they are intersecting with the player (to be collected)
- There is a trigger box you can walk into that turns green when you are inside it (AABB)

![GIF](https://djsimg.org/fbho05vJX2BULEo4h2tC.gif)

## 4. Collision

Relevant files: [CollisionComponent.h](https://github.com/lambdan/FG_MathTwo/blob/main/Source/FG_MathsBoogaloo/CollisionComponent.h), [CollisonComponent.cpp](https://github.com/lambdan/FG_MathTwo/blob/main/Source/FG_MathsBoogaloo/CollisionComponent.cpp)

- Implemented as a Actor Component that can be added to any actor
- Uses IntersectionLibrary from previous exercise to detect colliison
- Only tests for collision against actors with the `COLLISION` tag
- Uses gravity and mass

![GIF](https://djsimg.org/SJAWG1ofc11ryRkYq6Ii.gif)

## 5. Noise

Relevant files: [NoiseMesh.h](https://github.com/lambdan/FG_MathTwo/blob/main/Source/FG_MathsBoogaloo/NoiseMesh.h), [NoiseMesh.cpp](https://github.com/lambdan/FG_MathTwo/blob/main/Source/FG_MathsBoogaloo/NoiseMesh.cpp)

- Implemented as a "flying carpet". It's basically a mesh you stand on and it starts moving, and it "animates" the mesh through perlin noise

![GIF](https://djsimg.org/8E5UdXmRZPKcDR2Nj6PB.gif)

