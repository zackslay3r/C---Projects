#include "UnitTest.h"
#include <iostream>
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