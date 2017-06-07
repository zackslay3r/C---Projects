#pragma once
#include <initializer_list>

/**
* A template class doubly linked list container.
* https://en.wikipedia.org/wiki/Linked_list
* Depends on LinkedListIterator class.
* @author Ashley Flynn - AIE - 2017.
*/
namespace ContLib
{
	template <class T>
	class LinkedListIterator;

	template <class T>
	class LinkedList
	{

	public:

		friend LinkedListIterator<T>;

		/**
		* Default constructor.
		*/
		LinkedList();

		/**
		* Constructor with add element.
		*/
		LinkedList(T newObj);

		/**
		* Copy constructor.
		*/
		LinkedList(const LinkedList<T> &other);

        /**
        * Direct list initialisation.
        * Eg: LinkedList<int> fred; fred = { 1, 2, 3 };
        */
        LinkedList(const std::initializer_list<T> &l);

		/**
		* Default destructor.
		*/
		~LinkedList();

		/**
		* Assignment operator.
		*/
		LinkedList<T> &operator=(const LinkedList<T> &other);

		/**
		* [] operator to retrieve reference to elements by index number.
		* @params n The index number to retrieve.
		* @returns A reference to the object at the requested index.
		*/
		T &operator[](int n);
        
        /**
		* [] operator CONST SAFE to retrieve reference to elements by index number.
		* @params n The index number to retrieve.
		* @returns A reference to the object at the requested index.
		*/
        T &operator[](int n) const;

		/**
		* Add an object to the start of the linked list.
		* @params newObj The object to add.
		* @returns void.
		*/
		void push_front(T newObj);

		/**
		* Add an object to the end of the linked list.
		* @params newObj The object to add.
		* @returns void.
		*/
		void push_back(T newObj);

        /**
        * Remove an object to the start of the linked list and return its value.
        * @returns The stored object that was just removed.
        */
        T pop_front();

        /**
        * Remove an object to the end of the linked list and return its value.
        * @returns The stored object that was just removed.
        */
        T pop_back();

		/**
		* Remove an object using an index number.
		* @params n The index number.
		* @returns void.
		*/
		void remove(int n);

        /**
        * Remove an object using an iterator.
        * @params it The iterator pointing to the object to remove.
        * @returns void.
        */
        void erase(LinkedListIterator<T> &it);

		/**
		* Clear all objects from the list.
		* @returns void.
		*/
		void clear();

        /**
        * Insert an element before the current iterator location.
        * @params it The iterator pointing to the element to insert before.
        * @params newObj The object to add.
        */
        void insertBefore(LinkedListIterator<T> &it, T newObj);

        /**
        * Insert an element after the current iterator location.
        * @params it The iterator pointing to the element to insert after.
        * @params newObj The object to add.
        */
        void insertAfter(LinkedListIterator<T> &it, T newObj);

		/**
		* Get the list size.
		* @returns An integer of the number of elements in the list.
		*/
		int size() const;

		/**
		* Get the list size.
		* Alias for size().
		* @returns An integer of the number of elements in the list.
		*/
		inline int count() const { return size(); };

		/**
		* Check if the list is empty.
		* @returns Bool true if empty, false if not.
		*/
		bool empty() const;

		/**
		* Get the first element value as a reference.
		* @returns A reference to the first element value.
		*/
		T &first();

		/**
		* Get the last element value as a reference.
		* @returns A reference to the last element value.
		*/
		T &last();

		/**
		* Get an iterator set to the start of the list.
		* This is required for compatibility with C++11 features such as the "auto" keyword
		* for use in loops. http://en.cppreference.com/w/cpp/language/range-for
		* @returns An iterator set to the start of the list.
		*/
		LinkedListIterator<T> begin();

        /**
        * Get a CONST SAFE iterator set to the start of the list.
        * This is required for compatibility with C++11 features such as the "auto" keyword
        * for use in loops. http://en.cppreference.com/w/cpp/language/range-for
        * @returns An iterator set to the start of the list.
        */
        LinkedListIterator<T> begin() const;

