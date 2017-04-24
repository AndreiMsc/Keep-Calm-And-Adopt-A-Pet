/*
Created on Mar, 2017

@author: AndreiMsc
*/

#pragma once
#include <iostream>

class Animal{

private:
	std::string breed;
	std::string name;
	int age;
	std::string source;		// google link

public:

	// default constructor for a animal
	Animal();

	// constructor with parameters for animal
	Animal(const std::string& breed, const std::string& name, const int age, const std::string& source);

	// getters
	std::string getBreed() const { return breed; }
	std::string getName() const { return name; }
	int getAge() const { return age; }
	std::string getSource() const { return source; }

	// Opens the picture of the current animal (the page corresponding to the link)
	void show();

	//equality operator for two animals
	bool operator==(const Animal& d);
};