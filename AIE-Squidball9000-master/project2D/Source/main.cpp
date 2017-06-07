#include <string>
#include <iostream>
#include <Windows.h>
#include "aieException.h"
#include "aieLog.h"
#include "Application2D.h"
#include <GLFW\glfw3.h>
#include "Settings.h"

/*******************************************************************************
This function returns the full path to the folder that contains the current
executable. Note that there is NO trailing backslash.
********************************************************************************/
std::string getExecutableFolder()
{
	char buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	char *pos;
	if (pos = strrchr(buffer, '\\'))
	{
		*pos = 0;
	}

	return buffer;
}

int main() {

	try
	{
		/**
		* Start AIE Error handling classes and logging classes provided by Jeff Cotter AIE 2017.
		*/

		// Specify an ASCII log file for our application to use. This will be called
		// "log.txt" and will write itself into the executable's folder.
		aie::Log::instance().setLog(getExecutableFolder() + "\\log.txt");

		// Enable logging for all aie exceptions. When enabled, aie exceptions will
		// also record full details into the log.
		aie::Exception::enableLogging(true);

		aieLOG("Application started");

		/**
		* End error handling and logging setup.
		*/

		//Prevent window resizing.
		glfwInit();
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

        //Detect monitor size.
        const GLFWvidmode * mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
        int window_width = mode->width;
        int window_height = mode->height;
        SETT->refreshRate = (float)mode->refreshRate;

		//Allocation.
		auto app = new Application2D();

        if (!SETT->fullscreen)
        {
            //Create a window smaller than the screen;
            window_width -= 50;
            window_height -= 100;
        }

        SETT->screenHeight = window_height;
        SETT->screenWidth = window_width;

		//Initialise in full screen mode.
		app->run("SQUIDBALL 9000 - AIE - Ashley Flynn 2017", window_width, window_height, SETT->fullscreen);

		//Deallocation.
		delete app;

		aieLOG("Application shut down");

	}
	catch (aie::Exception & e)
	{
		//Set console colour back to default.
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x7);
		std::cout << "\n\nException = " << e.reason() << " \\" << e.fileName() << "  " << e.lineNumber() << "\n\n";
	}

	//Exit.
	return 0;
}