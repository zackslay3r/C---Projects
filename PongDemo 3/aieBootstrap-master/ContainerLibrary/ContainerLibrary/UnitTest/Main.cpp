#include "../ContainerLibrary/UnitTest.h"
#include "../ContainerLibrary/Stack.h"
#include <iostream>

int main()
{
	if (runUnittest() == false)
	{
		std::cout << "Looks like the unit test has failed!" << std::endl;
	}
	else
	{
		std::cout << "All the tests passed sucessfully!" << std::endl;
	}

	system("pause");
}

