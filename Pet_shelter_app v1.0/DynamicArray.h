/*
Created on Mar, 2017

@author: AndreiMsc
*/

#pragma once
#include "Animal.h"

typedef Animal TElement;

class DynamicArray{

private:
	TElement* elements;
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
	DynamicArray operator-(const TElement& e);

	// Adds an element to the current DynamicArray
	bool add(const TElement& e);

	// Removes an element from the current DynamicArray
	bool remove(const int pos);

	// Updates an element from the Current DynamicArray
	bool update(const int pos, const Animal& d);

	// getters
	int getSize() const;
	TElement* getAllElements() const;

private:
	// Resize the current DynamicArray, multiplying its capacity by 1.6
	void resize(int factor = 1.6);
};