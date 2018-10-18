#include <iostream>

#include <librealsense2\rs.hpp>
#include "imgui\imgui.h"
#include "imgui\imgui_impl_glfw.h"

#include "displayfunctions.hpp"
#include "rsgui.hpp"
#include "imguifunctions.hpp"

void rsgui::init() {
	window.onCreate(1280, 720, "IntelRealsenseXOneS");
	ImGui_ImplGlfw_Init(window, false);

	texture_rs rgbPreview, depthPreview;
	rs2::colorizer color_map;
	rs2::pipeline pipe;

	pipe.start();

	int counter = 0;
	bool show_color_camera = false;
	bool show_depth_camera = false;
	bool button_pressed = false;

	while (window) { // PROBLEM(?)
		rs2::frameset data = pipe.wait_for_frames();
		rs2::frame color = data.get_color_frame();
		rs2::frame depth = color_map(data.get_depth_frame());

		ImGui_ImplGlfw_NewFrame(1);
		menuGUIx(show_color_camera, show_depth_camera, button_pressed);

		if (show_color_camera) {
			rgbPreview.render(color, { 0, 0, window.width() / 2, window.height() / 2 });
		}

		if (show_depth_camera) {
			depthPreview.render(depth, { window.width() / 2, 0, window.width() / 2, window.width() / 2 });
		}

		if (button_pressed) {
			counter++;
		}
	}
}

void rsgui::testFunc() {
	texture_rs rgbPreview;
	rs2::pipeline pipe;

	pipe.start();

	bool show_color_camera = false;
	bool button_pressed = false;

	while (window) { // PROBLEM(?)
		rs2::frameset data = pipe.wait_for_frames();
		rs2::frame color = data.get_color_frame();
		rgbPreview.render(color, { 0, 0, window.width() / 2, window.height() / 2 });

		//ImGui_ImplGlfw_NewFrame(1); // Commented out since testing 
		//menuGUIx(show_color_camera, button_pressed); // Commented out since testing
	}
}
