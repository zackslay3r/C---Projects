#include <iostream>
#include <string>
#include <LinkedList.h>
#include <LinkedListIterator.h>
#include <BinarySearchTree.h>
#include <Stack.h>
#include <MathsLib.h>

bool testLinkedList()
{
    //////////////
    // Linked List
    //////////////
	
    {

		std::cout << "\nChecking Linked List...\n";

        //Create.
        ContLib::LinkedList<int> ll;

        //Push back.
        ll.push_back(6);
        ll.push_back(7);
        ll.push_back(8);
        ll.push_back(9);
        ll.push_back(10);

		//Size check.
        if (ll.size() != 5)
        {
            std::cout << "Size check failed after push back.";
            return false;
        }

		//Count check (alias of size).
		if (ll.count() != 5)
		{
			std::cout << "Count check failed after push back.";
			return false;
		}

		//Index check.
        if (ll[0] != 6 || ll[1] != 7 || ll[2] != 8 || ll[3] != 9 || ll[4] != 10)
        {
            std::cout << "Index check failed after push back.";
            return false;
        }

        //Push front.
        ll.push_front(5);
        ll.push_front(4);
        ll.push_front(3);
        ll.push_front(2);
        ll.push_front(1);

		//Size check.
        if (ll.size() != 10)
        {
            std::cout << "Size check failed after push front.";
            return false;
        }

		//Index check.
        if (ll[0] != 1 || ll[1] != 2 || ll[2] != 3 || ll[3] != 4 || ll[4] != 5)
        {
            std::cout << "Index check failed after push front.";
            return false;
        }

        //Clear list.
        ll.clear();

		//Size check.
        if (ll.size() != 0)
        {
            std::cout << "Size check after clear list failed.";
            return false;
        }

        //Repopulate list for next tests.
        ll.push_back(1);
        ll.push_back(2);
        ll.push_back(3);
        ll.push_back(4);
        ll.push_back(5);

        //Pop front.
        int test1 = ll.pop_front();

        //Popped value check.
        if (test1 != 1)
        {
            std::cout << "Value check after pop_front in list failed.";
            return false;
        }

        //Size check.
        if (ll.size() != 4)
        {
            std::cout << "Size check after pop_front in list failed.";
            return false;
        }

        //Pop back.
        int test2 = ll.pop_back();

        //Popped value check.
        if (test2 != 5)
        {
            std::cout << "Value check after pop_back in list failed.";
            return false;
        }

        //Size check.
        if (ll.size() != 3)
        {
            std::cout << "Size check after pop_back in list failed.";
            return false;
        }

        //Clear list.
        ll.clear();

        //Repopulate list for next tests.
        ll.push_back(6);
        ll.push_back(7);
        ll.push_back(8);
        ll.push_back(9);
        ll.push_back(10);

        //Assignment by index number (changes existing values).
        ll[0] = 1;
        ll[1] = 2;
        ll[2] = 3;
        ll[3] = 4;
        ll[4] = 5;

		//Size check.
        if (ll.size() != 5)
        {
            std::cout << "Size check failed after assignment by index number.";
            return false;
        }

		//Index check.
        if (ll[0] != 1 || ll[1] != 2 || ll[2] != 3 || ll[3] != 4 || ll[4] != 5)
        {
            std::cout << "Index check failed after assignment by index number.";
            return false;
        }

        //Construct from initialiser list.
        ContLib::LinkedList<int> ll1 = { 1, 2, 3, 4, 5 };

        //Size check.
        if (ll1.size() != 5)
        {
            std::cout << "Size check failed after construction by initialiser list.";
            return false;
        }

        //Index check.
        if (ll1[0] != 1 || ll1[1] != 2 || ll1[2] != 3 || ll1[3] != 4 || ll1[4] != 5)
        {
            std::cout << "Index check failed after construction by initialiser list.";
            return false;
        }

        //Constuct from copy.
        ContLib::LinkedList<int> ll2(ll);
        
		//Size check.
        if (ll2.size() != 5)
        {
            std::cout << "Size check of constucted copy failed.";
            return false;
        }

		//Index check.
        if (ll2[0] != 1 || ll2[1] != 2 || ll2[2] != 3 || ll2[3] != 4 || ll2[4] != 5)
        {
            std::cout << "Index check of constucted copy failed.";
            return false;
        }

        //Copy from assignment operator.
        ContLib::LinkedList<int> ll3 = ll2;

		//Size check.
        if (ll3.size() != 5)
        {
            std::cout << "Size check of assignment copy failed.";
            return false;
        }

		//Index check.
        if (ll3[0] != 1 || ll3[1] != 2 || ll3[2] != 3 || ll3[3] != 4 || ll3[4] != 5)
        {
            std::cout << "Index check of assignment copy failed.";
            return false;
        }

        //Remove element by index number.
        ll.remove(3);

		//Size check.
        if (ll.size() != 4)
        {
            std::cout << "Size check after removal of one element using 'remove' failed.";
            return false;
        }

		//Index check.
        if (ll[0] != 1 || ll[1] != 2 || ll[2] != 3 || ll[3] != 5)
        {
            std::cout << "Index check after removal of one element using 'remove' failed.";
            return false;
        }

        //Remove an element by iterator.
        ContLib::LinkedListIterator<int> it = ll.begin();

        ll.erase(it);

        //Size check.
        if (ll.size() != 3)
        {
            std::cout << "Size check after removal of one element using 'erase' failed.";
            return false;
        }

        //Index check.
        if (ll[0] != 2 || ll[1] != 3 || ll[2] != 5 )
        {
            std::cout << "Index check after removal of one element using 'erase' failed.";
            return false;
        }

		it = ll.begin();
		
		it++;

		ll.erase(it);

		//Size check.
		if (ll.size() != 2)
		{
			std::cout << "Size check 1 after removal of second element using 'erase' failed.";
			return false;
		}

		//Index check.
		if (ll[0] != 2 || ll[1] != 5)
		{
			std::cout << "Index check 1 after removal of second element using 'erase' failed.";
			return false;
		}

		it = ll.begin();

		it++;

		ll.erase(it);

		//Size check.
		if (ll.size() != 1)
		{
			std::cout << "Size check 2 after removal of second element using 'erase' failed.";
			return false;
		}

		//Index check.
		if (ll[0] != 2)
		{
			std::cout << "Index check 2 after removal of second element using 'erase' failed.";
			return false;
		}

        //Clear list.
        ll.clear();

        //Repopulate list for next tests.
        ll.push_back(5);
        ll.push_back(6);
        ll.push_back(7);
        ll.push_back(8);
        ll.push_back(9);

        //Insert before start of list by iterator.
        it = ll.begin();
       
        //Insert.
        ll.insertBefore(it, 4);

        //Size check.
        if (ll.size() != 6)
        {
            std::cout << "Size check after insert Before start of list into list using iterator failed.";
            return false;
        }

        //Set iterator to list start.
        it = ll.begin();

        //Value check.
        if (*it != 4)
        {
            std::cout << "Iterator value check after insertBefore start of list into list using iterator failed.";
            return false;
        }

        //Insert after by iterator.
        it = ll.begin();
        //Step forward 5 elements.
        it += 5;

        //Insert.
        ll.insertAfter(it, 10);

        //Size check.
        if (ll.size() != 7)
        {
            std::cout << "Size check after insertAfter end of list into list using iterator failed.";
            return false;
        }

        //Set iterator to list start.
        it = ll.begin();

        //Step forward 6 elements.
        it += 6;

        //Value check.
        if (*it != 10)
        {
            std::cout << "Iterator value check after insertAfter end of list into list using iterator failed.";
            return false;
        }

        //Clear list.
        ll.clear();

        //Repopulate list for next tests.
        ll.push_back(5);
        ll.push_back(6);
        ll.push_back(8);
        ll.push_back(10);
        ll.push_back(11);

        //Insert before element in middle of list by iterator.
        it = ll.begin();

        it += 2;

        //Insert.
        ll.insertBefore(it, 7);

        //Size check.
        if (ll.size() != 6)
        {
            std::cout << "Size check after insertBefore middle of list into list using iterator failed.";
            return false;
        }

        //Set iterator to list start.
        it = ll.begin();

        it += 2;

        //Value check.
        if (*it != 7)
        {
            std::cout << "Iterator value check after insertBefore middle of list into list using iterator failed.";
            return false;
        }

        //Insert after element in middle of list by iterator.
        it = ll.begin();
        
        //Step forward 3 elements.
        it += 3;

        //Insert.
        ll.insertAfter(it, 9);

        //Size check.
        if (ll.size() != 7)
        {
            std::cout << "Size check after insertAfter middle of list into list using iterator failed.";
            return false;
        }

        //Set iterator to list start.
        it = ll.begin();

        //Step forward 4 elements.
        it += 4;

        //Value check.
        if (*it != 9)
        {
            std::cout << "Iterator value check after insertAfter middle of list into list using iterator failed.";
            return false;
        }

        while (false); //Redundant task to allow this line to be used as a debugging breakpoint.
    }

	//////////////
	// Linked List Iterator
	//////////////

	{

		std::cout << "\nChecking Linked List Iterator...\n";

		//Create list.
		ContLib::LinkedList<int> ll;

		//Populate list.
		ll.push_back(1);
		ll.push_back(2);
		ll.push_back(3);
		ll.push_back(4);
		ll.push_back(5);

		//Loop test with "auto" keyword, which proves the container is compatible 
		//with C++11 standards for iterators.
		//See http://en.cppreference.com/w/cpp/language/range-for
		
		//Reference to contained object, not const safe.
		int check = 1;
		for (auto &var : ll)
		{
			if (var != check)
			{
				std::cout << "Loop and auto keyword check for LinkedListIterator REFERENECE/NON-CONST failed after push back.";
				return false;
			}
			check++;
		}

		//Reference to contained object, const safe.
		check = 1;
		for (auto const &var : ll)
		{
			if (var != check)
			{
				std::cout << "Loop and auto keyword check for LinkedListIterator REFERENECE/CONST-SAFE failed after push back.";
				return false;
			}
			check++;
		}

		//Copy, not a reference to contained object.
		check = 1;
		for (auto var : ll)
		{
			if (var != check)
			{
				std::cout << "Loop and auto keyword check for LinkedListIterator COPY/NON-REFERENCE failed after push back.";
				return false;
			}
			check++;
		}

		//Create iterator pointing to start of list using assignment.
		ContLib::LinkedListIterator<int> lli = ll.begin();

		//Check current iterator value.
		if (*lli != 1)
		{
			std::cout << "Dereference check after create using assignment and set to start for LinkedListIterator failed.";
			return false;
		}

		//Create iterator pointing to start of list using copy constructor.
		ContLib::LinkedListIterator<int> lli2(ll.begin());

		//Check current iterator value.
		if (*lli2 != 1)
		{
			std::cout << "Dereference check after create using copy constrcutor and set to start for LinkedListIterator failed.";
			return false;
		}

		//Create iterator pointing to end of list using assignment.
		ContLib::LinkedListIterator<int> lli3 = ll.end();

		//Check current iterator.
		if (lli3 != ll.end())
		{
			std::cout << "Dereference check after create using assignment and set to end for LinkedListIterator failed.";
			return false;
		}

		//Create iterator pointing to end of list using copy constructor.
		ContLib::LinkedListIterator<int> lli4(ll.end());

		//Check current iterator.
		if (lli4 != ll.end())
		{
			std::cout << "Dereference check after create using copy constrcutor and set to end for LinkedListIterator failed.";
			return false;
		}

		//Increment iterator.
		lli++;
		lli++;
		lli++;

		//Check current iterator value.
		if (*lli != 4)
		{
			std::cout << "Dereference check after iterate forward in LinkedListIterator failed.";
			return false;
		}

		//Decrement iterator.
		lli--;
		lli--;
		 
		//Check current iterator value.
		if (*lli != 2)
		{
			std::cout << "Dereference check after iterate backward in LinkedListIterator failed.";
			return false;
		}

		//Iterator equality.
		ContLib::LinkedListIterator<int> lli5 = ll.begin();
		ContLib::LinkedListIterator<int> lli6 = ll.begin();

		//Check iterator equality and inequality.

		if (lli5 != lli6) //Should be equal. So if not equal here, fail.
		{
			std::cout << "Inequality check for LinkedListIterator failed.";
			return false;
		}

		lli5++;

		if (lli5 == lli6) //Should NOT be equal. So if equal here, fail.
		{
			std::cout << "Equality check for LinkedListIterator failed.";
			return false;
		}

        //Iterator ++ return value check.
        ContLib::LinkedListIterator<int> lli7 = ll.begin();
        ContLib::LinkedListIterator<int> lli8 = ll.begin();

        //Iterator++ should return current iterator value THEN increment it.
        if (lli7++ != lli8)
        {
            std::cout << "Iterator++ check 1 for LinkedListIterator failed.";
            return false;
        }

        lli8++;

        //Iterator++ should have incremented during previous check.
        if (lli7 != lli8)
        {
            std::cout << "Iterator++ check 2 for LinkedListIterator failed.";
            return false;
        }

        lli8++;

        //++Iterator should increment and then return incremented value.
        if (++lli7 != lli8)
        {
            std::cout << "++Iterator check 3 for LinkedListIterator failed.";
            return false;
        }

        //Iterator -- return value check.
        ContLib::LinkedListIterator<int> lli9 = ll.begin();
        ContLib::LinkedListIterator<int> lli10 = ll.begin();

        lli9 += 4;
        lli10 += 4;

        //Iterator-- should return current iterator value THEN decrement it.
        if (lli9-- != lli10)
        {
            std::cout << "Iterator-- check 1 for LinkedListIterator failed.";
            return false;
        }

        lli10--;

        //Iterator-- should have decremented during previous check.
        if (lli9 != lli10)
        {
            std::cout << "Iterator-- check 2 for LinkedListIterator failed.";
            return false;
        }

        lli10--;

        //--Iterator should decrement and then return decremented value.
        if (--lli9 != lli10)
        {
            std::cout << "--Iterator check 3 for LinkedListIterator failed.";
            return false;
        }

	}

    return true;
}

