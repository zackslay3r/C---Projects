#include <iostream>

template<typename T>
class List;

template<typename T>
class ListIterator;

template<typename T>
class ListNode
{
private:

	// Only a list of the same type will be able use these ListNodes.
	friend List<T>;
	friend ListIterator<T>;
	ListNode<T>* pNext;
	ListNode<T>* pPrev;
	
	ListNode<T>() { pNext = nullptr; pPrev = nullptr; value = NULL; }
	ListNode<T>(T val) { value = val; pNext = NULL; }
	ListNode<T>(T val, ListNode<T>* next) { value(val); pNext(next); }
	ListNode<T>(T first, T last, T valuePassed) { next = first; prev = last; value = valuePassed; }


	

	// Value can now be of whatever type 
	T value;

};

template<typename T>
class ListIterator
{
public:
	// default constructor
	ListIterator() { nodePtr = 0; };
	// constructer that is given a node pointer.
	ListIterator(ListNode<T> *ptr) { nodePtr = ptr; };
	
	// converting an iterator to Node*
	operator ListNode<T>*() const { return nodePtr; }

	//testing two iternators to see if they are not equal.
	bool operator !=(const ListIterator& x) const { return nodePtr != x.nodePtr; }

	//preincrement operator
	ListIterator& operator++() { nodePtr = nodePtr->pNext; return *this; }

	ListIterator& operator++(int) { nodePtr = nodePtr->pNext; return *this; }

	// return value associated with iterator
	T& operator*() const { return nodePtr->value; }


	// Destructor.
	~ListIterator() {};

private:
	ListNode<T>* nodePtr;

};

template<typename T> 
class List
{
public:
	ListNode<T>* firstPos;
	ListNode<T>* lastPos;
	int listLength;
	typedef ListIterator<T> interator;

	List<T>()
	{
		head = new ListNode<T>();
		head->pNext = head->pPrev = head;
		listLength = 0;
	}

	~List<T>()
	{
	}
	
	//This function should add a value to the beginning of the list.
	/*void pushFront(T value)
	{
		if (firstPos == NULL)
		{
			lastPos = firstPos = new ListNode<T>(value);
			listLength++;
		}
		else
		{
			ListNode<T> *temp = new ListNode<T>(value);
			temp->pNext = firstPos;
			firstPos = temp;
			listLength++;
		}
	}*/

	void pushFront(T value)
	{
		
		ListNode<T> *ptr = new ListNode<T>;
		ptr->value = value;
		if (listLength == 0)
		{
			ptr->pNext = nullptr;
			ptr->pPrev = nullptr;
			listLength++;
			head = ptr;
			tail = ptr;
		}
		else
		{
			ptr->pNext = head;
			ptr->pPrev = nullptr;
			head->pPrev = ptr;
			head = ptr;
			listLength++;
		}
	}
	
	// This function should add a value to the end of the list.
	void pushBack(T value)
	{

		ListNode<T> *ptr = new ListNode<T>;
		ptr->value = value;
		if (listLength == 0)
		{
			ptr->pNext = nullptr;
			ptr->pPrev = nullptr;
			listLength++;
			head = ptr;
			tail = ptr;
		}
		else
		{
			ptr->pNext = nullptr;
			ptr->pPrev = tail;
			tail->pNext = ptr;
			tail = ptr;
			listLength++;
		}
	}
	
	
	// This function should remove the first item.
	void popFront()
	{
		ListNode<T> *ptr = head;
		ptr->pPrev->pNext = ptr->pNext;
		ptr->pNext->pPrev = ptr->pPrev;

		delete ptr;
	}
	
	// This function should remove the last item.
	void popBack()
	{
		Node *ptr = head->prev;
		ptr->prev->next = ptr->next;
		ptr->next->prev = ptr->prev;
		delete ptr;
	}
	ListIterator<T> List<T>::begin()
	{
		return ListIterator<T>(head);
	}


	ListIterator<T> List<T>::end()
	{
		return ListIterator<T>();
	}
private:
	ListNode<T> *head;
	ListNode<T> *tail;
};
