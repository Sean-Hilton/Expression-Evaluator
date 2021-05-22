
#include <iostream>
#include <stdexcept>
#include "Stack.h"
#define MAX 25
//
// Stack
//
template <typename T>
Stack <T>::Stack(void)
	:stack_top(-1),
	 ob(MAX)
	
	
{
}

//
// Stack
//
template <typename T>
Stack <T>::Stack(const Stack& stack)
	
	:stack_top(stack.stack_top)

{
	T holder;
	for (int i = 0; i <= stack_top; i++)
	{
		holder = stack.ob[i];
		ob[i] = holder;
	}
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack(void)
{
}

//
// push
//                 
template <typename T>
void Stack <T>::push(T element)
{
	if (stack_top == MAX-1)
	{
		
		throw std::out_of_range("Stack is full");
	}
	else 
	{
		stack_top++;
		ob[stack_top] = element;
	}
}

//
// pop
//
template <typename T>
void Stack <T>::pop(void)
{
	if (!is_empty())
	{
		stack_top--;
	}
	else
		throw empty_exception("Stack is empty");
}

//
// operator =
//
template <typename T>
const Stack <T>& Stack <T>::operator = (const Stack& rhs)
{
	if (&rhs != this)
	{
		
		stack_top = rhs.stack_top;
		ob = rhs.ob;
		
		

	}
	return *this;
}

//
// clear
// old elements will be removed as new elements are added
// operator [] relies on stack_top
template <typename T>
void Stack <T>::clear(void)
{

	stack_top = -1;
}

//
//operator []
//
template <typename T>
T& Stack <T>::operator [] (size_t index)
{
	
	if (index < 0 || index >= this->size())
		throw std::out_of_range("Out of bounds");
	
		return ob[index];
}

//User can only index stack elements on the stack
template <typename T>
const T& Stack<T>::operator [] (size_t index) const
{
	std::cout<<this->stack_top;
	if (index < 0 || index > this->size())
		throw std::out_of_range("Out of bounds");	

		return ob[index];

}





template <typename T>
bool Stack <T>::operator != (const Stack <T> & rhs) const
{
	return !(*this == rhs);
}




template <typename T>
 bool Stack<T>::operator == (const Stack<T>& rhs) const
{
	int i = 0;
	if (stack_top + 1 != rhs.stack_top+1)
		return false;
	for (i = 0; i < stack_top+1; i++)
	{

		if (ob[i] != rhs[i])
			return false;
	}
	return true;
}