bool testBinarySearchTree()
{
    //////////////
    // Binary Search Tree
    //////////////

    {

        std::cout << "\nChecking Binary Search Tree...\n";

        ContLib::BinarySearchTree<std::string, int> bst;
        bst.insert("Hello", 25);
        bst.insert("Goodbye", 46); ////
        bst.insert("Goodbye", 56); // Note that duplicates OVERWRITE existing value.
        bst.insert("Goodbye", 66); ////
        bst.insert("Potato", 97);
        bst.insert("Spanner", 88);
        
        //Check standard node value.

        int test = bst["Potato"];

        if (test != 97)
        {
            std::cout << "Value check 1 for Binary Search Tree failed.";
            return false;
        }

        //Check overwritten duplicate value.

        test = bst["Goodbye"];

        if (test != 66)
        {
            std::cout << "Value check 2 for Binary Search Tree failed.";
            return false;
        }

		//Count instances of key.

		int count = bst.count("Potato"); //There should only be one.

		if (count != 1)
		{
			std::cout << "Count check 1 for Binary Search Tree failed.";
			return false;
		}

		count = bst.count("Nonexistant"); //there should be none.

		if (count != 0)
		{
			std::cout << "Count check 2 for Binary Search Tree failed.";
			return false;
		}

        //Clear the tree.

        bst.clear();

        count = bst.count("Potato"); //There should be no such key.

        if (count != 0)
        {
            std::cout << "Count check 3 for Binary Search Tree failed.";
            return false;
        }

    }

    return true;
}

