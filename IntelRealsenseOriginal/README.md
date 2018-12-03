# Intel-Realsense-D435

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

#### Source: 
- https://github.com/IntelRealSense/librealsense/blob/master/doc/installation_windows.md (CMake Windows Installation)
- https://communities.intel.com/message/548179#548179 (First contact with D415, What should I do)

#### If "fopen" error warning occurs, do the following to fix compiler:
1. Select Project and click "Properties" from the context menu
2. Go to Configuration Properties > C/C++ > Preprocessor
3. Add ;_CRT_SECURE_NO_WARNINGS in the ProprocessorDefinitions field

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

## CMake Guide for Intel Realsense D435

1. Save librealsense-2.16.1 on **desktop**
2. On CMake, place the directory as ../Desktop/librealsense-2.16.1 as seen in the attached picture. 
![image](https://user-images.githubusercontent.com/21957042/46134155-d1ffd780-c274-11e8-8807-8b0fc5b6f02a.png)

3. Configuration:

![image](https://user-images.githubusercontent.com/21957042/46134460-81d54500-c275-11e8-91fc-72732a6c78e7.png)

_- clicked on Yes_

![image](https://user-images.githubusercontent.com/21957042/46134522-a7fae500-c275-11e8-9ed0-3125c4f489b5.png)

_- leave everything on default and click Finish_

![image](https://user-images.githubusercontent.com/21957042/46134627-f27c6180-c275-11e8-898d-9c5c11acf89f.png)
_- Performing Test COMPILER_SUPPORTS_CXX0X - Failed_ however... the [log](https://hastebin.com/cafamipata.sql) is here if it helps in any way. Clicked on Generate afterwards.


4. Now I have the CMake generated files on C:\Users\efoo1\Desktop\librealsense-2.16.1\build
![image](https://user-images.githubusercontent.com/21957042/46134824-60288d80-c276-11e8-999e-99a388eeadc0.png)