		/**
		* Get an iterator set to the end of the list, which is the element PAST 
		* the last element in the list, as a sentinel node.
		* https://en.wikipedia.org/wiki/Linked_list#Sentinel_nodes
		* This is required for compatibility with C++11 features such as the "auto" keyword
		* for use in loops. http://en.cppreference.com/w/cpp/language/range-for
		* @returns An iterator set to the end of the list, a sentinel node after the last element.
		*/
		LinkedListIterator<T> end();

        /**
        * Get a CONST SAFE iterator set to the end of the list, which is the element PAST
        * the last element in the list, as a sentinel node.
        * https://en.wikipedia.org/wiki/Linked_list#Sentinel_nodes
        * This is required for compatibility with C++11 features such as the "auto" keyword
        * for use in loops. http://en.cppreference.com/w/cpp/language/range-for
        * @returns An iterator set to the end of the list, a sentinel node after the last element.
        */
        LinkedListIterator<T> end() const;

	private:

		/**
		* An element of a linked list.
		*/
		template <class T>
		class LinkedListElement
		{

		public:

			/**
			* Default constructor.
			*/
			LinkedListElement() { prev = next = nullptr; }

			/**
			* The previous element in the chain.
			*/
			LinkedListElement *prev;

			/**
			* The next element in the chain.
			*/
			LinkedListElement *next;

			/**
			* The object we are storing.
			*/
			T obj;

		};

		/**
		* The current element pointed to.
		*/
		LinkedListElement<T> *pFirst;

		/**
		* The current element pointed to.
		*/
		LinkedListElement<T> *pLast;

		/**
		* The current size of the list.
		*/
		int currentSize;

		/**
		* Delete all elements.
		* @returns void.
		*/
		void deleteAll();

		/**
		* Copy another list to this list.
		* @params other The other list to copy from.
		* @returns void.
		*/
		void copy(const LinkedList<T> &other);
	};

	////////////////////////////////////////
	// LinkedList Definitions
	////////////////////////////////////////

	template<class T>
	inline LinkedList<T>::LinkedList()
	{
		currentSize = 0;

		//Reset all values to default.
		deleteAll();
	}

	template<class T>
	inline LinkedList<T>::LinkedList(T newObj)
	{
		currentSize = 0;

		//Reset all values to default.
		deleteAll();

		push_back(newObj);
	}

	template<class T>
	inline LinkedList<T>::LinkedList(const LinkedList<T> &other)
	{
		currentSize = 0;

		//Reset all values to default.
		deleteAll();

		copy(other);
	}

    template<class T>
    inline LinkedList<T>::LinkedList(const std::initializer_list<T> &l)
    {
        currentSize = 0;

        //Reset all values to default.
        deleteAll();

        for (auto var : l)
        {
            push_back(var);
        }
    }

	template<class T>
	inline void LinkedList<T>::copy(const LinkedList<T> &other)
	{
		LinkedListElement<T> *tmpElement;
		tmpElement = other.pFirst;
		int tmpSize = other.size();
		for (int i = 0; i < tmpSize; i++)
		{
			push_back(tmpElement->obj);
			tmpElement = tmpElement->next;
		}
	}

	template<class T>
	LinkedList<T>::~LinkedList()
	{
		//Delete all elements from the heap.
		deleteAll();
	}

