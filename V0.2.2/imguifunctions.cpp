#include "imgui\imgui.h"

#include "imguifunctions.hpp"

void menuGUIx(bool& show_color_camera, bool& show_depth_camera, bool& button_pressed) {
	ImGui::Begin("Menu");

	ImGui::Separator();
	ImGui::Text("STREAM");
	ImGui::Separator();
	ImGui::Checkbox("Preview Color Camera", &show_color_camera);
	ImGui::Checkbox("Preview Depth Camera", &show_depth_camera);
	if (ImGui::Button("Capture")) {
		// TODO
	}

	ImGui::Separator();
	ImGui::Text("SAVE");
	ImGui::Separator();
	ImGui::Text("MSC' FUNCTIONS");
	ImGui::Separator();

	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	ImGui::End();
	ImGui::Render();
}
