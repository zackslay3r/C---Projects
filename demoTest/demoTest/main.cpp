#include <iostream>
#include "List.h" // std: #include <list>
using namespace std;
typedef List Data; // std: typedef list<double> Data;
int main() {
	Data x;
	// back stuff
	//x.push_back(5);
	//x.push_back(6);
	//cout << x.back() << endl;
	//x.pop_back();
	// front stuff
	x.push_front(4);
	x.push_front(3);
	cout << x.front() << endl;
	x.pop_front();
	// forward iterator
	Data::iterator pos;
	for (pos = x.begin(); pos != x.end(); ++pos)
		cout << *pos << endl;
	// output and delete list
	while (!x.empty()) {
		cout << x.front() << endl;
		x.pop_front();
	}

	x.push_front(5);
	x.push_front(6);
	// remove and erase
	x.remove(5);
	pos = x.begin();
	x.erase(pos);
	x.push_front(5);
	x.push_front(6);
	// copy constructor
	Data y = x;
	// assignment operator
	Data z;
	z = x;
	return 0;
}