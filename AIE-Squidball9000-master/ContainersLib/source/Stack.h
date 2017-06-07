#pragma once

namespace ContLib
{
    template <class T>
    class Stack
    {

    public:

        /**
        * Default constructor.
        */
        Stack() 
        {
            topElement = nullptr;
            topIndex = -1;
            elementCount = 0;
            maxSize = 0;
        };
        
        /**
        * Constructor with size parameter.
        * @params newSize The size of the new stack, in max number of allowed elements.
        */
        Stack(int newSize) 
        {
            topElement = nullptr;
            topIndex = -1;
            elementCount = 0;
            maxSize = newSize;
            elements = new T[maxSize];
        };

        /**
        * Copy constructor.
        * @params other The stack to copy from.
        */
        Stack(const Stack &other)
        {
            topElement = nullptr;
            topIndex = -1;
            elementCount = 0;
            maxSize = 0;
            copy(other);
        };

        /**
        * Assignment operator.
        * @params other The stack to copy from.
        */
        Stack &operator=(const Stack &other)
        {
            copy(other);
            return *this;
        }

        /**
        * Copy another stack to this stack.
        * @params other The stack to copy from.
        */
        void copy(const Stack &other)
        {
            if (maxSize) delete[] elements;
            maxSize = other.maxSize;
            elements = new T[maxSize];

			for (int i = 0; i < maxSize; i++) elements[i] = other.elements[i];

            topIndex = other.topIndex;
            topElement = &elements[topIndex];
            elementCount = other.elementCount;
        }

        /**
        * Default destructor.
        */
        ~Stack() 
        {
            if (maxSize) delete [] elements;
        };

        /**
        * Get count of number of active elements.
        * @returns The count of number of active elements.
        */
        int count() const
        {
            return elementCount;
        };

        /**
        * Get size of max number of elements this stack can hold.
        * @returns The max number of elements this stack can hold.
        */
        int size() const
        {
            return maxSize;
        };


        /**
        * Add an element to the top of the stack.
        * @params obj The object to add.
        * @returns void.
        */
        void push(const T &obj)
        {
            //Check if stack size isn't big enough to hold more elements.
            if (topIndex == maxSize - 1)
            {
                //Resize stack to accomidate a new element.

                maxSize = maxSize + 1;
               
                T *elementsTmp = new T[maxSize];
				
				for (int i = 0; i < maxSize; i++) elementsTmp[i] = elements[i];
                
				delete[] elements;

                elements = elementsTmp;

            }

            elements[topIndex + 1] = obj;
            elementCount++;
            topElement = &elements[topIndex + 1];
            topIndex++;
        };

        /**
        * Get a reference to the element at the top of the stack.
        * @returns The element at the top of the stack.
        */
        T &top()
        {
            return *topElement;
        };

        /**
        * Remove and return the element at the top of the stack.
        * @returns The element at the top of the stack.
        */
        T pop()
        {
            T tmpElement = *topElement;
            topIndex--;
            elementCount--;
            topElement = &elements[topIndex];
            return tmpElement;
        }

        /**
        * Check if stack is empty.
        * @returns True if empty, false if not.
        */
        bool empty() const
        {
            return elementCount == 0;
        }

        /**
        * Remove all elements from stack.
        * @returns void.
        */
        void clear()
        {
            topIndex = -1;
            elementCount = 0;
            topElement = nullptr;
        }

    private:

        /**
        * Maximum size of this stack.
        */
        int maxSize;

        /**
        * Current number of active elments in this stack.
        */
        int elementCount;

        /**
        * Pointer to top element of the stack.
        */
        T *topElement;

        /**
        * Index of the current top element.
        */
        int topIndex;

        /**
        * Pointer to stack elements on the heap.
        */
        T *elements;

    };

}