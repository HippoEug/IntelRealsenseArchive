#include <iostream>
#include <stdio.h>
#include <thread>

#include "displayfunctions.hpp" // Classes to create GLFW window
#include "imguifunctions.hpp" // Functions to draw ImGui menus
#include "rsgui.hpp" // Libraries that manages Realsense SDK + Actual Logic of Program (TO REMOVE)

int main(int argc, char* argv[]) {
	rsgui rsgui_o; // Create object from Class rsgui

	std::thread t1(&rsgui::init, rsgui_o); // Multithreading init function from object rsgui_o
	t1.join(); // Suspends current thread until execution on t1 is completed
}
