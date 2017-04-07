/*
Created on Mar, 2017

@author: AndreiMsc
*/

#include "DynamicArray.h"
#include <iostream>

DynamicArray::DynamicArray(int capacity){
	this->size = 0;
	this->capacity = capacity;
	this->elements = new TElement[capacity];
}

DynamicArray::DynamicArray(const DynamicArray& a){
	this->size = a.size;
	this->capacity = a.capacity;
	this->elements = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elements[i] = a.elements[i];
}

DynamicArray::~DynamicArray(){
	delete[] this->elements;
}

DynamicArray& DynamicArray::operator=(const DynamicArray& a){
	if (this == &a)
		return *this;
	this->size = a.size;
	this->capacity = a.capacity;
	delete[] this->elements;
	this->elements = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elements[i] = a.elements[i];
	return *this;
}

DynamicArray DynamicArray::operator-(const TElement& e){
	auto cpy = *this;
	for (int i = 0; i < cpy.size; ++i)
		if (cpy.elements[i] == e){
			cpy.remove(i);
			break;
		}
	return cpy;
}

bool DynamicArray::add(const TElement& e){
	if (this->size == this->capacity)
		this->resize();
	this->elements[this->size] = e;
	this->size++;
	return true;
}

bool DynamicArray::remove(const int pos){
	for (int i = pos; i < this->size - 1; i++){
		this->elements[i] = this->elements[i + 1];
	}
	this->size--;
	return true;
}

bool DynamicArray::update(const int pos, const Animal& d){
	this->elements[pos] = d;
	return true;
}

// 'els' - an auxiliary with properties of 'elements'
void DynamicArray::resize(int factor){
	this->capacity *= factor;
	TElement* els = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		els[i] = this->elements[i];
	delete[] this->elements;
	this->elements = els;
}

TElement* DynamicArray::getAllElements() const{
	return this->elements;
}

int DynamicArray::getSize() const{
	return this->size;
}