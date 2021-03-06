#include <iostream>
#include <fstream>
#include <chrono>

#include <librealsense2\rs.hpp>
#include "imgui\imgui.h"
#include "imgui\imgui_impl_glfw.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION // Include header files for writing png file, fixes Linker error
#include "realsense\stb_image_write.h"

#include "rsgui.hpp" // Corresponding header file
#include "displayfunctions.hpp" // Classes to create GLFW window
#include "imguifunctions.hpp" // Functions to draw ImGui menus
#include "opencvfunctions.hpp" // Functions to select points on image and get coordinates

void rsgui::init() {
	window.onCreate(1280, 720, "IntelRealsenseXOneS"); // Create 1280x720 OpenGL window
	ImGui_ImplGlfw_Init(window, false); // Init ImGui

	texture_rs rgbPreview, depthPreview;
	rs2::colorizer color_map;
	rs2::temporal_filter tempFill;
	rs2::hole_filling_filter holeFill;
	//rs2::pipeline pipe;
	auto pipe = std::make_shared<rs2::pipeline>();

	std::ofstream testFile;
	testFile.open("test.csv");

	rs2::config cfg;
	cfg.enable_stream(RS2_STREAM_COLOR, -1, 1280, 720, rs2_format::RS2_FORMAT_RGB8, 0);
	cfg.enable_stream(RS2_STREAM_DEPTH, -1, 1280, 720, rs2_format::RS2_FORMAT_ANY, 0);

	pipe->start(cfg); // Cannot loop this over and over again

	// Booleans to control ImGui
	bool show_color_camera = false;
	bool show_depth_camera = false;
	bool camera_button = false;
	bool coordinates_button = false;
	bool CSV_button = false;

	// Booleans to control ROSBAG
	bool recorded = false;
	bool recording = false;

	while (window) {
		ImGui_ImplGlfw_NewFrame(1);
		menuGUI(show_color_camera, show_depth_camera, camera_button, coordinates_button, CSV_button);

		if (show_color_camera == true || show_depth_camera == true || camera_button == true || coordinates_button == true || CSV_button == true) {
			if (1) { // If pipeline enabled
				// Skip
			}
			else if (show_color_camera == true || show_depth_camera == true || camera_button == true || coordinates_button == true || CSV_button == true) {
				//pipe->start();
			}
			else {
				//pipe->stop();
			}
		}

		if (show_color_camera == true || show_depth_camera == true) {
			rs2::frameset data = pipe->wait_for_frames().apply_filter(holeFill);
			rs2::frame color = data.get_color_frame();
			rs2::frame depth = color_map.process(data.get_depth_frame());

			if (show_color_camera) {
				rgbPreview.render(color, { 640, 0, window.width() / 2, window.height() / 2 });
			}

			if (show_depth_camera) {
				depthPreview.render(depth, { 640, 360, window.width() / 2, window.height() / 2 });
			}
		}

		if (camera_button) {
			for (auto i = 0; i < 10; ++i) { // Capture 10 frames for camera hardware to settle
				pipe->wait_for_frames();
			}

			for (auto&& frame : pipe->wait_for_frames()) // Get next set of frames from the camera
			{
				// We can only save video frames as pngs, so we skip the rest
				if (auto vf = frame.as<rs2::video_frame>())
				{
					auto stream = frame.get_profile().stream_type();
					// Use the colorizer to get an rgb image for the depth stream
					if (vf.is<rs2::depth_frame>()) vf = color_map.process(frame);

					// Write images to disk
					std::stringstream png_file;
					png_file << "capture-" << vf.get_profile().stream_name() << ".png";
					stbi_write_png(png_file.str().c_str(), vf.get_width(), vf.get_height(), vf.get_bytes_per_pixel(), vf.get_data(), vf.get_stride_in_bytes());
					std::cout << "Saved " << png_file.str() << std::endl;
				}
			}

			camera_button = false;
		}

		if (coordinates_button) {
			selectCoordinates();
			coordinates_button = false;
		}

		if (CSV_button) {
			rs2::frameset frames;
			rs2::frame depth;

			pipe->stop();
			rs2::config cfg;
			cfg.enable_record_to_file("test.bag");
			pipe->start(cfg);

			// capture 1 frame here?

			pipe->stop(); // Stop the pipeline that holds the file and the recorder
			pipe = std::make_shared<rs2::pipeline>(); //Reset the shared pointer with a new pipeline
			pipe->start(); // Resume streaming with default configuration

			CSV_button = false;
		}
	}
}
