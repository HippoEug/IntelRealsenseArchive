#include <iostream>
#include <thread>

#include "rsfunctions.hpp"
#include "opencvfunctions.hpp"

int main(int argc, char* argv[]) {
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
			selectCoordinates();
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
