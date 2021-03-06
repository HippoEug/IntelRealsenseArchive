#include "imgui\imgui.h"

#include "imguifunctions.hpp"

void menuGUI(bool& show_color_camera, bool& show_depth_camera, bool& camera_button, bool& coordinates_button, bool& CSV_button) {
	static const int flags = ImGuiWindowFlags_NoCollapse
	| ImGuiWindowFlags_NoScrollbar
	| ImGuiWindowFlags_NoSavedSettings
	| ImGuiWindowFlags_NoTitleBar
	| ImGuiWindowFlags_NoResize
	| ImGuiWindowFlags_NoMove;

	ImGui::Begin("Menu", nullptr, flags);

	ImGui::Separator();
	ImGui::Text("-------STREAM-------");
	ImGui::Separator();
	ImGui::Checkbox("Preview Color Camera", &show_color_camera);
	ImGui::Checkbox("Preview Depth Camera", &show_depth_camera);

	ImGui::Separator();
	ImGui::Text("--------SAVE--------");
	ImGui::Separator();
	if (ImGui::Button("Capture Image", { 150, 25 })) {
		camera_button = true;
	}

	ImGui::Separator();
	ImGui::Text("---MSC' FUNCTIONS---");
	ImGui::Separator();
	if (ImGui::Button("Select Coordinates", { 150, 25 })) {
		coordinates_button = true;
	}

	if (ImGui::Button("Save XYZ Coordinates", { 150, 25 })) {
		CSV_button = true;
	}
	//ImGui::Checkbox("ROSBAG", &CSV_button);

	ImGui::Separator();
	ImGui::Text("Frame Rate: %.1f FPS", ImGui::GetIO().Framerate);
	ImGui::Separator();
	ImGui::Text("Copyright 2018, HippoEug. All Rights Reserved");
	ImGui::End();
	ImGui::Render();
}

void rosbagGUI() {
	//ImGui::Begin("Wtf");
	//ImGui::End();
	//ImGui::Render();
}
