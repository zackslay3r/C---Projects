#include <StateDemoApp.h>
int main() {
	
	auto app = new StateDemoApp();
	app->run("AIE", 1280, 720, false);
	delete app;

	return 0;
}