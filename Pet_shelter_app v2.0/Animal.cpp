/*
Created on Mar, 2017

@author: AndreiMsc
*/

#include "Animal.h"
#include <Windows.h>
#include <shellapi.h>

Animal::Animal() : breed(""), name(""), age(NULL), source("") {}

Animal::Animal(const std::string& breed, const std::string& name, const int age, const std::string& source){
	this->breed = breed;
	this->name = name;
	this->age = age;
	this->source = source;
}

void Animal::show(){
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getSource().c_str(), NULL, SW_SHOWMAXIMIZED);
}

bool Animal::operator==(const Animal& d){
	if (this->breed == d.breed)
		if (this->name == d.name)
			return true;
		else
			return false;
	else
		return false;
}