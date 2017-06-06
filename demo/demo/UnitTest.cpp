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
	
	
	
	// Deletes the list.
	a.deleteList();
	
	//makes the iterator the begin of the list
	test = a.begin();

	// if the value in the beginning of the list has a value, fail
	if (test.nodePtr != nullptr)
	{
		std::cout << "Fail! the list was not fully deleted.";
		return false;
	}
	
	// all tests sucessful.
	std::cout << "Linked list tests were sucessful!";


	std::cout << "Moving onto binary tree...";


	// Creates the binary tree. Key and value are both ints.
	BinaryTree<int, int> myBT = BinaryTree<int, int>();
	myBT.AddItem(5, 1);
	myBT.AddItem(2, 7);
	myBT.AddItem(7, 1);
	myBT.AddItem(3, 10);
	myBT.AddItem(6, 4);

	// Test the make sure the input's were correctly filled.
	if (myBT[5] != 1 )
	{
		std::cout << "Fail, the first key does not contain the correct value.";
		return false;
	}

	if (myBT[2] != 7)
	{
		std::cout << "Fail, the second key does not contain the correct value.";
		return false;
	}

	if (myBT[7] != 1)
	{
		std::cout << "Fail, the third key does not contain the correct value.";
		return false;
	}

	if (myBT[3] != 10)
	{
		std::cout << "Fail, the fourth key does not contain the correct value.";
		return false;
	}

	if (myBT[6] != 4)
	{
		std::cout << "Fail, the fifth key does not contain the correct value.";
		return false;
	}

	// Will now test to ensure that you can overwrite a value.
	myBT[2] = 3;

	if (myBT[2] != 3)
	{
		std::cout << "Fail, the value was not correctly changed.";
		return false;
	}

	//Will now test to see to make sure that if a key that is already being used is attempted to be inserted, it overrides instead of creates a new node 
	// with the same key.

	myBT.AddItem(2, 7);

	if (myBT[2] != 7)
	{
		std::cout << "Fail, the value was not overwritten.";
		return false;
	}
	
	myBT.clear();
	std::cout << "Binary tree tests complete." << std::endl;

	return true;


	/*int fred = 6;
	myBT[2] = fred;
	fred = myBT[3];
	myBT.AddItem(4, 5);
	myBT.PrintTree();

	myBT.clear();
*/
}