/*
Created on Mar, 2017

@author: AndreiMsc
*/

#include "UI.h"
#include <string>

using namespace std;

void UI::printMenu(){
	cout << endl;
	cout << "1 - Manage animals repository. (administrator mode: add, delete, update animals)" << endl;
	cout << "0 - Exit.\n" << endl;
}

void UI::printRepositoryMenu(){
	cout << "Possible commands: " << endl;
	cout << "\t 1 - Add animal." << endl;
	cout << "\t 2 - Remove animal." << endl;
	cout << "\t 3 - Update animal." << endl;
	cout << "\t 9 - Display all animals." << endl;
	cout << "\t 0 - Back.\n" << endl;
}

void UI::addAnimalToRepo(){
	cout << "Enter the breed: ";
	std::string breed;
	getline(cin, breed);
	cout << "Enter the name: ";
	std::string name;
	getline(cin, name);
	cout << "Photo link: ";
	std::string link;
	getline(cin, link);
	cout << "Enter the age (in months): ";
	int age;
	cin >> age;
	bool result = this->ctrl.addAnimalToRepository(breed, name, age, link);
	if (result)
		cout << "\n\tPet added succesfully!\n";
	else
		cout << "\n\tPet could not be added!\n";
	cout << "" << endl;
}

void UI::removeAnimalFromRepo(){
	cout << "Enter the breed: ";
	std::string breed;
	getline(cin, breed);
	cout << "Enter the name: ";
	std::string name;
	getline(cin, name);
	bool result = this->ctrl.removeAnimalFromRepository(breed, name);
	if (result)
		cout << "\n\tPet removed succesfully!\n";
	else
		cout << "\n\tPet could not be removed!\n";
	cout << "" << endl;
}

void UI::updateAnimalFromRepo(){
	cout << "Enter the current breed: ";
	std::string currBreed;
	getline(cin, currBreed);
	cout << "Enter the current name: ";
	std::string currName;
	getline(cin, currName);
	cout << "Enter the updated breed: ";
	std::string breed;
	getline(cin, breed);
	cout << "Enter the updated name: ";
	std::string name;
	getline(cin, name);
	cout << "Updated photo link: ";
	std::string link;
	getline(cin, link);
	cout << "Enter the updated age (in months): ";
	int age;
	cin >> age;
	bool result = this->ctrl.updateAnimalFromRepository(currBreed, currName, breed, name, age, link);
	if (result)
		cout << "\n\tPet updated succesfully!\n";
	else
		cout << "\n\tPet could not be updated!\n";
	cout << "" << endl;
}

void UI::displayAllAnimalsRepo(){
	cout << "" << endl;
	DynamicArray v = this->ctrl.getRepo().getAnimals();
	Animal* animals = v.getAllElements();
	if (animals == NULL)
		return;
	if (v.getSize() == 0){
		cout << "There are no animals in the repository." << endl;
		return;
	}
	for (int i = 0; i < v.getSize(); i++){
		Animal d = animals[i];
		cout << d.getBreed() << " - " << d.getName() << "; " << d.getAge() << endl;
	}
	cout << "" << endl;
}

void UI::run(){
	while (true){
		UI::printMenu();
		int command{ 0 };
		cout << "Input the command: ";
		cin >> command;
		cin.ignore();
		if (command == 0)
			break;
		// repository management
		if (command == 1){
			while (true){
				UI::printRepositoryMenu();
				int commandRepo{ 0 };
				cout << "Input the command: ";
				cin >> commandRepo;
				cin.ignore();
				if (commandRepo == 0)
					break;
				switch (commandRepo){
				case 1:
					this->addAnimalToRepo();
					break;
				case 2:
					this->removeAnimalFromRepo();
					break;
				case 3:
					this->updateAnimalFromRepo();
					break;
				case 9:
					this->displayAllAnimalsRepo();
				}
			}
		}
	}
}