#include <iostream>
#include <thread>
#include <stdio.h>

#include "rsfunctions.hpp"
#include "imguifunctions.hpp"

#include <GLFW\glfw3.h>
#include "imgui\imgui.h"
#include "imgui\imgui_impl_glfw.h"
#include "imgui\imgui_impl_opengl2.h"

int main(int argc, char* argv[]) {
	imguiFunctionsInit(); // DONE: glfwInit()
	GLFWwindow* window = glfwCreateWindow(1280, 720, "IntelRealsenseX", NULL, NULL); // DONE
	glfwMakeContextCurrent(window); // DONE
	glfwSwapInterval(1);
	ImGui_ImplGlfw_InitForOpenGL(window, true); // matched with librealsense2 rs-align

	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
	//ImVec4 clear_color = ImVec4(0.0f, 0.0f, 0.0f, 0.0f); // Black background color

	static AppLog log;

	bool show_color_camera = false;
	bool show_depth_camera = false;
	bool show_app_log = true; // TODO

	bool button_pressed = false;

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		// Start the Dear ImGui frame
		ImGui_ImplOpenGL2_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		menuGUI(show_color_camera, show_depth_camera, show_app_log, button_pressed);

		if (show_app_log) {
			log.Draw("Log");
		}

		if (button_pressed) {
			log.AddLog("Capture Button Pressed\n");
			button_pressed = false;
		}

		if (show_color_camera) {
			ImGui::Begin("Color Camera Stream");
			//ImGui::Begin("Another Window", &show_color_camera);   // Passing a pointer to our bool variable will have a closing button that will clear the bool when clicked
			ImGui::End();
			
			//int x = 1;
			//preview2D(x);
			//colorStream(&window);
		}

		if (show_depth_camera) {
			//ImGui::Begin("Depth Camera Stream");
			//ImGui::End();
		}

		// Rendering
		ImGui::Render();
		int display_w, display_h;
		glfwGetFramebufferSize(window, &display_w, &display_h);
		glViewport(0, 0, display_w, display_h);
		glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());

		glfwMakeContextCurrent(window);
		glfwSwapBuffers(window);
	}

	// Cleanup
	ImGui_ImplOpenGL2_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwDestroyWindow(window); // DONE
	glfwTerminate(); // DONE
}
