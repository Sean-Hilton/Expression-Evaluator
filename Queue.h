
#ifndef _CS507_Queue_H_
#define _CS507_Queue_H_
#include "Array.h"
#include <exception>


template <typename T>
class Queue
{
public:
	typedef T type;



	//default const
	Queue(void);

	Queue(const Queue& q);

	~Queue(void);

	const Queue& operator = (const Queue& rhs);

	void enqueue(T element);

	T dequeue(void);

	bool is_empty();

	size_t size();

	void clear();

	bool operator != (const Queue<T>& rhs) const;
	virtual T& operator [] (size_t index);
	virtual const T& operator [] (size_t index) const;


	bool operator == (const Queue<T>& rhs) const;



private:
	size_t front_index;
	size_t back_index;

	//useful for keeping track of total array allocation size
	size_t cur_size_;

	
	Array<T> ob;

	



};

#include "Queue.cpp"



#endif 