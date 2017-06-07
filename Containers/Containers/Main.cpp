#include "UnitTest.h"
#include "Stack.h"
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

	////Stack <int>a;    // Create object of class a with int Template
	////int opt = 1;
	////while (opt != 3)
	////{
	////	
	////	std::cout << " MAX STACK CAPACITY=" << ((default_value - a.top) - 1) << "\n\n\n\n";
	////	std::cout << "1) Push Item\n";
	////	std::cout << "2) Pop Item\n";
	////	std::cout << "3) Exit\n\n";
	////	std::cout << "Option?";
	////	std::cin >> opt;
	////	switch (opt)
	////	{
	////	case 1:
	////		std::cout << "Which Number should be pushed?";
	////		std::cin >> a.object;
	////		a.push(a.object);
	////		break;


	////	case 2:
	////		a.tempTop = a.pop();
	////		std::cout << "Item popped from Stack is:" << a.tempTop << std::endl;
	////		break;
	////	}
	////}
}

