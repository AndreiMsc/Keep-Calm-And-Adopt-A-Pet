/*
Created on Mar, 2017

@author: AndreiMsc
*/

#pragma once
#include "DynamicArray.h"
#include "Animal.h"

class Shelter{
private:
	DynamicArray<Animal> animals;
	int current;

public:
	Shelter();

	// Adds a animal to the shelter
	void add(const Animal& animal);

	// Returns the song that is currently shown
	Animal Shelter::getCurrentAnimal();

	// Starts the shelter presentation - shows the first animal
	void show();

	// Shows the next animal in the shelter
	void next();

	// Checks if the animal is empty
	bool isEmpty();

	DynamicArray<Animal> getAnimals() const { return animals; }
};

