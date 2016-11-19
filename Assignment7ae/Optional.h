/*
 * Optional.h
 *
 *  Created on: Oct 12, 2016
 *      Author: Karan
 */

#ifndef OPTIONAL_H_
#define OPTIONAL_H_

/**
   An Optional represents a value of a given type, or no value.
   It is a safer version of using a pointer that might or might
   not be null. T must have a copy constructor, but T
   need not have a default constructor.
*/
template<typename T>
class Optional
{
 public:
   /**
      Constructs an Optional in which the given value is present.
   */
   Optional(const T& val);
   /**
      Constructs an Optional where no value is present.
   */
   Optional();
   /**
      Gets the value of this optional if one is present, or defval
      otherwise.
   */
   T getOrElse(const T& defval);
   /**
      Checks whether a value is present in this Optional.
   */
   bool isPresent();

   Optional(const Optional<T>& other) { copy(other); }
   Optional<T> operator=(const Optional<T>& other) { free(); copy(other); }
   ~Optional() { free(); }

 private:
   void copy(Optional<T> other) { value = other.value == 0 ? 0 : new T(*other.value); }
   void free() { delete value; }

   T* value;
};


/*
  Fill in the missing constructors and methods.
*/
template<typename T>
Optional<T>::Optional(const T& val)
{
	this->value = new T(val);
}

template<typename T>
Optional<T>::Optional()
{
	this->value = nullptr;
}

template<typename T>
T Optional<T>::getOrElse(const T& defval)
{
	if(this->value != nullptr)
	{
		return *this->value;
	}
	else
	{
		return defval;
	}
}

template<typename T>
bool Optional<T>::isPresent()
{
	if(this->value != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

#endif /* OPTIONAL_H_ */
