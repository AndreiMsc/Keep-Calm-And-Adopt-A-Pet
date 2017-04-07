/*
Created on Mar, 2017

@author: AndreiMsc
*/

#pragma once
#include "Controller.h"

class UI
{
private:
	Controller ctrl;

public:
	UI(const Controller& c) : ctrl(c) {}

	void run();

private:
	static void printMenu();
	static void printRepositoryMenu();
	static void printShelterMenu();

	// repository(administrator mode) functions
	void addAnimalToRepo();
	void removeAnimalFromRepo();
	void updateAnimalFromRepo();
	void displayAllAnimalsRepo();
	
	// shelter(user mode) functions
	void addAnimalToShelter();
};

