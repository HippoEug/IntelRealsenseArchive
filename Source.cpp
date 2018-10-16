#include <iostream>
#include <stdio.h>

#include "displayfunctions.hpp"
#include "imguifunctions.hpp"
#include "rsgui.hpp"

int main(int argc, char* argv[]) {
	window_rs window(1280, 720, "IntelRealsenseXOneS");
	ImGui_ImplGlfw_Init(window, false);

	texture_rs rgbPreview;
	rs2::pipeline pipe;
	pipe.start();

	static AppLog log;
	bool show_color_camera = false;
	bool show_depth_camera = false;
	bool show_app_log = false;

	bool button_pressed = false;

	while (window) {
		rs2::frameset data = pipe.wait_for_frames();
		rs2::frame color = data.get_color_frame();
		rgbPreview.render(color, { 0, 0, window.width()/2, window.height()/2 });

		ImGui_ImplGlfw_NewFrame(1);
		menuGUI(show_color_camera, show_depth_camera, show_app_log, button_pressed);
	}
}
