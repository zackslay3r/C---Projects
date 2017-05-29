#include "List.h"
//////////////
// list.cpp //
//////////////
//
// helper functions
//
// delete list
static void deleteList(Node *head) {
	Node *p = head->next;
	while (p != head) {
		Node *next = p->next;
		delete p;
		p = next;
	}
	delete head;
}
// copy list
static void copyList(const Node *from, Node *&to) {
	// create dummy header
	to = new Node;
	to->next = to->prev = to;
	// copy nodes
	for (Node *p = from->next; p != from; p = p->next) {
		Node *t = new Node;
		t->value = p->value;

		// insert at end of list
		t->next = to;
		t->prev = to->prev;
		t->prev->next = t;
		t->next->prev = t;
	}
}
//
// member functions
//
// constructor
List::List() {
	head = new Node;
	head->next = head->prev = head;
}
// destructor
List::~List() {
	deleteList(head);
}
// copy constructor
List::List(const List& x) {
	copyList(x.head, head);
}
// assignment operator
List& List::operator=(const List& x) {
	if (this == &x) return *this;
	deleteList(head);
	copyList(x.head, head);
	return *this;
}
// insert value in front of list
void List::push_front(double value) {
	Node *p = new Node;
	p->value = value;
	p->next = head->next;
	p->prev = head;
	p->next->prev = p;
	p->prev->next = p;
}
// insert value in back of list
void List::push_back(double value) {
	Node *p = new Node;
	p->value = value;
	p->next = head;
	p->prev = head->prev;
	p->next->prev = p;
	p->prev->next = p;
}
// delete value from front of list
void List::pop_front() {
	Node *p = head->next;
	p->prev->next = p->next;
	p->next->prev = p->prev;
	delete p;
}
// delete value from back of list
void List::pop_back() {
	Node *p = head->prev;
	p->prev->next = p->next;
	p->next->prev = p->prev;
	delete p;
}
// return value on front of list
double List::front() const {
	return head->next->value;
}
// return value on back of list
double List::back() const {
	return head->prev->value;
}
// delete value specified by iterator
void List::erase(const iterator& i) {
	Node *p = i;
	p->prev->next = p->next;
	p->next->prev = p->prev;
	delete p;
}
// delete all nodes with specified value
void List::remove(double value) {
	Node *p = head->next;
	while (p != head) {
		Node *next = p->next;
		if (p->value == value) {
			p->prev->next = p->next;
			p->next->prev = p->prev;
			delete p;
		}
		p = next;
	}
}
// return true if list is empty
bool List::empty() const {
	return head->next == head;
}
// return reference to first element in list
List::iterator List::begin() const {
	return head->next;
}
// return reference to one past last element in list
List::iterator List::end() const {
	return head;
}