#include <iostream>
#include <fstream>

#include <librealsense2\rs.hpp>
#include "imgui\imgui.h"
#include "imgui\imgui_impl_glfw.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION // Include header files for writing png file, fixes Linker error
#include "realsense\stb_image_write.h"

#include "displayfunctions.hpp"
#include "rsgui.hpp"
#include "imguifunctions.hpp"

void rsgui::init() {
	window.onCreate(1280, 720, "IntelRealsenseXOneS");
	ImGui_ImplGlfw_Init(window, false);

	texture_rs rgbPreview, depthPreview;
	rs2::colorizer color_map;
	rs2::pipeline pipe;

	pipe.start(); // Cannot loop this over and over again

	int counter = 0;
	bool show_color_camera = false;
	bool show_depth_camera = false;
	bool button_pressed = false;

	while (window) {
		ImGui_ImplGlfw_NewFrame(1);
		menuGUIx(show_color_camera, show_depth_camera, button_pressed);

		if (show_color_camera == true || show_depth_camera == true) {
			rs2::frameset data = pipe.wait_for_frames();
			rs2::frame color = data.get_color_frame();
			rs2::frame depth = color_map(data.get_depth_frame());

			if (show_color_camera) {
				rgbPreview.render(color, { 640, 0, window.width() / 2, window.height() / 2 });
			}

			if (show_depth_camera) {
				depthPreview.render(depth, { 640, 360, window.width() / 2, window.height() / 2 });
			}
		}

		if (button_pressed) {
			button_pressed = true;

			for (auto i = 0; i < 10; ++i) { // Capture 30 frames for camera hardware to settle
				pipe.wait_for_frames();
			}

			for (auto&& frame : pipe.wait_for_frames()) // Get next set of frames from the camera
			{
				// We can only save video frames as pngs, so we skip the rest
				if (auto vf = frame.as<rs2::video_frame>())
				{
					std::cout << "WATCHA SAY BRUV" << std::endl;
					auto stream = frame.get_profile().stream_type();
					// // Use the colorizer to get an rgb image for the depth stream
					if (vf.is<rs2::depth_frame>()) vf = color_map(frame);

					// Write images to disk
					std::stringstream png_file;
					png_file << "capture-" << vf.get_profile().stream_name() << ".png";
					stbi_write_png(png_file.str().c_str(), vf.get_width(), vf.get_height(), vf.get_bytes_per_pixel(), vf.get_data(), vf.get_stride_in_bytes());
					std::cout << "Saved " << png_file.str() << std::endl;
				}
			}

			button_pressed = false;
		}
		
	}
}
