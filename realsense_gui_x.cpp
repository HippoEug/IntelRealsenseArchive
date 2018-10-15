#include <iostream>
#include <stdio.h>

#include <librealsense2\rs.hpp>

#include <GLFW\glfw3.h>
#include "imgui\imgui.h"
#include "imgui\imgui_impl_glfw.h"
#include "imgui\imgui_impl_opengl2.h"

#include "realsense_gui_x.hpp"

void initGlfwRS() {
	if (!glfwInit()) {
		std::cout << "GLFW INIT FAILED" << std::endl;
		glfwSetErrorCallback(glfw_error_callback);
		return;
	}

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	(void)io;

	ImGui_ImplOpenGL2_Init();
	ImGui::StyleColorsDark();

	GLFWwindow* window = glfwCreateWindow(1280, 720, "IntelRealsenseX", NULL, NULL);
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
	//ImVec4 clear_color = ImVec4(0.0f, 0.0f, 0.0f, 0.0f); // Black background color

	while (1) {
		glfwPollEvents();

		// Start the Dear ImGui frame
		ImGui_ImplOpenGL2_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		ImGui::Begin("Hello");
		ImGui::End();

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

	ImGui_ImplOpenGL2_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwDestroyWindow(window); // DONE
	glfwTerminate(); // DONE
}

void glfw_error_callback(int error, const char* description) {
	fprintf(stderr, "GLFW Error &d: %s\n", error, description);
}
