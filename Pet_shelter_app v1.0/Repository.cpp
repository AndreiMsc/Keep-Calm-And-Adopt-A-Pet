/*
Created on Mar, 2017

@author: AndreiMsc
*/

#include "Repository.h"
#include <string>

using namespace std;

bool Repository::addAnimal(const Animal& d){
	int alreadyExists = findByBreedAndName(d.getBreed(), d.getName());
	if (alreadyExists != -1)
		return false;
	return this->animals.add(d);
}

/*
bool Repository::removeAnimal(const Animal& d){
	int pos;
	Animal* animalsInDynamicArray = this->animals.getAllElements();
	if (animalsInDynamicArray == NULL)
		pos = -2;
	for (int i = 0; i < this->animals.getSize(); i++){
		Animal animal = animalsInDynamicArray[i];
		if (animal == d)
			pos = i;
	}
	return this->animals.remove(pos);
}
*/

bool Repository::removeAnimal(const Animal& d){
	Animal* animalsInDynamicArray = this->animals.getAllElements();
	for (int i = 0; i < this->animals.getSize(); i++){
		Animal animal = animalsInDynamicArray[i];
		if (animal == d){
			this->animals = this->animals - d;
			return true;
		}
	}
	return false;
}

bool Repository::updateAnimal(const int pos, const Animal& d){
	return this->animals.update(pos, d);
}

// ToFix:: Only finds the first animal with the asked breed and age
Animal Repository::findByBreedAndAge(const std::string& breed, const int age){
	Animal* animalsInDynamicArray = this->animals.getAllElements();
	if (animalsInDynamicArray == NULL)
		return Animal{};
	for (int i = 0; i < this->animals.getSize(); i++){
		Animal d = animalsInDynamicArray[i];
		if (d.getBreed() == breed && d.getAge() <= age)
			return d;
	}
	return Animal{};
}

int Repository::findByBreedAndName(const std::string& breed, const std::string& name){
	Animal d{ breed, name, NULL, "" };
	Animal* animalsInDynamicArray = this->animals.getAllElements();
	if (animalsInDynamicArray == NULL)
		return -2;
	for (int i = 0; i < this->animals.getSize(); i++){
		Animal animal = animalsInDynamicArray[i];
		if (animal == d)
			return i;
	}
	return -1;
}