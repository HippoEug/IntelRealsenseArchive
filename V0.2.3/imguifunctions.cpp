#include "imgui\imgui.h"

#include "imguifunctions.hpp"

void menuGUIx(bool& show_color_camera, bool& show_depth_camera, bool& button_pressed) {
	ImGui::Begin("Menu");

	ImGui::Separator();
	ImGui::Text("STREAM");
	ImGui::Separator();
	ImGui::Checkbox("Preview Color Camera", &show_color_camera);
	ImGui::Checkbox("Preview Depth Camera", &show_depth_camera);

	ImGui::Separator();
	ImGui::Text("SAVE");
	ImGui::Separator();
	if (ImGui::Button("Capture")) {
		button_pressed = true;
	}

	ImGui::Separator();
	ImGui::Text("MSC' FUNCTIONS");
	ImGui::Separator();

	ImGui::Text("Frame Rate: %.1f FPS", ImGui::GetIO().Framerate);
	ImGui::Separator();
	ImGui::Text("Copyright 2018, HippoEug. All Rights Reserved");
	ImGui::End();
	ImGui::Render();
}
