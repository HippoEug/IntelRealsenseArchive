#include <iostream>
#include <fstream>
#include <sstream>

#include <librealsense2/rs.hpp> // Include Realsense Cross Platform API
#include "realsense\example.hpp" // Include some rendering functions for convenience
#define STB_IMAGE_WRITE_IMPLEMENTATION // Include header files for writing png file
#include "realsense\stb_image_write.h" // Include header files for writing png file

#include "rsfunctions.hpp"

#include "displayfunctions.hpp" 

int getChoice() {
	int choice;
	system("CLS");

	std::cout << "=============[STREAM]=============" << std::endl;
	std::cout << "1. Preview Depth & RGB Cameras" << std::endl;
	std::cout << "2. Preview 3D PointCloud" << std::endl;
	std::cout << "==============[SAVE]==============" << std::endl;
	std::cout << "3. Save Color & Depth Preview PNG" << std::endl;
	std::cout << "4. Save Preview MetaData" << std::endl;
	std::cout << "5. Capture Relevant Data" << std::endl;
	std::cout << "=========[MSC' FUNCTIONS]=========" << std::endl;
	std::cout << "6. Get Distance" << std::endl;
	std::cout << "7. Select Coordinates of Object" << std::endl;
	std::cout << "\nChoice: ";
	std::cin >> choice;

	return choice;
}

void terminateChoice(int& choice) {
	system("CLS");

	std::cout << "00. Terminate Preview" << std::endl;
	std::cout << "\nChoice: ";
	std::cin >> choice;
}

void preview2D(int& choice) {
	texture depth_image, color_image; // Declare two different textures on GPU for image rendering
	rs2::colorizer color_map; // Declare depth colorizer for visualization of depth data, helper to colorize depth images
	rs2::pipeline pipe; // Declare Realsense Pipeline, encapsulating actual device and sensors, no parameters will start default stream

	pipe.start(); // Start pipeline for streaming with default config
	window app(1280, 600, "Preview 2D"); // Create OpenGL rendering window

	while (app && (choice != 00)) { // While application still alive
		rs2::frameset data = pipe.wait_for_frames(); // Block application until a frameset is available

		rs2::frame depth = color_map(data.get_depth_frame()); // Find and colorize the depth data
		rs2::frame color = data.get_color_frame(); // Find the color data

		depth_image.render(depth, { 0, 0, app.width() / 2, app.height() }); // Render depth on to the first half of the screen
		color_image.render(color, { app.width() / 2, 0, app.width() / 2, app.height() }); // Render color on to the second half of the screen
	}

	pipe.stop(); // Stop pipeline
}

void preview3D(int& choice) {
	// TODO: Fix example.hpp -> Zooming in and out

	rs2::pointcloud pc; // Declare pointcloud object to calculate pointclouds and texture mappings
	rs2::points points; // Makes points object to be persistent so last cloud is still displayed should there be frame drops
	rs2::pipeline pipe; // Declare Realsense Pipeline, encapsulating actual device and sensors

	pipe.start(); // Start pipeline for streaming with default config
	window app(1280, 600, "Preview 3D"); // Create OpenGL rendering window

	glfw_state app_state; // Declare object to manage view state
	register_glfw_callbacks(app, app_state); // Register callbacks to allow manipulation of pointcloud, ie panning using mouse

	while (app && (choice != 00)) { // While application still alive
		auto frames = pipe.wait_for_frames(); // Wait for next set of frames from the camera
		auto depth = frames.get_depth_frame(); // Wait for next set of frames fromt the camera

		points = pc.calculate(depth); // Generate the pointcloud and texture mappings
		auto color = frames.get_color_frame(); // Generate the pointcloud and texture mappings

		pc.map_to(color); // Map pointcloud object to color frame
		app_state.tex.upload(color); // Upload color frame to OpenGL

		draw_pointcloud(app.width(), app.height(), app_state, points); // Draw the pointcloud
	}

	pipe.stop(); // Stop pipeline
}

void save2DPreview() {
	rs2::colorizer color_map; // Declare depth colorizer for visualization of depth data
	rs2::pipeline pipe; // Declare Realsense Pipeline, encapsulating actual device and sensors

	pipe.start(); // Start pipeline for streaming with default config

	for (auto i = 0; i < 30; ++i) { // Capture 30 frames for camera hardware to settle
		pipe.wait_for_frames();
	}

	for (auto&& frame : pipe.wait_for_frames()) // Get next set of frames from the camera
	{
		// We can only save video frames as pngs, so we skip the rest
		if (auto vf = frame.as<rs2::video_frame>())
		{
			auto stream = frame.get_profile().stream_type();
			// Use the colorizer to get an rgb image for the depth stream
			if (vf.is<rs2::depth_frame>()) vf = color_map(frame);

			// Write images to disk
			std::stringstream png_file;
			png_file << "capture-" << vf.get_profile().stream_name() << ".png";
			stbi_write_png(png_file.str().c_str(), vf.get_width(), vf.get_height(),
				vf.get_bytes_per_pixel(), vf.get_data(), vf.get_stride_in_bytes());
			std::cout << "Saved " << png_file.str() << std::endl;

			// Record per-frame metadata for UVC streams
			std::stringstream csv_file;
			csv_file << "capture-" << vf.get_profile().stream_name() << "-metadata.csv";

			std::ofstream csv;
			csv.open(csv_file.str());

			//    std::cout << "Writing metadata to " << filename << endl;
			csv << "Stream," << rs2_stream_to_string(vf.get_profile().stream_type()) << "\nMetadata Attribute,Value\n";
		}
	}

	pipe.stop(); // Stop pipeline
}

void saveMetaData() {
	// TODO: Implement
}

void saveRData() {
	// TODO: Implement

	int x = 0;
	int y = 0;
	int z = 0;

	std::ofstream outFile;
	outFile.open("xyz-depth-data.csv");
	outFile << "x" << "," << "y" << "," << "z" << std::endl;
	outFile << x << "," << y << "," << z << std::endl;
	outFile.close();
}

void getDistance() {
	// TODO: Fix display and termination

	rs2::pipeline pipe; // Declare Realsense Pipeline, encapsulating actual device and sensors

	pipe.start(); // Start pipeline for streaming with default config
	//float width = depth.get_width();
	//float height = depth.get_height();
	//float dist_to_center = depth.get_distance(width / 2, height / 2);

	rs2::frameset frames = pipe.wait_for_frames();
	rs2::depth_frame depth = frames.get_depth_frame();
	std::cout << depth.get_distance(640, 360) << std::endl; // For center of camera
}
