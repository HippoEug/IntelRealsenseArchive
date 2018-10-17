#include <iostream>
#include <stdio.h>

#include "displayfunctions.hpp"
#include "imguifunctions.hpp"

class testx {
public:
	window_rs window;

	void create() {
		window.onCreate(1280, 720, "IntelRealsenseXOneS");
		//window_rs window(1280, 720, "esgegx"); // create window
		ImGui_ImplGlfw_Init(window, false);

		texture_rs rgbPreview;
		rs2::pipeline pipe;
		pipe.start();

		while (window) {
			rs2::frameset data = pipe.wait_for_frames();
			rs2::frame color = data.get_color_frame();
			rgbPreview.render(color, { 0, 0, window.width() / 2, window.height() / 2 });
		}
	}
};

int main(int argc, char* argv[]) {
	testx test;
	test.create();
}
