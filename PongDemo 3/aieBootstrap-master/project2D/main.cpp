#include "Application2D.h"

int main() {
	try 
	{
		// allocation
		auto app = new Application2D();

		// initialise and loop
		app->run("AIE", 1280, 720, false);

		// deallocation
		delete app;
		
		return 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Unspecified error." << std::endl;
	}

	system("pause");

	//Exit.
	return EXIT_SUCCESS;
}