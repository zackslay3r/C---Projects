#include "demoList.h"
#include "BinaryTree.h"
#include "UnitTest.h"

typedef List<int> Data;

bool runUnittest()
{
	// Make a new list.
	Data a;

	// Push the value 1 to the front. This list currently contains 1.
	a.pushFront(1);

		if (a.listLength != 1)
	{
		std::cout << "Fail!, value not added.";
		return false;
		
	}

	// Pushes the value 2 to the back. The list currently contain 1 and 2.
	a.pushBack(2);
	if (a.listLength != 2)
	{
		std::cout << "Fail!, second value not added.";
		return false;
	}
	

	// Pushes the value 4 to the front, The list currently contains 4,1,2.
	a.pushFront(4);

	// Creates the iterator to test the values within spaces. it defaults to the beginning.
	ListIterator<int> test = a.begin();

	// Tests if the first value is 4.
	if(*test != 4)
	{ 
		std::cout << "Fail!, this value was not pushed forward correctly.";
		return false;
	}
	
	// Inserts a value before what is in the third value. expected values should be 4,1,54,2.
	a.insertBefore(3, 54);
	
	test++;
	test++;

	if (*test != 54)
	{
		std::cout << "Fail! the insert before was not done sucessfully.";
		return false;
	}

	
	//this will insert after the first position. the values should be 4,20,1,54,2.
	a.insertAfter(1, 20);
	// resets the testing iterator.
	test = a.begin();
	//increments it for testing.
	test++;

	if (*test != 20)
	{
		std::cout << "Fail! the insert after was not done sucessfully.";
		return false;
	}

	

	
	/*	Data::interator pos;
	for (pos = a.begin(); pos != a.end(); pos++)
	{
		std::cout << *pos << std::endl;
	}*/
	
	
	

	a.deleteList();
	
	test = a.begin();

	if (*test != NULL)
	{
		std::cout << "Fail! the list was not fully deleted.";
		return false;
	}

	std::cout << "Linked list tests were sucessful!";



	int fred = 6;

	BinaryTree<int, int> myBT = BinaryTree<int, int>();
	myBT.AddItem(1, 1);
	myBT.AddItem(2, 7);
	myBT.AddItem(3, 1);
	myBT.AddItem(4, 10);
	myBT.AddItem(5, 4);
	myBT[2] = fred;
	fred = myBT[3];
	myBT.AddItem(4, 5);
	myBT.PrintTree();

	myBT.clear();

}