#pragma once
////////////
// List.h //
////////////
struct Node;
class ListIterator;
class List {
public:
	typedef ListIterator iterator;
	// constructor
	List();
	// destructor
	virtual ~List();
	// copy constructor
	List(const List& x);
	// assignment operator
	List& operator=(const List& x);
	// insert value in front of list
	void push_front(double value);
	// insert value in back of list
	void push_back(double value);
	// delete value from front of list
	void pop_front();
	// delete value from back of list
	void pop_back();

	// return value on front of list
	double front() const;
	// return value on back of list
	double back() const;
	// delete value specified by iterator
	void erase(const iterator& i);
	// delete all nodes with specified value
	void remove(double value);
	// return true if list is empty
	bool empty() const;
	// return reference to first element in list
	iterator begin() const;
	// return reference to one past last element in list
	iterator end() const;
private:
	Node *head; // head of list
};
struct Node {
	Node *prev; // previous node
	Node *next; // next node
	double value; // stored value
};
class ListIterator {
public:
	// default constructor
	ListIterator() {
		i = 0;
	}
	// construct iterator for given pointer (used for begin/end)
	ListIterator(Node *p) {
		i = p;
	}

	// convert iterator to Node*
	operator Node*() const {
		return i;
	}
	// test two iterators for not equal
	bool operator!=(const ListIterator& x) const {
		return i != x.i;
	}
	// preincrement operator
	ListIterator& operator++() {
		i = i->next;
		return *this;
	}
	// return value associated with iterator
	double& operator*() const {
		return i->value;
	}
private:
	Node *i; // current value of iterator
};