#include "stdfunctions.h"

#include <iostream>

int getChoice() {
	int choice;

	system("CLS");

	std::cout << "=============[STREAM]=============" << std::endl;
	std::cout << "1. Preview Depth & RGB Cameras" << std::endl;
	std::cout << "2. Preview 3D PointCloud" << std::endl;
	std::cout << "==============[SAVE]==============" << std::endl;
	std::cout << "3. Save Color & Depth Preview PNG" << std::endl;
	std::cout << "4. Save Preview MetaData" << std::endl;
	std::cout << "5. Capture Relevant Data" << std::endl;
	std::cout << "=========[MSC' FUNCTIONS]=========" << std::endl;
	std::cout << "6. Get Distance" << std::endl;
	std::cout << "7. Select Coordinates of Object" << std::endl;
	std::cout << "\nChoice: ";
	std::cin >> choice;

	return choice;
}

void terminateChoice(int& choice) {
	system("CLS");

	std::cout << "00. Terminate Preview" << std::endl;
	std::cout << "01. TODO: Capture Data" << std::endl;

	std::cout << "\nChoice: ";
	std::cin >> choice;
}
