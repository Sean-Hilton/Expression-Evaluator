#include <iostream>
#include <stdexcept>         // for std::out_of_bounds exception

//
// Array
//
template <typename T>
Array <T>::Array(void)
	:data_(new T[0]),
	cur_size_(0),
	max_size_(100)
{
}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array(size_t length)
	:data_(new T[length]),
	cur_size_(length),
	max_size_(100)
{
}

//
// Array (size_t, char)
//
template <typename T>
Array <T>::Array(size_t length, T fill)
	:data_(new T[length]),
	cur_size_(length),
	max_size_(100)
{
	for (int i = 0; i < cur_size_; i++)
	{
		data_[i] = fill;

	}
}

//
// Array (const Array &)
//
template <typename T>
Array<T>::Array(const Array& array)
	:data_(new T[array.cur_size_]),
	cur_size_(array.cur_size_),
	max_size_(array.max_size_)
{
	T holder;
	for (int i = 0; i < array.cur_size_; i++)
	{
		holder = array[i];

		data_[i] = holder;
	}
}

//
// ~Array
//
template <typename T>
Array <T>::~Array(void)
{
	delete[] data_;
	data_ = nullptr;
}

//
// operator =
//
//checks to see if they are the same
template <typename T>
const Array<T>& Array<T>:: operator = (const Array<T>& rhs)
{
	if (&rhs != this)  
	{
		delete[] data_;
		cur_size_ = rhs.cur_size_;
		data_ = new T[cur_size_];
		for (int i = 0; i < cur_size_; i++)
			data_[i] = rhs.data_[i];

	}
	return *this;
}


//
// operator []
//
template <typename T>
T& Array<T>::operator [] (size_t index)
{
	if (index < 0 || index >= cur_size_)
		throw std::out_of_range("Out of bounds");
	return data_[index];
}

//
// operator [] 
//
template <typename T>
 const T& Array<T>:: operator [] (size_t index) const
{
	if (index < 0 || index >= cur_size_)
		throw std::out_of_range("Out of bounds");
	return data_[index];
}

//
// get
//
template <typename T>
T Array <T>::get(size_t index) const
{
	if (index < 0 || index >= cur_size_)
		throw std::out_of_range("Out of bounds");
	return data_[index];
}

//
// set
//
template <typename T>
void Array <T>::set(size_t index, T value)
{
	if (index < 0 || index >= cur_size_)
		throw std::out_of_range("Out of bounds");
	data_[index] = value;
}

//
// resize
// throws error if new size exceeds max size
//frees memory before allocating new dynamic array
template <typename T>
void Array <T>::resize(size_t new_size)
{
	if (new_size > max_size_)
		throw std::out_of_range("Passed max size");
	if (new_size == cur_size_)
	{
	}
	else if (new_size > cur_size_)
	{

		T* new_ar = new T[new_size];
		for (int i = 0; i < cur_size_; i++)
			new_ar[i] = data_[i];
		delete[] data_;    
		data_ = new_ar;
		cur_size_ = new_size;

		new_ar = nullptr;
	}
	else
	{

		T* new_ar = new T[new_size];
		for (int i = 0; i < new_size; i++)
			new_ar[i] = data_[i];
		delete[] data_;
		data_ = new_ar;
		cur_size_ = new_size;

		new_ar = nullptr;

	}

}

//
// find (char)
//
template  <typename T>
int Array <T>::find(T element) const
{
	for (int i = 0; i < cur_size_; i++)
	{
		if (data_[i] == element)
			return i;
	}

	std::cout << "Char not found" << std::endl;

	return -1;
}

//
// find (char, size_t) 
//
template <typename T>
int Array <T>::find(T element, size_t start) const
{
	if (start >= cur_size_ || start < 0)
		throw std::out_of_range("Out of bounds");
	for (start; start < cur_size_; start++)
	{
		if (data_[start] == element)
			return start;
	}

	std::cout << "Char not found" << std::endl;

	return -1;
}

//
// operator ==
//
template <typename T>
 bool Array<T>::operator == (const Array<T>& rhs) const
{
	int i = 0;
	if (cur_size_ != rhs.cur_size_)
		return false;
	for (i = 0; i < cur_size_; i++)
	{

		if (data_[i] != rhs[i])
			return false;
	}
	return true;
}

//
// operator !=
//uses prev defined == method to simplify this method
template <typename T>
bool Array <T>::operator != (const Array<T>& rhs) const
{
	return !(*this == rhs);
}

//
// fill
//
template <typename T>
void Array<T>::fill(T value)
{
	for (int i = 0; i < cur_size_; i++)
		data_[i] = value;
}


//frees memory before assigning new dynamic array to data_
template <typename T>
void Array<T>::shrink(void)
{
	int counter = 0;
	for (int i = 0; i < cur_size_; i++)
	{
		if ((int)data_[i] != '\0')
			counter++;
	}
	T* newar = new T[counter];
	for (int i = 0; i < counter; i++)
		newar[i] = data_[i];
	
	delete [] data_;
	data_ = newar;
	cur_size_ = counter;
}


//slices from beginning and includes end element
template <typename T>
Array<T> Array<T>::slice(size_t begin)const


{
	int cpycnt = 0;
	size_t newsize = cur_size_;
	newsize = newsize - begin;
	Array sp4(newsize);
	for (begin; begin < cur_size_; begin++)
	{
		sp4.data_[cpycnt] = data_[begin];
		++cpycnt;
	}
	sp4.cur_size_ = newsize;
	return sp4;
}

//slices from beginning but does NOT include specified end index
template <typename T>
Array<T> Array<T>::slice(size_t begin, size_t end)const
{
	int cpycnt = 0;
	size_t newsize = end - begin;
	Array sp4(newsize);
	for (begin; begin < end; begin++)
	{
		sp4.data_[cpycnt] = data_[begin];
		++cpycnt;
	}
	sp4.cur_size_ = newsize;
	return sp4;
}
template <typename T>
void Array<T>::reverse(void)
{
	int start = 0;
	int end = cur_size_ - 1;
	for (int i = 0; i < cur_size_; i++)
	{

		while (start < end)
		{
			T holder = data_[start];
			data_[start] = data_[end];
			data_[end] = holder;
			start++;
			end--;
		}

	}

}
