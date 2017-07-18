#pragma once
#include<iostream>
#include "Exeception.h"

template <class T>
class Stack {
	
	
	
	
public:
	T object; // this is to store values.
	T tempTop; // this is to store the value of the top of the stack when it is deleted.
	int top; // this is a index of the amount in the stack.
	T* myArray;
	int size;

	/* Stack()
	*
	* This is a default constructor for Stack
	*
	*/
	Stack()
	{
	}
	
	/// This is the constructor. we do not use the default constructor, as we always want this to have a size.
	/* Stack(int n)
	*
	* This is a constructor for List that will take a size parameter.
	*
	*
	* parameter 1 n - the amount of items you want in the stack.
	*
	*/
	Stack(int n)
	{
		size = n;
		eASSERT(n > 0);
		// this creates an empty stack with the amount of spaces previously defined by 'default_value'
		myArray = new T[n];
		// this defaults the index to be -1 to signifiy the stack is empty of values.
		top = -1;

	}

	/* ~Stack()
	*
	* This is a default destructor for Stack
	*
	*/
	~Stack()
	{
	}


	/* void push(T object)
	*
	*This pushes a value to the top of the stack and will increment the index.
	*
	*
	* @parameter 1  object - a value you want to push into the stack.
	*
	*
	* @returns void
	*/
	void push(T object)
	{
		top++;
		if (top < size)
		{
			myArray[top] = object;
		}
		// if the stack is full, dont allow the user to add to the stack 
		else
		{
			eTHROW("You tried to push the stack above its set size.");	
		}
	}

	
	/* T pop()
	*
	* This pops a value from the top of the stack and decrement the stack.
	*

	* @returns T - the object that is popped.
	*/
	T pop()
	{
		if (top == -1)
		{
			eTHROW("You tried to pop from the a list that is empty.");
		}
		else
		{
			T data = myArray[top];
			myArray[top] = NULL;
			top--;
			return data;
		}
	
	}
	/* T pop()
	*
	* This function is responsible for checking to see if a stack is empty or not.
	* @returns bool - true or false.
	*/
	bool empty()
	{
		if (top == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

protected:

};