	template<class T>
	inline LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &other)
	{
		currentSize = 0;

		//Reset all values to default.
		deleteAll();

		copy(other);

		return *this;
	}

	template<class T>
	inline T & LinkedList<T>::operator[](int n)
	{
		//If the list is empty, throw.
		if (currentSize == 0) throw;

		//Sanity check n.
		if (n < 0 || n > currentSize - 1) throw;

		//Temp pointer.
		LinkedListElement<T> *currTmp;

		//Step from nearest end to the element.
		if (n <= currentSize / 2)
		{
			//Temp pointer to start.
			currTmp = pFirst;

			//Step forward through elements to target.
			for (int i = 0; i < n; i++) currTmp = currTmp->next;
		}
		else
		{
			//Temp pointer to end.
			currTmp = pLast;

			//Step backward through elements to target.
			for (int i = 0; i < (currentSize - 1) - n; i++) currTmp = currTmp->prev;
		}

		return currTmp->obj;
	}

    template<class T>
    inline T & LinkedList<T>::operator[](int n) const
    {
        //If the list is empty, throw.
        if (currentSize == 0) throw;

        //Sanity check n.
        if (n < 0 || n > currentSize - 1) throw;

        //Temp pointer.
        LinkedListElement<T> *currTmp;

        //Step from nearest end to the element.
        if (n <= currentSize / 2)
        {
            //Temp pointer to start.
            currTmp = pFirst;

            //Step forward through elements to target.
            for (int i = 0; i < n; i++) currTmp = currTmp->next;
        }
        else
        {
            //Temp pointer to end.
            currTmp = pLast;

            //Step backward through elements to target.
            for (int i = 0; i < (currentSize - 1) - n; i++) currTmp = currTmp->prev;
        }

        return currTmp->obj;
    }

	template<class T>
	inline void LinkedList<T>::push_front(T newObj)
	{
		if (!pFirst)
		{
			//If there are no elements.
			pFirst = new LinkedListElement<T>();
			pLast = pFirst;
			pFirst->obj = newObj;
		}
		else
		{
			//If there are already elements.
			LinkedListElement<T> *tmp = new LinkedListElement<T>();
			pFirst->prev = tmp;
			tmp->next = pFirst;
			pFirst = tmp;
			pFirst->obj = newObj;
		}

		currentSize++;
	}

	template<class T>
	inline void LinkedList<T>::push_back(T newObj)
	{
		if (!pFirst)
		{
			//If there are no elements.
			pFirst = new LinkedListElement<T>();
			pLast = pFirst;
			pFirst->obj = newObj;
		}
		else
		{
			//If there are already elements.
			LinkedListElement<T> *tmp = new LinkedListElement<T>();
			pLast->next = tmp;
			tmp->prev = pLast;
			pLast = tmp;
			pLast->obj = newObj;
		}

		currentSize++;
	}

    template<class T>
    inline T LinkedList<T>::pop_front()
    {
        //If there are no elements, throw error.
        if (!pFirst) throw;
        
        T obj = pFirst->obj;

        pFirst->next->prev = nullptr;

        LinkedListElement<T> *tmp = pFirst->next;

        delete pFirst;

        currentSize--;

        pFirst = tmp;

        return obj;
    }

    template<class T>
    inline T LinkedList<T>::pop_back()
    {
        //If there are no elements, throw error.
        if (!pLast) throw;

        T obj = pLast->obj;

        pLast->prev->next = nullptr;

        LinkedListElement<T> *tmp = pLast->prev;

        delete pLast;

        currentSize--;

        pLast = tmp;

        return obj;
    }

	template<class T>
	inline void LinkedList<T>::remove(int n)
	{
		//If the list is empty, throw.
		if (currentSize == 0) throw;

		//Sanity check n.
		if (n < 0 || n > currentSize - 1) throw;

		//Temp pointer to start.
		LinkedListElement<T> *currTmp = pFirst;

		//Step forward through elements n times.
		for (int i = 0; i < n; i++) currTmp = currTmp->next;

		if (currTmp->prev && currTmp->next)
		{
			//Element being removed is not the start or end element and there are other elements.
			currTmp->prev->next = currTmp->next;
			currTmp->next->prev = currTmp->prev;
		}
		else if (currTmp->prev && !currTmp->next)
		{
			//Element being removed is the end element and there are other elements.
			currTmp->prev->next = nullptr;
			pLast = currTmp->prev;
		}
		else if (!currTmp->prev && currTmp->next)
		{
			//Element being removed is the start element and there are other elements.
			currTmp->next->prev = nullptr;
			pFirst = currTmp->next;
		}
		else if (!currTmp->prev && !currTmp->next)
		{
			//Element being removed is the start element and the end element as there are no other elements.
			pFirst = nullptr;
			pLast = nullptr;
		}

		currentSize--;

		//Set currTmp prev and next to nullptr so we can identify if it was the element
		//pointed to by current.
		currTmp->prev = nullptr;
		currTmp->next = nullptr;

		delete currTmp;

	}

	template<class T>
	inline void LinkedList<T>::deleteAll()
	{
		//Temp pointer to start.
		LinkedListElement<T> *currTmp = pFirst;

		int tmpSize = currentSize;
		for (int i = 0; i < tmpSize; i++)
		{
			LinkedListElement<T> *nextTmp = currTmp->next;
			delete currTmp;
			currTmp = nextTmp;
		}

		currentSize = 0;
		pFirst = nullptr;
		pLast = nullptr;
	}

    template<class T>
    inline void LinkedList<T>::erase(LinkedListIterator<T> &it)
    {
        //If the list is empty, throw.
        if (currentSize == 0) throw;

        //Sanity check iterator.
        if (it.element == nullptr) throw;
        
        if (it.element->prev && it.element->next)
        {
            //Element being removed is not the start or end element and there are other elements.
            it.element->prev->next = it.element->next;
            it.element->next->prev = it.element->prev;
        }
        else if (it.element->prev && !it.element->next)
        {
            //Element being removed is the end element and there are other elements.
            it.element->prev->next = nullptr;
            pLast = it.element->prev;
        }
        else if (!it.element->prev &&  it.element->next)
        {
            //Element being removed is the start element and there are other elements.
            it.element->next->prev = nullptr;
            pFirst = it.element->next;
        }
        else if (!it.element->prev && !it.element->next)
        {
            //Element being removed is the start element and the end element as there are no other elements.
            pFirst = nullptr;
            pLast = nullptr;
        }

        currentSize--;

		//HACK
		//BUG here? Game eventually crashes unless I comment out the following delete.
        delete it.element;

        it.element = nullptr;
    }

    template<class T>
	inline void LinkedList<T>::clear()
	{
		deleteAll();
	}

    template<class T>
    inline void LinkedList<T>::insertBefore(LinkedListIterator<T>& it, T newObj)
    {
        //If the iterator points nowhere, throw.
        if (it.element == nullptr) throw;

        //If the list is empty, throw.
        if (currentSize == 0) throw;

        //Create the new element.
        LinkedListElement<T> *tmp = new LinkedListElement<T>();
        tmp->obj = newObj;

        if (it.element->prev)
        {
            //There is an element before the target element.
            it.element->prev->next = tmp;
            tmp->prev = it.element->prev;
            tmp->next = it.element;
            it.element->prev = tmp;
        }
        else 
        {
            //There is no element before the target element.
            tmp->prev = nullptr;
            tmp->next = it.element;
            it.element->prev = tmp;
            pFirst = tmp;
        }

        currentSize++;
    }

    template<class T>
    inline void LinkedList<T>::insertAfter(LinkedListIterator<T>& it, T newObj)
    {
        //If the iterator points nowhere, throw.
        if (it.element == nullptr) throw;

        //If the list is empty, throw.
        if (currentSize == 0) throw;

        //Create the new element.
        LinkedListElement<T> *tmp = new LinkedListElement<T>();
        tmp->obj = newObj;

        if (it.element->next)
        {
            //There is an element after the target element.
            it.element->next->prev = tmp;
            tmp->prev = it.element;
            tmp->next = it.element->next;
            it.element->next = tmp;
        }
        else
        {
            //There is no element after the target element.
            tmp->next = nullptr;
            tmp->prev = it.element;
            it.element->next = tmp;
            pLast = tmp;
        }

        currentSize++;
    }

    template<class T>
	inline int LinkedList<T>::size() const
	{
		return currentSize;
	}

	template<class T>
	inline bool LinkedList<T>::empty() const
	{
		return currentSize == 0;
	}

	template<class T>
	inline T & LinkedList<T>::first()
	{
		return &pFirst;
	}

	template<class T>
	inline T & LinkedList<T>::last()
	{
		return &pLast;
	}

	template<class T>
	inline LinkedListIterator<T> LinkedList<T>::begin()
	{
		LinkedListIterator<T> tmp;
		tmp.element = pFirst;
		return tmp;
	}

    template<class T>
    inline LinkedListIterator<T> LinkedList<T>::begin() const
    {
        LinkedListIterator<T> tmp;
        tmp.element = pFirst;
        return tmp;
    }

    template<class T>
    inline LinkedListIterator<T> LinkedList<T>::end()
    {
        LinkedListIterator<T> tmp;
        tmp.element = nullptr;
        return tmp;
    }

	template<class T>
	inline LinkedListIterator<T> LinkedList<T>::end() const
	{
		LinkedListIterator<T> tmp;
		tmp.element = nullptr;
		return tmp;
	}

}