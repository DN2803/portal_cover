#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
/* vector class template */
template<typename T>
class vector {
private:
	T* ptr;
	int capacity;
	int sz;
public:
	// Constructors
	vector();
	vector(int cap);
	~vector();
	// utilities methods
	/* operator[] */
	T& operator[](int n);
	/* Expand extra memory */
	void reserve(int newalloc);
	// input, output
	void push(const T& element);
	friend std::ostream& operator <<  (std::ostream& os, const vector<T>& src) {
		for (int i = 0; i < src.sz; i++) {
			os << src.ptr[i];
		}
		return os;
	};
	int size();
};


template<typename T>
vector<T>::vector()
{
	ptr = nullptr;
	capacity = 0;
	sz = 0;
}

template<typename T>
vector<T>::vector(int cap)
{
	capacity = cap;
	sz = 0;
	ptr = new T[cap];

}

template<typename T>
vector<T>::~vector()
{
	if (capacity > 0) {
		delete[] ptr;
		capacity = 0;
		sz = 0;
	}
}

template<typename T>
T& vector<T>::operator[](int n)
{
	return ptr[n];

}


template<typename T>
void vector<T>::reserve(int newalloc)
{
	if (newalloc >= 0) {
		capacity += newalloc;
		T* newptr = new T[capacity];
		for (int i = 0; i < sz; i++) {
			newptr[i] = ptr[i];
		}
		delete[] ptr;
		ptr = newptr;
	}

}


template<typename T>
void vector<T>::push(const T& element)
{
	if (sz < capacity) {
		ptr[sz] = element;
		sz++;
	}
	else {
		T* newptr = new T[sz + 1];
		for (int i = 0; i < sz; i++) {
			newptr[i] = ptr[i];
		}
		++sz;
		newptr[sz - 1] = element;
		delete[] ptr;
		ptr = newptr;
		capacity++;
	}
}
//template<typename T>
//std::ostream& operator << (std:: ostream&os, const vector<T>& src)
//{
//	for (int i = 0; i < src.sz; i++) {
//		os << src.ptr[i];
//	}
//	return os;
//}
template<typename T>
int vector<T>::size()
{
	return sz;
}
#endif


