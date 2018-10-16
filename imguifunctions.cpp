#include "imgui\imgui.h"

#include "imguifunctions.hpp"

void menuGUI(bool& show_color_camera, bool& show_depth_camera, bool& show_app_log, bool& button_pressed) {
	ImGui::Begin("Menu");                          // Create a window called "Hello, world!" and append into it.
	ImGui::Separator();
	ImGui::Text("STREAM");               // Display some text (you can use a format strings too)
	ImGui::Separator();
	ImGui::Checkbox("Preview Color Camera", &show_color_camera);      // Edit bools storing our window open/close state
	ImGui::Checkbox("Preview Depth Camera", &show_depth_camera);
	ImGui::Checkbox("Show Application Log", &show_app_log);

	//ImGui::SliderFloat("Disparity Value", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f    
	//ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

	if (ImGui::Button("Capture")) {                           // Buttons return true when clicked (most widgets return true when edited/activated)
		button_pressed = true;
	}

	//ImGui::Text("counter = %d", counter);
	ImGui::Separator();
	ImGui::Text("SAVE");
	ImGui::Separator();
	ImGui::Text("MSC' FUNCTIONS");
	ImGui::Separator();

	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	ImGui::End();
	ImGui::Render();
}

void menuGuiTest() {
	ImGui::Begin("Menu");
	ImGui::Separator();
	ImGui::Text("STREAM");               // Display some text (you can use a format strings too)
	ImGui::Separator();
	ImGui::End();
	ImGui::Render();
}
