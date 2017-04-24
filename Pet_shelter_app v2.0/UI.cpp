/*
Created on Mar, 2017

@author: AndreiMsc
*/

#include "UI.h"
#include <string>
#include <Windows.h>
#include <shellapi.h>

using namespace std;

void UI::printMenu(){
	cout << endl;
	cout << "1 - Manage animals repository. (administrator mode: add, delete, update animals)" << endl;
	cout << "2 - Manage shelter/adoption list. (user mode: see animals one by one(with pictures), adopt animals etc)" << endl;
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
	DynamicArray<Animal> v = this->ctrl.getRepo().getAnimals();
	Animal* animals = v.getAllElements();
	if (animals == NULL)
		return;
	if (v.getSize() == 0){
		cout << "There are no animals in the repository.\n" << endl;
		return;
	}
	for (int i = 0; i < v.getSize(); i++){
		Animal d = animals[i];
		cout << d.getBreed() << " - " << d.getName() << "; " << d.getAge() << endl;
	}
	cout << "" << endl;
}

void UI::printShelterMenu(){
	cout << "Possible commands: " << endl;
	cout << "\t 1 - See all animals." << endl;
	cout << "\t 2 - See all the dogs of a given breed, having an age less than a given number(if the breed is empty, all breeds will be considered)." << endl;
	cout << "\t 9 - See the adoption list." << endl;
	cout << "\t 0 - Back.\n" << endl;
}

void UI::printAdoptionMenu(){
	cout << "\t Possible commands: " << endl;
	cout << "\t\t 1 - Adopt the animal." << endl;
	cout << "\t\t 2 - Don't adopt the animal." << endl;
	cout << "\t\t 0 - Stop showing animals.\n" << endl;
}

void UI::seeAllAnimalsShelter(){
	int commandAdoption2;
	cout << "" << endl;
	DynamicArray<Animal> v = this->ctrl.getRepo().getAnimals();
	Animal* animals = v.getAllElements();
	if (animals == NULL)
		return;
	if (v.getSize() == 0){
		cout << "There are no animals in the repository." << endl;
		return;
	}
	while (true){
		DynamicArray<Animal> v = this->ctrl.getRepo().getAnimals();
		Animal* animals = v.getAllElements();
		if (v.getSize() == 0){
			cout << "There are no more animals in the repository." << endl;
			break;
		}
		for (int i = 0; i < v.getSize(); i++){
			Animal d = animals[i];
			cout << d.getBreed() << " - " << d.getName() << "; " << d.getAge() << endl;
			ShellExecuteA(NULL, NULL, "chrome.exe", d.getSource().c_str(), NULL, SW_SHOWMAXIMIZED);
			UI::printAdoptionMenu();
			int commandAdoption{ 0 };
			cout << "\t Input the command: ";
			cin >> commandAdoption;
			cin.ignore();
			commandAdoption2 = commandAdoption;
			if (commandAdoption == 0)
				break;
			if (commandAdoption == 1)
				this->ctrl.adoptAnimal(d);
		}
		if (commandAdoption2 == 0)
			break;
		cout << "\tAll animals were shown. Do you want to start again?(animals adopted will be excluded) [0-NO / any other digit-YES]:\t" << endl;
		int option;
		cin >> option;
		if (option == 0){
			break;
		}
	}
	cout << "" << endl;
}

void UI::seeByBreedAndAgeShelter(){
	cout << "Enter the breed: ";
	std::string breed;
	getline(cin, breed);
	cout << "Enter the age (in months): ";
	int age;
	cin >> age;
	int commandAdoption2;
	cout << "" << endl;
	DynamicArray<Animal> v = this->ctrl.getRepo().getAnimals();
	Animal* animals = v.getAllElements();
	if (animals == NULL)
		return;
	if (v.getSize() == 0){
		cout << "There are no animals in the repository." << endl;
		return;
	}
	while (true){
		DynamicArray<Animal> v = this->ctrl.getRepo().getAnimals();
		Animal* animals = v.getAllElements();
		if (v.getSize() == 0){
			cout << "There are no more animals in the repository." << endl;
			break;
		}
		for (int i = 0; i < v.getSize(); i++){
			Animal d = animals[i];
			commandAdoption2 = -1;
			if ( ((d.getBreed() == breed) && (d.getAge() <= age)) || ((breed == "") && (d.getAge() <= age)) ){
				cout << d.getBreed() << " - " << d.getName() << "; " << d.getAge() << endl;
				ShellExecuteA(NULL, NULL, "chrome.exe", d.getSource().c_str(), NULL, SW_SHOWMAXIMIZED);
				UI::printAdoptionMenu();
				int commandAdoption{ 0 };
				cout << "\t Input the command: ";
				cin >> commandAdoption;
				cin.ignore();
				commandAdoption2 = commandAdoption;
				if (commandAdoption == 0)
					break;
				if (commandAdoption == 1)
					this->ctrl.adoptAnimal(d);
			}
		}
		if (commandAdoption2 == 0)
			break;
		cout << "\tAll animals were shown. Do you want to start again?(animals adopted will be excluded) [0-NO / other key-YES]:\t" << endl;
		int option;
		cin >> option;
		if (option == 0){
			break;
		}
	}
	cout << "" << endl;
}

void UI::displayAllAnimalsShelter(){
	cout << "" << endl;
	DynamicArray<Animal> v = this->ctrl.getShelter().getAnimals();
	Animal* animals = v.getAllElements();
	if (animals == NULL)
		return;
	if (v.getSize() == 0){
		cout << "There are no animals in the adoption list.\n" << endl;
		return;
	}
	for (int i = 0; i < v.getSize(); i++){
		Animal d = animals[i];
		cout << d.getBreed() << " - " << d.getName() << "; " << d.getAge() << endl;
	}
	cout << "" << endl;
}

void UI::run(){
	cout << "Wellcome! --- @author: AndreiMsc\n" << endl;
	cout << "Also, don't forget to visit my website: https://github.com/AndreiMsc/" << endl;
	while (true){
		UI::printMenu();
		int command{ 0 };
		cout << "Input the command: ";
		cin >> command;
		cin.ignore();
		if (command == 0)
			break;
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
		if (command == 2){
			while (true){
				UI::printShelterMenu();
				int commandShelter{ 0 };
				cout << "Input the command: ";
				cin >> commandShelter;
				cin.ignore();
				if (commandShelter == 0)
					break;
				switch (commandShelter){
				case 1:
					this->seeAllAnimalsShelter();
					break;
				case 2:
					this->seeByBreedAndAgeShelter();
				case 3:
					this->displayAllAnimalsShelter();
				}
			}
		}
	}
}