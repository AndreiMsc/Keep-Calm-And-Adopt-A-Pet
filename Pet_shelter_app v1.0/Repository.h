/*
Created on Mar, 2017

@author: AndreiMsc
*/

#pragma once
#include "Animal.h"
#include "DynamicArray.h"

class Repository
{
private:
	DynamicArray animals;

public:
	/*
	Default constructor
	Initializes an object of type repository
	*/
	Repository() {}

	/*
	Adds a animal to the repository
	Input: d - Animal
	Output: true - if the animal is added to the repository
	*/
	bool addAnimal(const Animal& d);

	/*
	Removes a animal from the repository
	Input: pos - the position of th eanimal in the repository
	Output: true - the animal is removed from the repository
	*/
	bool removeAnimal(const Animal& d);

	/*
	Updates the animal with the given data from the animal repository
	Input: currDetail - the current detail with which the animal will be localized in the repository
		   detail - the detail which the animal will have after the update
	Output: updated animal
	*/
	bool updateAnimal(const int pos, const Animal& d);

	/*
	Finds animals, by breed and age
	Input: breed - string, age - int
	Output: the animals that were found, or an "empty" animal (all fields empty and age 0), if nothing was found
	*/
	Animal findByBreedAndAge(const std::string& breed, const int age);

	/*
	Finds a animal, by breed and name
	Input: breed - string, name - string
	Output: the position of the animal which was found, or -1, if nothing was found
	*/
	int findByBreedAndName(const std::string& breed, const std::string& name);

	DynamicArray getAnimals() const { return animals; }
};