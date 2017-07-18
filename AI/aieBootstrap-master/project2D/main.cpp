#include "Application2D.h"
#include "Global.h"
int main() {

	// allocation
	auto app = new Application2D();
	
	// initialise and loop
	app->run("AIE", 1600, 900, false);

	// deallocation
	delete app;

	return 0;
}