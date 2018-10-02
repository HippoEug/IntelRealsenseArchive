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

#### Sources: 
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
