
#ifndef _ARRAY_H_
#define _ARRAY_H_

#include "IArray.h"
#include <cstring>          // for size_t definition

/**
 * @class Array
 *
 * Basic implementation of a standard array class for chars.
 */
template <typename T>
class Array : IArray <T> 
{
public:
	/// Type definition of the element type.
	typedef T type;

	/// Default constructor.
     Array(void);

	/**
	 * Initializing constructor.
	 *
	 * @param[in]      length        Initial size
	 */
	Array(size_t length);

	/**
	 * Initializing constructor.
	 *
	 * @param[in]      length        Initial size
	 * @param[in]      fill          Initial value for each element
	 */
	Array(size_t length, T fill);

	/**
	 * Copy constructor
	 *
	 * @param[in]     arr         The source array.
	 */
	Array(const Array& arr);

	/// Destructor.
	~Array(void);
	
	

	/**
	 * Retrieve the current size of the array.
	 *
	 * @return          The current size
	 */
	size_t size(void) const;

	/**
	 * Retrieve the maximum size of the array.
	 *
	 * @return          The maximum size
	 */
	size_t max_size(void) const;

	

	


	//VIRTUAL METHODS 
	
	virtual T& operator [] (size_t index);
	virtual const T& operator [] (size_t index) const;
	virtual T get(size_t index) const;
	virtual void set(size_t index, T value);
	virtual int find(T element) const;
	virtual int find(T element, size_t start) const;
	virtual void fill(T element);
	virtual void reverse(void);

	//METHODS UNIQUE TO CLASS
	
	void resize(size_t new_size);
	bool operator == (const Array<T>& rhs) const;
	bool operator != (const Array<T>& rhs) const;
	void shrink();
	Array slice(size_t begin)const;
	Array slice(size_t begin, size_t end)const;
	const Array& operator = (const Array& rhs);

	

	
private:
	/// Pointer to the actual data.
	T* data_;

	/// Current size of the array.
	size_t cur_size_;

	/// Maximum size of the array.
	size_t max_size_;
};

#include "Array.inl"
#include "Array.cpp"

#endif   // !defined _ARRAY_H_
