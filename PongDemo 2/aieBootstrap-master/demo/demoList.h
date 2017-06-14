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
	
	ListNode<T>() { pNext = nullptr; pPrev = nullptr; }
	ListNode<T>(T val) { value = val; pNext = nullptr; }
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


	ListIterator(const ListIterator<T> &iter) { nodePtr = iter.nodePtr; };

	ListIterator &operator = (const ListIterator<T> &iter) { nodePtr = iter.nodePtr; return *this; };
	
	// converting an iterator to Node*
	operator ListNode<T>*() const { return nodePtr; }

	//testing two iternators to see if they are not equal.
	bool operator !=(const ListIterator& x) const { return nodePtr != x.nodePtr; }


	bool operator ==(const ListIterator& x) const { return nodePtr == x.nodePtr; }

	//preincrement operator
	ListIterator& operator++() { nodePtr = nodePtr->pNext; return *this; }
	

	// decrement operator
	ListIterator& operator--() { nodePtr = nodePtr->pPrev; return *this; }


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

template<typename T> 
class List
{
public:
	//ListNode<T>* firstPos;
	//ListNode<T>* lastPos;
	int listLength;
	typedef ListIterator<T> interator;

	List<T>()
	{
		tail = head = nullptr;
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
	
	// This function should add a value to the end of the list.
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

	// this function should insert a value before the node parameter.
	void insertBefore(int position, T insertedValue)
	{
		if (position == 0)
		{
			pushFront(insertedValue);
		}
		/*else if (position == listLength)
		{
			pushBack(insertedValue);
		}*/
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

	////Deletes the list by first referencing the head
	//void deleteList(ListNode<T>* head_ref)
	//{
	//	// Dereference head_ref to get the real head of the list.
	//	ListNode<T>* current = head_ref;
	//	ListNode<T>* next;

	//	while (current != NULL)
	//	{
	//		next = current->pNext;
	//		delete current;
	//		current = next;
	//	}
	//	// deref head_ref to affect the real head back in the caller.
	//	*head_ref = NULL;

	//}

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

	T& first()
	{
		return head->value;
	}

	T& last()
	{
		return tail->value;
	}
protected:
	ListNode<T> *head;
	ListNode<T> *tail;
};
