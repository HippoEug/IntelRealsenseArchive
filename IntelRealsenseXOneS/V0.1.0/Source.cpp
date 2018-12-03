#include <iostream>
#include <thread>
#include <stdio.h>

#include "imgui_x.hpp"
#include "realsense_gui_x.hpp"
#include "displayhelper.hpp"

int main(int argc, char* argv[]) {
	//initGlfwRS();
	window_rs window(1280, 720, "Realsense");
	texture_rs color_image;

	//std::thread t1(&window_rs::showSimpleMenu, window);
	//t1.join();
	//window.showSimpleMenu();
	
	rs2::pipeline pipe;
	pipe.start();

	while (window) {
		rs2::frameset data = pipe.wait_for_frames();
		rs2::frame color = data.get_color_frame();
		color_image.render(color, { window.width() / 2, 0, window.width(), window.height() });

		ImGui_ImplGlfw_NewFrame(1);
		ImGui::Begin("slider");

		ImGui::End();
		ImGui::Render();
	}
}
