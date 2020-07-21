# CPPND: Capstone Hot Dog Detector in a video feed

This program detects hot dogs in videos (at least it tries as hard as it can).

## Here is a rundown on the project's structure:

/src/

        main.cpp              - the starting point and detection logic
        Model.h               - Class that creates a neural network from the Yolo3
        Model.cpp               trained dataset and works with that network
        Detector.h            - Class that process video frames
        Detector.cpp            and opens a video file

/data/

        coco.names            - classifier labels for Yolo3
        hotdogs.mp4           - input video file
        yolov3-tiny.cfg       - Yolo3 configuration
        yolov3-tiny.weights   - Yolo3 trained network

## Rubrics I addressed in this project:

- README
- Compiling and testing
- Loops, Functions, I/O
  - The project reads data from a file and process the data: _main.cpp:19, model.cpp:15_
- Object Oriented Programming
  - The project uses Object Oriented Programming techniques: _Detector.h, Model.h_
  - Classes use appropriate access specifiers for class members: _Detector.h:7, Detector.h:13, Model.h:7, Model.h:15_
  - Class constructors utilize member initialization lists: _Detector.h:8, Model.cpp:5_
  - Classes abstract implementation details from their interfaces: _Detector.h, Detector.cpp, Model.h, Model.cpp_
- Memory Management
  - The project makes use of references in function declarations: _Detector.h:11, Model.h:11_

## Dependencies for Running Locally

- cmake >= 3.7
  - All OSes: [click here for installation instructions](https://cmake.org/install/)
- make >= 4.1 (Linux, Mac), 3.81 (Windows)
  - Linux: make is installed by default on most Linux distros
  - Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  - Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
- OpenCV >= 4.1
  - The OpenCV 4.1.0 source code can be found [here](https://github.com/opencv/opencv/tree/4.1.0)
- gcc/g++ >= 5.4
  - Linux: gcc / g++ is installed by default on most Linux distros
  - Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  - Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./hotdog_video_detector`
