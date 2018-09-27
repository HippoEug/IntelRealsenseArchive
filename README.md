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


## If "fopen" error warning occurs, do the following to fix compiler:
1. Select Project and click "Properties" from the context menu
2. Go to Configuration Properties > C/C++ > Preprocessor
3. Add ;_CRT_SECURE_NO_WARNINGS in the ProprocessorDefinitions field


## CMake Guide for Intel Realsense D435
Hi there again Sergey,

Trying to follow the CMake Building Guide but to no avail :'(

1. Here is your example. but with the directories blank I am not too sure if I am using the correct one.
![image](https://user-images.githubusercontent.com/21957042/46134230-fa87d180-c274-11e8-9aa5-958309fd60de.png)


2. This is mine. My librealsense-2.16.1 is saved on my **desktop**, so on CMake I just placed the directory as ../Desktop/librealsense-2.16.1 as seen in the attached picture. 
![image](https://user-images.githubusercontent.com/21957042/46134155-d1ffd780-c274-11e8-8807-8b0fc5b6f02a.png)


3. My steps trying to configure it: 
![image](https://user-images.githubusercontent.com/21957042/46134460-81d54500-c275-11e8-91fc-72732a6c78e7.png)
_clicked on Yes_
![image](https://user-images.githubusercontent.com/21957042/46134522-a7fae500-c275-11e8-9ed0-3125c4f489b5.png)
_Left everything on default and clicked Finish_
![image](https://user-images.githubusercontent.com/21957042/46134627-f27c6180-c275-11e8-898d-9c5c11acf89f.png)
_Performing Test COMPILER_SUPPORTS_CXX0X - Failed_ however... the [log](https://hastebin.com/cafamipata.sql) is here if it helps in any way. Clicked on Generate afterwards.


4. Now I have the CMake generated files on C:\Users\efoo1\Desktop\librealsense-2.16.1\build
![image](https://user-images.githubusercontent.com/21957042/46134824-60288d80-c276-11e8-999e-99a388eeadc0.png)
