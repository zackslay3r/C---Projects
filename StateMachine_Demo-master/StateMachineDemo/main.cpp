#include "StateMachineDemoApp.h"

int main() {
	
	auto app = new StateMachineDemoApp();
	app->run("AIE", 1280, 720, false);
	delete app;

	return 0;
}