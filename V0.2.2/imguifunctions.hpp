#pragma once

#include "imgui\imgui.h"

void menuGUIx(bool& show_color_camera, bool& show_depth_camera, bool& button_pressed);

struct AppLog {
	ImGuiTextBuffer Buf;
	ImGuiTextFilter Filter;
	ImVector<int> LineOffsets;
	bool ScrollToBottom;

	void Clear() {
		Buf.clear();
		LineOffsets.clear();
	}

	void AddLog(const char* fmt, ...) IM_FMTARGS(2) {
		int old_size = Buf.size();
		va_list args;
		va_start(args, fmt);
		Buf.appendv(fmt, args); // modified from appendfv : error here porobably
		va_end(args);

		for (int new_size = Buf.size(); old_size < new_size; old_size++) {
			if (Buf[old_size] == '\n') {
				LineOffsets.push_back(old_size);
			}
		}
		//ScrollToBottom = true;
	}

	void Draw(const char* title, bool* p_open = NULL) {
		ImGui::SetNextWindowSize(ImVec2(500, 400), ImGuiSetCond_FirstUseEver);
		if (!ImGui::Begin(title, p_open)) {
			ImGui::End();
			return;
		}
		if (ImGui::Button("Clear")) {
			Clear();
		}
		ImGui::SameLine();
		bool copy = ImGui::Button("Copy");
		ImGui::SameLine();
		Filter.Draw("Filter", -100.0f);
		ImGui::Separator();
		ImGui::BeginChild("scrolling", ImVec2(0, 0), false, ImGuiWindowFlags_HorizontalScrollbar);
		if (copy) {
			ImGui::LogToClipboard();
		}

		if (Filter.IsActive()) {
			const char* buf_begin = Buf.begin();
			const char* line = buf_begin;
			for (int line_no = 0; line != NULL; line_no++) {
				const char* line_end = (line_no < LineOffsets.Size) ? buf_begin + LineOffsets[line_no] : NULL;

				if (Filter.PassFilter(line, line_end)) {
					ImGui::TextUnformatted(line, line_end);
				}

				line = line_end && line_end[1] ? line_end + 1 : NULL;
			}
		}
		else {
			ImGui::TextUnformatted(Buf.begin());
		}

		//if (ScrollToBottom) {
			//ImGui::SetScrollHere(1.0f); // Original SetScrollHereY
		//}
		//ScrollToBottom = false;
		ImGui::EndChild();
		ImGui::End();
	}
};
