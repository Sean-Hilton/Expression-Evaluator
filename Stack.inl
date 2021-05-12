// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $


#include "Stack.h"


//
// size
// returns # of total elements on stack

template <typename T>
inline
size_t Stack <T>::size (void) const
{
	return stack_top+1;
}

//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const
{
	if (is_empty() == false)
	{
		
		return ob[stack_top];
	}
	else
		throw empty_exception("Stack is empty");
}

//
// is_empty

template <typename T>
inline
bool Stack <T>::is_empty (void) const
{  


	return (stack_top == -1);
}


