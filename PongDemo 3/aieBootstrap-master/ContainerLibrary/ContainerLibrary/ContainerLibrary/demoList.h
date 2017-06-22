#include <iostream>
#include "Exeception.h"
template<typename T>
class List;

template<typename T>
class ListIterator;

/*
*class ListNode
* This is a ListNode, it is a object within my linked list. 
* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
* 
*/


template<typename T>
class ListNode
{
private:

	// Only a list of the same type will be able use these ListNodes.
	friend List<T>;
	friend ListIterator<T>;
	ListNode<T>* pNext;
	ListNode<T>* pPrev;

	/* ListNode<T>()
	*
	* This is a default constuctor for ListNode
	*
	*/
	ListNode<T>() { pNext = nullptr; pPrev = nullptr; }




	

	// Value can now be of whatever type 
	T value;

};


/*
*class ListIterator
* This is a ListIterator, it this is a part of my linked list that allows me to iterate though it.
* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
*
*/

template<typename T>
class ListIterator
{
public:
	/* ListIterator()
	*
	* This is a default constuctor for ListIterator
	*
	*/
	ListIterator() { nodePtr = 0; };
	
	
	/* ListIterator(ListNode<T> *ptr)
	*
	* This is a constructor that is given a node pointer.
	*
	*/
	ListIterator(ListNode<T> *ptr) { nodePtr = ptr; };

	/* ListIterator(const ListIterator<T> &iter)
	*
	* This is a constructor that is a previous list iterator and sets the nodePtr to the current one.
	*
	*/
	ListIterator(const ListIterator<T> &iter) { nodePtr = iter.nodePtr; };


	ListIterator &operator = (const ListIterator<T> &iter) { nodePtr = iter.nodePtr; return *this; };
	
	// converting an iterator to Node*
	operator ListNode<T>*() const { return nodePtr; }

	//testing two iternators to see if they are not equal.
	bool operator !=(const ListIterator& x) const { return nodePtr != x.nodePtr; }

	// This tests two nodePtrs to see if they are equal.
	bool operator ==(const ListIterator& x) const { return nodePtr == x.nodePtr; }

	//preincrement operator
	ListIterator& operator++() { nodePtr = nodePtr->pNext; return *this; }
	

	// decrement operator
	ListIterator& operator--() { nodePtr = nodePtr->pPrev; return *this; }

	// This function allows the Iternator to iterate to a certain position.
	// It will return the nodePtr that is at that position.
	ListIterator& operator+=(int position) { 
	
		for (int i = 0; i < position; i++)
		{
			nodePtr = nodePtr->pNext; 
			return *this;
		}
		return *this;
	
	}

	ListIterator& operator++(int) { nodePtr = nodePtr->pNext; return *this; }

	// return value associated with iterator
	T& operator*() const { return nodePtr->value; }

	ListNode<T>* nodePtr;

	// Destructor.
	~ListIterator() {};

private:
	

};


/*
*class List
* This is a List, it this is my doubly linked listed in its entirety, comprised of ListNodes and the iterator.
* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
*
*/
template<typename T> 
class List
{
public:
	
	int listLength;
	typedef ListIterator<T> interator;

	// This is the default constructor for the list.
	List<T>()
	{
		tail = head = nullptr;
		listLength = 0;
	}

	// This is the destructor.
	~List<T>()
	{
	}
	

	
	// This will create a new list node and put a value in it, then it will put it at the front of the list.
	// It takes a value and returns void.
	void pushFront(T value)
	{
		
		ListNode<T> *ptr = new ListNode<T>;
		ptr->value = value;
		if (this->listLength == 0)
		{	
			head = ptr;
			tail = ptr;
		}
		else
		{
			ptr->pNext = head;
			ptr->pPrev = nullptr;
			head->pPrev = ptr;
			head = ptr;
			
		}

		
		listLength++;
	}
	
