#include <iostream>
#include <stdio.h>
#include <thread>

#include "displayfunctions.hpp"
#include "imguifunctions.hpp"
#include "rsgui.hpp"

int main(int argc, char* argv[]) {
	rsgui rsgui;

	std::thread t1(&rsgui::init, rsgui);
	t1.join();
}
