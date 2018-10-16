#include <iostream>
#include <stdio.h>

#include <librealsense2\rs.hpp>
#include "imgui\imgui.h"
#include "imgui\imgui_impl_glfw.h"

#include "displayfunctions.hpp"

int main(int argc, char* argv[]) {
	window_rs window(1280, 720, "IntelRealsenseXOneS");
	ImGui_ImplGlfw_Init(window, false);

	texture_rs rgbPreview;
	rs2::pipeline pipe;
	pipe.start();

	while (window) {
		rs2::frameset data = pipe.wait_for_frames();
		rs2::frame color = data.get_color_frame();
		rgbPreview.render(color, { 0, 0, window.width()/2, window.height()/2 });

		ImGui_ImplGlfw_NewFrame(1);
		ImGui::Begin("HEllo");
		ImGui::End();
		ImGui::Render();
	}
}
