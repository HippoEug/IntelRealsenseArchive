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
