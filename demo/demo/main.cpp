#include "demoList.h"
#include "BinaryTree.h"

typedef List<int> Data;

int main()
{
	Data a;

	a.pushFront(1);

		if (a.listLength != 1)
	{
		std::cout << "Fail!, value not added.";
	}

	a.pushBack(2);
	if (a.listLength != 2)
	{
		std::cout << "Fail!, second value not added.";
	}
	


	a.pushFront(4);
	
	a.insertBefore(2, 54);

	
	
	Data::interator pos;

	for (pos = a.begin(); pos != a.end(); pos++)
	{
		std::cout << *pos << std::endl;
	}
	
	a.deleteList();
	

	for (pos = a.begin(); pos != a.end(); pos++)
	{
		std::cout << *pos << std::endl;
	}

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