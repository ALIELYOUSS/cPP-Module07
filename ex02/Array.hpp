#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>

template <typename T>
class Array
{
public:
	class OutOfRangeException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Array index out of range";
		}
	};

	Array() : _data(0), _size(0)
	{
	}

	explicit Array(unsigned int n) : _data(n ? new T[n]() : 0), _size(n)
	{
	}

	Array(Array const &other) : _data(0), _size(0)
	{
		*this = other;
	}

	~Array()
	{
		delete[] _data;
	}

	Array &operator=(Array const &other)
	{
		if (this != &other)
		{
			T *newData = other._size ? new T[other._size]() : 0;
			for (unsigned int index = 0; index < other._size; ++index)
				newData[index] = other._data[index];
			delete[] _data;
			_data = newData;
			_size = other._size;
		}
		return *this;
	}

	unsigned int size() const
	{
		return _size;
	}

	T &operator[](unsigned int index)
	{
		if (index >= _size)
			throw OutOfRangeException();
		return _data[index];
	}

	T const &operator[](unsigned int index) const
	{
		if (index >= _size)
			throw OutOfRangeException();
		return _data[index];
	}

private:
	T *_data;
	unsigned int _size;
};

#endif
