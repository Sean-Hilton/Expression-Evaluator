
#ifndef _IARRAY_H_
#define _IARRAY_H_
#include <iostream>
template <typename T>
class IArray {

public:

	

 /*	
 * Get the character at the specified index. If the index is not
 * within the range of the array, then std::out_of_range exception
 * is thrown.
 *
 * @param[in]       index               Zero-based location
 * @exception       std::out_of_range   Invalid \a index value
 */
	virtual T& operator [] (size_t index) = 0;

	/**
	 * @overload
	 *
	 * The returned character is not modifiable.
	 */
	virtual const T& operator [] (size_t index) const = 0;



	/**
	 * Get the character at the specified index. If the \a index is not within
	 * the range of the array, then std::out_of_range exception is thrown.
	 *
	 * @param[in]       index                 Zero-based location
	 * @return          Character at \index
	 * @exception       std::out_of_range     Invalid index value
	 */
	virtual T get(size_t index) const = 0;





	/**
	* Set the character at the specified \a index. If the \a index is not
	 * within range of the array, then std::out_of_range exception is
	 * thrown.
	 *
	* @param[in]       index                 Zero-based location
	* @param[in]       value                 New value for character
	* @exception       std::out_of_range     Invalid \a index value
	*/
	virtual void set(size_t index, T value) = 0;




	/**
	 * Locate the specified character in the array. The index of the first
	 * occurrence of the character is returned. If the character is not
	 * found in the array, then -1 is returned.
	 *
	 * @param[in]        ch        Character to search for
	 * @return           Index value of the character
	 * @retval           -1        Character not found
	 */
	virtual int find(T element) const = 0;





	/**
	 * @overload
	 *
	 * This version allows you to specify the start index of the search. If
	 * the start index is not within the range of the array, then the
	 * std::out_of_range exception is thrown.
	 *
	 * @param[in]       ch                   Character to search for
	 * @param[in]       start                Index to begin search
	 * @return          Index value of first occurrence
	 * @retval          -1                   Character not found
	 * @exception       std::out_of_range    Invalid index
	 */
	virtual int find(T element, size_t start) const = 0;

	/**




	/**
	 * Fill the contents of the array.
	 *
	 * @param[in]       ch                   Fill character
	 */
	virtual void fill(T element) = 0;

	virtual void reverse() = 0;



};
#endif
