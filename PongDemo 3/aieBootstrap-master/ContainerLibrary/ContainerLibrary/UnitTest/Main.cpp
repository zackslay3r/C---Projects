#include "../ContainerLibrary/UnitTest.h"
#include "../ContainerLibrary/Stack.h"
#include <iostream>
#define default_value 5
int main()
{
	if (runUnittest() == false)
	{
		std::cout << "Looks like the unit test has failed!";
	}
	else
	{
		std::cout << "All the tests passed sucessfully!";
	}


}

