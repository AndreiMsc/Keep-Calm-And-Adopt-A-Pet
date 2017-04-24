/*
Created on Mar, 2017

@author: AndreiMsc
*/

#pragma once
#include "Repository.h"
#include "Shelter.h"

class Controller
{
private:
	Repository repo;
	Shelter shelter;

public:
	Controller(const Repository& r, const Shelter& s) : repo(r) {}

	Repository getRepo() const { return repo; }
	Shelter getShelter() const { return shelter; }

////// repository(administrator mode) functions

	// Adds a animal with the given data to the animal repository
	bool addAnimalToRepository(const std::string& breed, const std::string& name, int age, const std::string& source);
	// Removes the animal with the given data from the animal repository
	bool removeAnimalFromRepository(const std::string& breed, const std::string& name);
	/*
	Updates the animal with the given data from the animal repository
	Input: currDetail - the current detail with which the animal will be localized in the repository
		   detail - the detail which the animal will have after the update
	*/
	bool updateAnimalFromRepository(const std::string& currBreed, const std::string& currName, const std::string& breed, const std::string& name, const int age, const std::string& source);

////// shelter(user mode) functions

	/*
	Adds a given animal to the current shelter
	Input: animal - Animal, the animal must belong to the repository
	Output: the animal is added to the shelter(that is, the adoption list)
	*/
	void adoptAnimal(const Animal& animal);

};

