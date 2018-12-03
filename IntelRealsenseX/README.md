# IntelRealsenseX

## Installation Guide
1. Create new Visual C++ Project (Recommended: Empty Project)
2. Go to View > Other Windows > Property Manager
3. Click on "Add Existing Property Sheet" icon
4. Navigate to "C:\Program Files (x86)\Intel RealSense SDK 2.0"
5. Add intel.realsense.props, now #include <librealsense2/rs.h> can be used
6. Navigate to your newly created Project in File Explorer
7. Copy and paste these files [example.hpp, int-rs-splash.hpp, stb_easy_font.h, stb_image.h, stb_image_write.h] inside
8. Right Click on Source Files in Solution Explorer
9. Create new CPP File (Name: Source.CPP)
10. Refresh CPP Project

#### Adding OpenCV Library
1. Verify Visual Studio toolbar has Solution Configurations set to "Debug", and Solution Platforms to "x64"
NOTE: New versions of OpenCV only supports x64 binaries
2. Project > Properties (Active(Debug)) > Configuration Properties > VC++ Directories > Include Directories > Add > C:\OpenCV-3.4.3\opencv\build\include
3. Project > Properties (Active(Debug)) > Configuration Properties > VC++ Directories > Library Directories > Add > C:\OpenCV-3.4.3\opencv\build\x64\vc15\lib
4. Open Windows File Explorer > C:\OpenCV-3.4.3\opencv\build\x64\vc15\lib > Copy the filename "opencv_world343d.lib"
5. Visual Studio > Project > Properties > Configuration Properties > Linker > Input > Additional Dependencies > Edit > opencv_world343d.lib

#### If "fopen" error warning occurs, do the following to fix compiler:
1. Select Project and click "Properties" from the context menu
2. Go to Configuration Properties > C/C++ > Preprocessor
3. Add ;_CRT_SECURE_NO_WARNINGS in the ProprocessorDefinitions field

#### TO-READ
- Getting points from .bag file: https://communities.intel.com/thread/128530
- https://github.com/IntelRealSense/librealsense/wiki/Projection-in-RealSense-SDK-2.0
- Open3D Library
    - https://github.com/IntelVCL/Open3D
    - https://github.com/IntelRealSense/librealsense/issues/2463
    - https://github.com/IntelVCL/Open3D/issues/231

#### Sources: 
- https://github.com/IntelRealSense/librealsense/blob/master/doc/installation_windows.md (CMake Windows Installation)
- https://communities.intel.com/message/548179#548179 (First contact with D415, What should I do)

## CMake Guide for Intel Realsense D435

1. Save librealsense-2.16.1 on **desktop**
2. On CMake, place the directory as ../Desktop/librealsense-2.16.1. 
3. Configuration:
    - Where is the source code: C:/Users/efoo1/Desktop/librealsense-2.16.1
    - Where to build the binaries: C:/Users/efoo1/Desktop/librealsense-2.16.1/build
4. Now the CMake generated files is present on C:\Users\efoo1\Desktop\librealsense-2.16.1\build

## OpenCV Wrappers for Realsense
- https://github.com/IntelRealSense/librealsense/tree/master/wrappers/opencv [GitHub Page]
- https://communities.intel.com/thread/129435 (I want to extract information(depth,object name) from 'dnn' in real time as text
 
## Realsense GitHub Useful and Relevant Issues
- https://github.com/IntelRealSense/librealsense/issues/2200 (How to get the depth value of a specific coordinate through the stored depth picture)
- https://github.com/IntelRealSense/librealsense/issues/2348 (How to get real distance from 16-bit value in depth image)
- https://github.com/IntelRealSense/librealsense/issues/2229 (Changing disparity shift in c++)

## StackOverflow PointCloud and Volume Questions
- https://stackoverflow.com/questions/41267210/point-cloud-xyz-format-specification
- https://stackoverflow.com/questions/35970803/algorithm-for-calculating-the-volume-of-the-part-of-point-cloud

## External Wrapper Libraries
- https://github.com/glfw/glfw
- https://github.com/ocornut/imgui
