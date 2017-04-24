/*
Created on Mar, 2017

@author: AndreiMsc
*/

#pragma once
#include <iterator>

template <typename T>
class DynamicArray{

private:
	T* elements;
	int size;
	int capacity;

public:
	// default constructor for DynamicArray
	DynamicArray(int capacity = 10);

	// copy constructor for a DynamicArray
	DynamicArray(const DynamicArray& v);
	~DynamicArray();

	// assignment operator for a DynamicArray
	DynamicArray& operator=(const DynamicArray& v);

	// remove operator for a DynamicArray
	DynamicArray operator-(const T& e);

	/*
	Overloading the subscript operator

	Input:
	pos - a valid position within the vector.

	Output: 
	a reference to the element on the position pos.
	*/
	T& operator[](int pos);

	// Adds an element to the current DynamicArray
	bool add(const T& e);

	// Removes an element from the current DynamicArray
	bool remove(const int pos);

	// Updates an element from the Current DynamicArray
	bool update(const int pos, const T& d);

	// getters and setters
	int getSize() const;
	void setSize(int s) { size = s; }
	T* getAllElements() const;

private:
	// Resize the current DynamicArray, multiplying its capacity by 1.6
	void resize(int factor = 1.6);

public:
	class iterator : public std::iterator<std::forward_iterator_tag, T, std::ptrdiff_t, T*, T&>
	{
	private:
		T* ptr;
	public:
		iterator(T* p) : ptr{ p } { }
		iterator operator++() { this->ptr++; return *this; }
		iterator operator++(int dummy) { iterator i = *this; this->ptr++; return i; }
		T& operator*() { return *this->ptr; }
		T* operator->() { return this->ptr; }
		bool operator!=(const iterator& it) { return this->ptr != it.ptr; }
	};

	iterator begin()
	{
		return iterator{ this->elems };
	}

	iterator end()
	{
		return iterator{ this->elems + this->size };
	}
};

template <typename T>
DynamicArray<T>::DynamicArray(int capacity){
	this->size = 0;
	this->capacity = capacity;
	this->elements = new T[capacity];
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& a){
	this->size = a.size;
	this->capacity = a.capacity;
	this->elements = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elements[i] = a.elements[i];
}

template <typename T>
DynamicArray<T>::~DynamicArray(){
	delete[] this->elements;
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& a){
	if (this == &a)
		return *this;
	this->size = a.size;
	this->capacity = a.capacity;
	delete[] this->elements;
	this->elements = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elements[i] = a.elements[i];
	return *this;
}

template <typename T>
DynamicArray<T> DynamicArray<T>::operator-(const T& e){
	auto cpy = *this;
	for (int i = 0; i < cpy.size; ++i)
	if (cpy.elements[i] == e){
		cpy.remove(i);
		break;
	}
	return cpy;
}

template <typename T>
bool DynamicArray<T>::add(const T& e){
	if (this->size == this->capacity)
		this->resize();
	this->elements[this->size] = e;
	this->size++;
	return true;
}

template <typename T>
bool DynamicArray<T>::remove(const int pos){
	for (int i = pos; i < this->size - 1; i++){
		this->elements[i] = this->elements[i + 1];
	}
	this->size--;
	return true;
}

template <typename T>
bool DynamicArray<T>::update(const int pos, const T& d){
	this->elements[pos] = d;
	return true;
}

template <typename T>
// 'els' - an auxiliary with properties of 'elements'
void DynamicArray<T>::resize(int factor){
	this->capacity *= factor;
	T* els = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		els[i] = this->elements[i];
	delete[] this->elements;
	this->elements = els;
}

template <typename T>
T* DynamicArray<T>::getAllElements() const{
	return this->elements;
}

template <typename T>
int DynamicArray<T>::getSize() const{
	return this->size;
}