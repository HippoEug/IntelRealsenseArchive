# IntelRealsenseXOne

## Installation Guide
1. Create new Visual C++ Project (Recommended: Empty Project)
2. Go to View > Other Windows > Property Manager
3. Click on "Add Existing Property Sheet" icon
4. Navigate to "C:\Program Files (x86)\Intel RealSense SDK 2.0"
5. Add intel.realsense.props, now #include <librealsense2/rs.h> can be used
6. Copy folder [realsense] into Project's File Explorer
7. Copy folder [imgui] into Project's File Explorer
NOTE: Copy the above files from Realsense\third-party\imgui instead of the official imgui release
8. Properties > VC++ > Include Directories > C:\Users\efoo1\Desktop\glfw-3.2.1.bin.WIN32\include
NOTE: 64bit: C:\Users\efoo1\Desktop\glfw-3.2.1.bin.WIN64\include
9. Properties > VC++ > Library Directories > C:\Users\efoo1\Desktop\glfw-3.2.1.bin.WIN32\lib-vc2015
NOTE: 64bit: C:\Users\efoo1\Desktop\glfw-3.2.1.bin.WIN64\lib-vc2015
10. Linker > Input > Additional Dependencies > glfw3.lib + opengl32.lib
11. Create new filters [realsense] & [imgui] and Add > Existing Items > Include all items in respective folders created earlier in steps 6 and 7

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
