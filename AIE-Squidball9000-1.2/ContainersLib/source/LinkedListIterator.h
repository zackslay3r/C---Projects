#pragma once
#include "LinkedList.h"

/**
* A template class linked list iterator.
* Depends on LinkedList class.
* @author Ashley Flynn - AIE - 2017.
*/
namespace ContLib
{

	template <class T>
	class LinkedListIterator
	{

	public:

		friend LinkedList<T>;

		/**
		* Default constructor.
		*/
		LinkedListIterator();

		/**
		* Copy constructor.
		*/
		LinkedListIterator(const LinkedListIterator<T> &other);

		/**
		* Default destructor.
		*/
		~LinkedListIterator();

		/**
		* Assignment operator.
		*/
		LinkedListIterator<T> &LinkedListIterator<T>::operator=(const LinkedListIterator<T> &other);

		/**
		* Copy one iterator to another.
		*/
		void copy(const LinkedListIterator<T> &other);

		/**
		* Dereference operator * overload.
		* @returns A reference to the object.
		*/
		T &operator *()
		{
			return element->obj;
		}

		/**
		* Dereference operator * overload.
		* Const safe version.
		* @returns A reference to the object.
		*/
		const T *operator *() const
		{
			return &element->obj;
		}

        /**
        * Dereference operator -> overload.
        * @returns A reference to the object.
        */
        T *operator ->()
        {
            return &element->obj;
        }

        /**
        * Dereference operator -> overload.
        * Const safe version.
        * @returns A reference to the object.
        */
        const LinkedListIterator<T> *operator ->() const
        {
            return *this;
        }

		/**
		* ++Iterator operator overload.
		* Increments the iterator forwards in the list.
		* @returns void.
		*/
        inline LinkedListIterator<T> operator++() 
        { 
            if (!element) throw; 
            element = element->next; 
            return *this; 
        };

		/**
		* Iterator++ operator overload.
		* Increments the iterator forwards in the list.
		* @params int Unused. Required syntax for this overload.
		* @returns void.
		*/
		inline LinkedListIterator<T> operator++(int) 
        { 
            if (!element) throw;
            LinkedListIterator<T> tmp = *this;
            element = element->next;
            return tmp;
        };

        /**
        * Iterator += integer overload.
        * Increments the iterator forwards N times in the list.
        * @param n The number of times to increment.
        * @returns void.
        */
        inline void operator+=(int n);

		/**
		* --Iterator operator overload.
		* Decrements the iterator backwards in the list.
		* @returns void.
		*/
		inline LinkedListIterator<T> operator--() {
            if (!element) throw;
            element = element->prev;
            return *this;
        };

		/**
		* Iterator-- operator overload.
		* Decrements the iterator backwards in the list.
		* @params int Unused. Required syntax for this overload.
		* @returns void.
		*/
		inline LinkedListIterator<T> operator--(int) 
        {
            if (!element) throw;
            LinkedListIterator<T> tmp = *this;
            element = element->prev;
            return tmp;
        };

        /**
        * Iterator -= integer overload.
        * Decrements the iterator backwards N times in the list.
        * @param n The number of times to decrement.
        * @returns void.
        */
        inline void operator-=(int n);

		/**
		* Equality operator, to compare if two iterators are equal.
		* @returns True if the iterators point to the same list element. False if not.
		*/
		inline bool operator==(const LinkedListIterator<T> &other) { return element == other.element; };

		/**
		* Inequality operator, to compare if two iterators are not equal.
		* @returns True if the iterators don't point to the same list element. False if they do.
		*/
		inline bool operator!=(const LinkedListIterator<T> &other) { return element != other.element; };

	private:

		/**
		* Pointer to the linked list element.
		*/
		typename LinkedList<T>::LinkedListElement<T> *element;

	};

	////////////////////////////////////////
	// LinkedListIterator Definitions
	////////////////////////////////////////

	template<class T>
	inline LinkedListIterator<T>::LinkedListIterator()
	{
		element = nullptr;
	}

	template<class T>
	inline LinkedListIterator<T>::LinkedListIterator(const LinkedListIterator<T> &other)
	{
		element = nullptr;

		copy(other);
	}

	template<class T>
	inline void LinkedListIterator<T>::copy(const LinkedListIterator<T> &other)
	{
		element = other.element;
	}

    template<class T>
    inline void LinkedListIterator<T>::operator+=(int n)
    {
        for (int i = 0; i < n; i++)
        {
            //Throw if we try to step past end of list.
            if (!element->next) throw;
            element = element->next;
        }
    }

    template<class T>
    inline void LinkedListIterator<T>::operator-=(int n)
    {
        //Throw if we try to step past start of list.
        if (!element->prev) throw;
        for (int i = 0; i < n; i++) element = element->prev;
    }

	template<class T>
	LinkedListIterator<T>::~LinkedListIterator()
	{

	}

	template<class T>
	inline LinkedListIterator<T> &LinkedListIterator<T>::operator=(const LinkedListIterator<T> &other)
	{
		element = nullptr;

		copy(other);
		return *this;
	}
}