	// This will create a new list node and put a value in it, then it will put it at the back of the list.
	// It takes a value and returns void.
	void pushBack(T value)
	{

		ListNode<T> *ptr = new ListNode<T>();
		ptr->value = value;
		if (this->listLength == 0)
		{
			
			head = ptr;
			tail = ptr;
		}
		else
		{
			ptr->pNext = nullptr;
			ptr->pPrev = tail;
			tail->pNext = ptr;
			tail = ptr;
			
		}
	
		
		listLength++;
	}
	
	
	// This function should remove the first item and returns void.
	void popFront()
	{
		ListNode<T> *ptr = head->pNext;
		delete head;
		ptr->pPrev = nullptr;
		head = ptr;
		listLength--;

	}
	
	// This function should remove the last item and returns void.
	void popBack()
	{
		ListNode<T> *ptr = tail->pPrev;
		delete tail;
		if (ptr)
		{
			ptr->pNext = nullptr;
			tail = ptr;
		}
		else
		{
			head = tail = nullptr;
		}
		listLength--;
	}

	// this function should insert a value before the node parameter. it takes the position of the list and the value it wants inserted as parameters and returns void.
	void insertBefore(int position, T insertedValue)
	{
		if (position == 0)
		{
			pushFront(insertedValue);
		}

		else if (position < 0 || position > listLength)
		{
			throw("Error: tried to enter a value outside of the list.");
		}
		else
		{
			List<T>::interator holder = begin();
			holder += (position);
			ListNode<T> *ptr = new ListNode<T>;
			ptr->pNext = (holder.nodePtr)->pNext;
			ptr->pPrev = (holder.nodePtr);
			(holder.nodePtr)->pNext->pPrev = ptr;
			(holder.nodePtr)->pNext = ptr;
			ptr->value = insertedValue;
			head = ptr;
			listLength++;
			
			
		
		}
		
	}
	// this function should insert a value after the node parameter. it takes the position of the list and the value it wants inserted as parameters and returns void.
	void insertAfter(int position, T insertedValue)
	{
		if (position == 0)
		{
			pushFront(insertedValue);
		}
		else if (position == listLength)
		{
			pushBack(insertedValue);
		}
		else if (position < 0 || position > listLength)
		{
			throw("Error: tried to enter a value outside of the list.");
		}
		else
		{
			List<T>::interator holder = begin();
			holder += (position);
			ListNode<T> *ptr = new ListNode<T>;
			ptr->pNext = (holder.nodePtr);
			ptr->pPrev = (holder.nodePtr)->pPrev;
			(holder.nodePtr)->pPrev->pNext = ptr;
			//(holder.nodePtr)->pNext = ptr;
			ptr->value = insertedValue;
			tail = ptr;
			listLength++;



		}

	}

	// This will delete a listNode at a certain position and decrease the list. the parameter is the position and it returns void.
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
			List<T>::interator holder = begin();
			holder += (position);
			(holder.nodePtr)->pNext->pPrev = (holder.nodePtr)->pPrev;
			(holder.nodePtr)->pPrev->pNext = (holder.nodePtr)->pNext;
			delete (holder.nodePtr);
			listLength--;

		}

	}
	//This will delete a value within the list dependant on what the value is. the parameter is of type T and it returns void.
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


	// THis will delete the entire list and returns void.
	void deleteList()
	{
		ListNode<T> *pDel = head;

		while (pDel != NULL)
		{
			head = head->pNext;
			delete pDel;

			pDel = head;
		
		}
	
		tail = head = NULL;
		listLength = 0;
	}

	
	ListIterator<T> List<T>::begin()
	{
		return ListIterator<T>(head);
	}


	ListIterator<T> List<T>::end()
	{
		return ListIterator<T>();
	}
	// This returns the value of the first value in the first item of the list.
	T& first()
	{
		return head->value;
	}
	// This returns the value of the last value in the last item of the list.
	T& last()
	{
		return tail->value;
	}
protected:
	ListNode<T> *head;
	ListNode<T> *tail;
};
