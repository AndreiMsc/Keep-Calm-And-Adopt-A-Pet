/*
Created on Mar, 2017

@author: AndreiMsc
*/

#include "Controller.h"

// 'link'(transmited from the UI) = 'source'(everywhere else except UI) = the website where the photo is present

bool Controller::addAnimalToRepository(const std::string& breed, const std::string& name, int age, const std::string& source){
	Animal d{ breed, name, age, source };
	return this->repo.addAnimal(d);
}

bool Controller::removeAnimalFromRepository(const std::string& breed, const std::string& name){
	Animal d{ breed, name, NULL, "" };
	return this->repo.removeAnimal(d);
}

bool Controller::updateAnimalFromRepository(const std::string& currBreed, const std::string& currName, const std::string& breed, const std::string& name, const int age, const std::string& source){
	int pos = this->repo.findByBreedAndName(currBreed, currName);
	if (pos == -1)
		return false;
	int checkPos = this->repo.findByBreedAndName(breed, name);
	if (checkPos == -1){
		Animal d{ breed, name, age, source };
		return this->repo.updateAnimal(pos, d);
	}
	if ((checkPos != -1) && (currName == name) && (currBreed == breed)){
		Animal d{ breed, name, age, source };
		return this->repo.updateAnimal(pos, d);
	}
	return false;
}

void Controller::adoptAnimal(const Animal& animal){
	this->shelter.add(animal);
	this->removeAnimalFromRepository(animal.getBreed(), animal.getName());
}