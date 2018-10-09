#include <iostream>
#include <thread>
#include <stdio.h>

#include "rsfunctions.hpp"
//#include "opencvfunctions.hpp"

#include <GLFW\glfw3.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl2.h"

static void glfw_error_callback(int error, const char* description)
{
	fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

int main(int argc, char* argv[]) {
	// Setup window
	if (!glfwInit()) {
		return 1;
	}
	glfwSetErrorCallback(glfw_error_callback);
	GLFWwindow* window = glfwCreateWindow(1280, 720, "Realsense", NULL, NULL);

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;

	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL2_Init();
	ImGui::StyleColorsDark();

	bool show_demo_window = true;
	bool show_another_window = false;
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

	while (!glfwWindowShouldClose(window))
	{
		// Poll and handle events (inputs, window resize, etc.)
		// You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
		// - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application.
		// - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application.
		// Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
		glfwPollEvents();

		// Start the Dear ImGui frame
		ImGui_ImplOpenGL2_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		// 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
		if (show_demo_window)
			ImGui::ShowDemoWindow(&show_demo_window);

		// 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
		{
			static float f = 0.0f;
			static int counter = 0;

			ImGui::Begin("Menu");                          // Create a window called "Hello, world!" and append into it.

			ImGui::Text("Select Functions");               // Display some text (you can use a format strings too)
			ImGui::Checkbox("Preview Color Camera", &show_demo_window);      // Edit bools storing our window open/close state
			ImGui::Checkbox("Preview Depth Camera", &show_another_window);

			ImGui::SliderFloat("Disparity Value", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f    
			ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

			if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
				counter++;
			ImGui::SameLine();
			ImGui::Text("counter = %d", counter);

			ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
			ImGui::End();
		}

		// 3. Show another simple window.
		if (show_another_window)
		{
			ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
			ImGui::Text("Hello from another window!");
			if (ImGui::Button("Close Me"))
				show_another_window = false;
			ImGui::End();
		}

		// Rendering
		ImGui::Render();
		int display_w, display_h;
		glfwGetFramebufferSize(window, &display_w, &display_h);
		glViewport(0, 0, display_w, display_h);
		glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
		glClear(GL_COLOR_BUFFER_BIT);
		//glUseProgram(0); // You may want this if using this code in an OpenGL 3+ context where shaders may be bound, but prefer using the GL3+ code.
		ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());

		glfwMakeContextCurrent(window);
		glfwSwapBuffers(window);
	}

	// Cleanup
	ImGui_ImplOpenGL2_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwDestroyWindow(window);
	glfwTerminate();

	//return 0;

	int choice = getChoice();

	while(1) {
		switch (choice) {
		case 1: { // Preview Depth & RGB Camera
			std::thread t1(preview2D, std::ref(choice)); // Start function preview 2D
			std::thread t2(terminateChoice, std::ref(choice)); // Start function terminateChoice, passing parameter choice by reference
			t1.join(); // Main thread will wait for T1 to finish
			t2.join(); // Main thread will wait for T2 to finish

			choice = getChoice();
			break;
		}
		case 2: { // Preview 3D PointCloud
			std::thread t1(preview3D, std::ref(choice)); // Start function preview 3D
			std::thread t2(terminateChoice, std::ref(choice)); // Start function terminateChoice, passing parameter choice by reference
			t1.join(); // Main thread will wait for T1 to finish
			t2.join(); // Main thread will wait for T2 to finish

			choice = getChoice();
			break;
		}
		case 3: { // Save 2D Color & Depth Preview PNG
			std::cout << "Saving 2D Color & Depth Preview PNGs" << std::endl;
			save2DPreview();

			choice = getChoice();
			break;
		}
		case 4: { // Save Preview Metadata
			std::cout << "Saving Preview Metadata" << std::endl;
			saveMetaData();

			choice = getChoice();
			break;
		}
		case 5: { // Save Relevant Data
			std::cout << "Saving Relevant Data" << std::endl;
			saveRData();

			choice = getChoice();
			break;
		}
		case 6: { // Get Distance
			std::cout << "Displaying Distance" << std::endl;
			getDistance();

			choice = getChoice();
			break;
		}
		case 7: { // Select Coordinates
			std::cout << "Opening Coordinates Select Menu" << std::endl;
			//selectCoordinates();
		}
		default: {
			std::cout << "\nINVALID OPTION" << std::endl;
			std::chrono::milliseconds(10000); // Not Effective
			
			choice = getChoice();
			break;
		}
		}
	}
}
