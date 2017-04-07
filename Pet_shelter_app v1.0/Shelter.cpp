/*
Created on Mar, 2017

@author: AndreiMsc
*/

#include "Shelter.h"

Shelter::Shelter(){
	this->current = 0;
}

void Shelter::add(const Animal& animal){
	this->animals.add(animal);
}

Animal Shelter::getCurrentAnimal(){
	if (this->current == this->animals.getSize())
		this->current = 0;
	Animal* elems = this->animals.getAllElements();
	if (elems != NULL)
		return elems[this->current];
	return Animal{};
}

void Shelter::show(){
	if (this->animals.getSize() == 0)
		return;
	this->current = 0;
	Animal currentAnimal = this->getCurrentAnimal();
	currentAnimal.show();
}

void Shelter::next(){
	if (this->animals.getSize() == 0)
		return;
	this->current++;
	Animal currentAnimal = this->getCurrentAnimal();
	currentAnimal.show();
}

bool Shelter::isEmpty(){
	return this->animals.getSize() == 0;
}