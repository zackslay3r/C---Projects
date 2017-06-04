#include "demoList.h"

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
	



}