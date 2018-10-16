#include <iostream>
#include <stdio.h>

#include <librealsense2\rs.hpp> // IMPORTANT I THINK

#include "imgui\imgui.h" // ALSO IMPORTANT
#include "imgui\imgui_impl_glfw.h"
#include "realsense\example.hpp"

int main(int argc, char* argv[]) {
	window window(1280, 720, "Realsense");
	ImGui_ImplGlfw_Init(window, false);

	texture color_image;
	rs2::pipeline pipe;
	pipe.start();

	while (window) {
		rs2::frameset data = pipe.wait_for_frames();
		rs2::frame color = data.get_color_frame();
		color_image.render(color, { 0, 0, window.width()/2, window.height()/2 });

		ImGui_ImplGlfw_NewFrame(1);
		ImGui::Begin("HEllo");
		ImGui::End();
		ImGui::Render();
	}
}
