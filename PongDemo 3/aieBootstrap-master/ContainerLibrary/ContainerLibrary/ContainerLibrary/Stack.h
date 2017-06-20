#pragma once
#include<iostream>
#include "Exeception.h"
#define default_value 5
template <class T>
class Stack {
	
	
	
	
public:
	T object; // this is to store values.
	T tempTop; // this is to store the value of the top of the stack when it is deleted.
	int top; // this is a index of the amount in the stack.
	T* myArray;
	Stack()
	{
		// this creates an empty stack with the amount of spaces previously defined by 'default_value'
		
			myArray = new T[default_value];
		
		// this defaults the index to be -1 to signifiy the stack is empty of values.
		top = -1;
	}

	Stack(int n)
	{
		eASSERT(n > 0);
		// this creates an empty stack with the amount of spaces previously defined by 'default_value'
		myArray = new T[n];
		// this defaults the index to be -1 to signifiy the stack is empty of values.
		top = -1;

	}

	~Stack()
	{
		//delete[] myArray;
	}

	//This pushes a value to the top of the stack and will increment the index.
	void push(T object)
	{
		top++;
		if (top < default_value)
		{
			myArray[top] = object;
		}
		// if the stack is full, dont allow the user to add to the stack 
		else
		{
			throw;	
		}
	}

	T pop()
	{
		if (top == -1)
		{
			throw;
		}
		else
		{
			T data = myArray[top];
			myArray[top] = NULL;
			top--;
			return data;
		}
	
	}
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

