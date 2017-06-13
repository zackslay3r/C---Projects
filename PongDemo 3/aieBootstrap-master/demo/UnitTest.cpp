#include "demoList.h"
#include "BinaryTree.h"
#include "UnitTest.h"
#include "Stack.h"

typedef List<int> Data;

bool runUnittest()
{
	// Make a new list.
	Data a;

	// Push the value 1 to the front. This list currently contains 1.
	a.pushFront(1);

		if (a.listLength != 1)
	{
		std::cout << "Fail!, value not added." << std::endl;
		return false;
		
	}

	// Pushes the value 2 to the back. The list currently contain 1 and 2.
	a.pushBack(2);
	if (a.listLength != 2)
	{
		std::cout << "Fail!, second value not added." << std::endl;
		return false;
	}
	

	// Pushes the value 4 to the front, The list currently contains 4,1,2.
	a.pushFront(4);

	// Creates the iterator to test the values within spaces. it defaults to the beginning.
	ListIterator<int> test = a.begin();

	// Tests if the first value is 4.
	if(*test != 4)
	{ 
		std::cout << "Fail!, this value was not pushed forward correctly." << std::endl;
		return false;
	}
	
	// Inserts a value before what is in the third value. expected values should be 4,1,54,2.
	a.insertBefore(3, 54);
	
	test++;
	test++;

	if (*test != 54)
	{
		std::cout << "Fail! the insert before was not done sucessfully." << std::endl;
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
		std::cout << "Fail! the insert after was not done sucessfully." << std::endl;
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
		std::cout << "Fail! the list was not fully deleted." << std::endl;
		return false;
	}
	
	// all tests sucessful.
	std::cout << "Linked list tests were sucessful!" << std::endl;


	std::cout << "Moving onto binary tree..." << std::endl;


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
		std::cout << "Fail, the first key does not contain the correct value." << std::endl;
		return false;
	}

	if (myBT[2] != 7)
	{
		std::cout << "Fail, the second key does not contain the correct value." << std::endl;
		return false;
	}

	if (myBT[7] != 1)
	{
		std::cout << "Fail, the third key does not contain the correct value." << std::endl;
		return false;
	}

	if (myBT[3] != 10)
	{
		std::cout << "Fail, the fourth key does not contain the correct value." << std::endl;
		return false;
	}

	if (myBT[6] != 4)
	{
		std::cout << "Fail, the fifth key does not contain the correct value." << std::endl;
		return false;
	}

	// Will now test to ensure that you can overwrite a value.
	myBT[2] = 3;

	if (myBT[2] != 3)
	{
		std::cout << "Fail, the value was not correctly changed." << std::endl;
		return false;
	}

	//Will now test to see to make sure that if a key that is already being used is attempted to be inserted, it overrides instead of creates a new node 
	// with the same key.

	myBT.AddItem(2, 7);

	if (myBT[2] != 7)
	{
		std::cout << "Fail, the value was not overwritten." << std::endl;
		return false;
	}
	
	myBT.clear();
	std::cout << "Binary tree tests complete." << std::endl;

	std::cout << "Now starting stack testing." << std::endl;

	// Creates the Stack for testing.
	Stack<int> stackTest;

	//Testing push
	stackTest.push(5);
	if (stackTest.myArray[stackTest.top] != 5)
	{
		std::cout << "Fail! stack to the top of the list failed." << std::endl;
		return false;
	}

	stackTest.push(4);
	if (stackTest.myArray[stackTest.top] != 4)
	{
		std::cout << "Fail! 2nd object stack to the top of the list failed." << std::endl;
		return false;
	}
	
	stackTest.push(3);
	if (stackTest.myArray[stackTest.top] != 3)
	{
		std::cout << "Fail! 3rd object stack to the top of the list failed." << std::endl;
		return false;
	}
	
	stackTest.push(2);
	if (stackTest.myArray[stackTest.top] != 2)
	{
		std::cout << "Fail! 4th object stack to the top of the list failed." << std::endl;
		return false;
	}
	
	stackTest.push(1);
	if (stackTest.myArray[stackTest.top] != 1)
	{
		std::cout << "Fail! 4th object stack to the top of the list failed." << std::endl;
		return false;
	}


	// Test's the popping function.

	stackTest.tempTop = stackTest.pop();
	if (stackTest.tempTop != 1)
	{
		std::cout << "Fail! Top of the Stack failed to pop." << std::endl;
		return false;
	}
	//Test's that you are able to push when an object has just been popped.

	stackTest.push(8);
	if (stackTest.myArray[stackTest.top] != 8)
	{
		std::cout << "Fail! object push after pop failed." << std::endl;
		return false;
	}

	// Pop's and test's that the pops are valid.

	stackTest.tempTop = stackTest.pop();
	if (stackTest.tempTop != 8)
	{
		std::cout << "Fail! Top of the Stack failed to pop." << std::endl;
		return false;
	}

	stackTest.tempTop = stackTest.pop();
	if (stackTest.tempTop != 2)
	{
		std::cout << "Fail! second from the top of the Stack failed to pop." << std::endl;
		return false;
	}

	stackTest.tempTop = stackTest.pop();
	if (stackTest.tempTop != 3)
	{
		std::cout << "Fail! third from the top of the Stack failed to pop." << std::endl;
		return false;
	}

	stackTest.tempTop = stackTest.pop();
	if (stackTest.tempTop != 4)
	{
		std::cout << "Fail! fourth from the top of the Stack failed to pop." << std::endl;
		return false;
	}

	stackTest.tempTop = stackTest.pop();
	if (stackTest.tempTop != 5)
	{
		std::cout << "Fail! last from the top of the Stack failed to pop." << std::endl;
		return false;
	}

	std::cout << "Stack test's completed!" << std::endl;

	return true;


	/*int fred = 6;
	myBT[2] = fred;
	fred = myBT[3];
	myBT.AddItem(4, 5);
	myBT.PrintTree();

	myBT.clear();
*/
}