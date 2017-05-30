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
		ListNode<T> *ptr = head->pNext;
		delete head;
		ptr->pPrev = nullptr;
		head = ptr;
		listLength--;

	}
	
	// This function should remove the last item.
	void popBack()
	{
		ListNode<T> *ptr = tail->pPrev;
		delete tail;
		ptr->pNext = nullptr;
		tail = ptr;
		listLength--;
	}
	// this function should insert a value before the node parameter.
	void insert(int position, T insertedValue)
	{
		if (position == 0)
		{
			pushFront();
		}
		else if (position == listLength)
		{
			pushBack();
		}
		else if (position < 0 || position > listLength)
		{
			throw("Error: tried to enter a value outside of the list.");
		}
		else
		{
			ListNode<T> *holder = head;
			for (int i = 1; i <= position; i++)
			{
				if (i == position)
				{
					ListNode<T> *ptr = new ListNode<T>;
					ptr->pNext = holder->pNext;
					ptr->pPrev = holder;
					holder->pNext->pPrev = ptr;
					holder->pNext = ptr;
					ptr->value = insertedValue;
					listLength++;
				}
				else
				{
					holder = holder->pNext;
				}
			
			}
		
		}
		
	}

	void erase(int position)
	{
		if (position == 0)
		{
			popFront();
		}
		else if (position == listLength)
		{
			popBack();
		}
		else if (position < 0 || position > listLength)
		{
			throw("Error: tried to delete a value outside of the list.");
		}
		else
		{
			ListNode<T> *holder = head;
			for (int i = 1; i <= position; i++)
			{
				if (i == position)
				{
					holder->pNext->pPrev = holder->pPrev;
					holder->pPrev->pNext = holder->pNext;
					delete holder;
					listLength--;
				}
				else
				{
					holder = holder->pNext;
				}

			}

		}

	}
	
	void remove(T value)
	{
		ListNode<T> *ptr = head->next;
		while (ptr != head) {
			Node *next = ptr->next;
			if (ptr->value == value) {
				ptr->prev->next = p->next;
				ptr->next->prev = p->prev;
				delete p;
			}
			p = next;
		}
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
