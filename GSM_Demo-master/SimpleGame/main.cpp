#include "SimpleGameApp.h"

int main() {
	
	auto app = new SimpleGameApp();
	app->run("AIE", 1280, 720, false);
	delete app;

	return 0;
}