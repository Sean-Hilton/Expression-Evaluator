#include "Queue.h"
#include <stdexcept>
#define MAX 25

template <typename T>
Queue<T>::Queue(void)
	:front_index(0),
	back_index(0),
	ob(25),
	cur_size_(25)
	
{}

template <typename T>
Queue<T>::Queue(const Queue& q)
	:front_index(q.front_index),
	back_index(q.back_index),
	ob(q.cur_size_),
	cur_size_(q.cur_size_)
	
{
	T holder;
	for (int i = front_index; i < back_index; i++)
	{
		holder = q.ob[i];
		ob[i] = holder;
	}
}

template <typename T>

Queue <T>::~Queue(void)
{
	
	
}

template <typename T>
const Queue <T>& Queue <T>::operator = (const Queue& rhs)
{
	if (&rhs != this)
	{
		front_index = rhs.front_index;
		back_index = rhs.back_index;
		ob = rhs.ob;

	}
	return *this;
}

template <typename T>
void Queue <T>::enqueue(T element)
{
	

	if (back_index > cur_size_-1)
{
		ob.resize(ob.size()+10);
		cur_size_ = ob.size();  //sets Queue current size equal to arrays cur size
}
       
	ob[back_index] = element;
	back_index++;
	

}

//deletes heap memory if using dequeue on empty queue
template <typename T>
T Queue <T>::dequeue()
{
	if (is_empty())
	{
		
		//throw  typename Stack<T>::empty_exception();
	}
	else
	{
		T holder;
		holder = ob[front_index];
		front_index++;
		return holder;
	}
}

template <typename T>
bool Queue <T>::is_empty()
{
	if (size() == 0)
		return true;
	else
		return false;
}



template <typename T>
size_t Queue <T>::size()
{
	return (back_index - front_index);
}



template <typename T>
void Queue <T>::clear()
{
	
	front_index = 0;
	back_index = 0;
	
}



template <typename T>
T& Queue <T>::operator [] (size_t index)
{
	if (index < front_index || index >= back_index)
		throw std::out_of_range("Out of bounds");
	return ob[index];
}

template <typename T>
const T& Queue<T>::operator [] (size_t index) const
{
	if (index < front_index || index >= back_index)
		throw std::out_of_range("Out of bounds");
	return ob[index];
}



template <typename T>
 bool Queue<T>::operator == (const Queue<T>& rhs) const
{
	
	int i = 0;
	if (this->size() != rhs.size())
		return false;
	for (i = 0; i < this->size; i++)
	{

		if (ob[i] != rhs[i])
			return false;
	}
	return true;
}



//
// operator !=
//uses prev defined == method to simplify this method
template <typename T>
bool Queue <T>::operator != (const Queue<T>& rhs) const
{
	return !(*this == rhs);
}