bool testStack()
{
    //////////////
    // Stack
    //////////////

    {

        std::cout << "\nChecking Stack...\n";

        //Create stack of 5 elements.
        ContLib::Stack<int> s = ContLib::Stack<int>(5);
        
        //Add 5 elements.
        s.push(1);
        s.push(2);
        s.push(3);
        s.push(4);
        s.push(5);

        //Element count check.
        if (s.count() != 5)
        {
            std::cout << "Count check 1 in Stack failed.";
            return false;
        }

        //Check value of top element.
        if (s.top() != 5)
        {
            std::cout << "Value check 1 in Stack failed.";
            return false;
        }

        //Pop element from top of stack.
        if (s.pop() != 5)
        {
            std::cout << "Pop 1 in Stack failed.";
            return false;
        }
        if (s.pop() != 4)
        {
            std::cout << "Pop 2 in Stack failed.";
            return false;
        }
        if (s.pop() != 3)
        {
            std::cout << "Pop 3 in Stack failed.";
            return false;
        }

        //Element count check 2.
        if (s.count() != 2)
        {
            std::cout << "Count check 2 in Stack failed.";
            return false;
        }

        //Clear stack.
        s.clear();

        //Check if stack is empty.
        if (!s.empty())
        {
            std::cout << "Empty check 1 in Stack failed.";
            return false;
        }

        //Overfill stack (max 5 elements) with 6 elements to check dynamic resizing.
        s.push(1);
        s.push(2);
        s.push(3);
        s.push(4);
        s.push(5);
        s.push(6);

        //Check stack max size has increased. 
        //It was 5, it should now be 6.
        if (s.size() != 6)
        {
            std::cout << "Size check 1 in Stack failed.";
            return false;
        }

		//Create stack using copy constructor.
		ContLib::Stack<int> s2(s);

		//Check value of top element.
		if (s2.top() != 6)
		{
			std::cout << "Value check 2 in Stack failed.";
			return false;
		}
		
		//Check stack max size.
		if (s.size() != 6)
		{
			std::cout << "Size check 2 in Stack failed.";
			return false;
		}

		//Set stack using assignment operator.
		ContLib::Stack<int> s3 = s;

		//Check value of top element.
		if (s3.top() != 6)
		{
			std::cout << "Value check 3 in Stack failed.";
			return false;
		}

		//Check stack max size.
		if (s3.size() != 6)
		{
			std::cout << "Size check 3 in Stack failed.";
			return false;
		}

    }

    return true;
}

bool runTests()
{
	if (!testLinkedList())
	{
		std::cout << "\n\nLinked list test FAILED.\n\n";
		return false;
	}
	else
	{
		std::cout << "\n\nLinked list test passed.\n\n";
	}

	if (!testBinarySearchTree())
	{
		std::cout << "\n\nBinary search tree test FAILED.\n\n";
		return false;
	}
	else
	{
		std::cout << "\n\nBinary search tree test passed.\n\n";
	}

	if (!testStack())
	{
		std::cout << "\n\nStack test FAILED.\n\n";
		return false;
	}
	else
	{
		std::cout << "\n\nStack test passed.\n\n";
	}

	return true;
}

int main()
{

	runTests();

    system("pause");

    return 0;

}