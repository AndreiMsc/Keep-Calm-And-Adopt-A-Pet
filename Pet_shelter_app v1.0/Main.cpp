/*
Created on Mar, 2017

@author: AndreiMsc
*/

#include "Animal.h"
#include "UI.h"
#include <Windows.h>

using namespace std;

int main()
{
	system("color f4");

	Repository repo{};

	// add some animals
	Animal d1{ "Dog Terrier", "King", 15, "https://www.cesarsway.com/sites/newcesarsway/files/styles/large_article_preview/public/14-top-terrier-breeds.jpg?itok=gPu9xAwh" };
	Animal d2{ "Dog Labrador", "Jinx", 6, "http://www.thelabradorsite.com/wp-content/uploads/2015/07/yellow-labrador-puppy-garden.jpg" };
	Animal d3{ "Cat British Shorthair", "Pixie", 8, "http://cdn2-www.cattime.com/assets/uploads/gallery/british-shorthair-cats-and-kittens/british-shorthair-cats-and-kittens-1.jpg" };
	repo.addAnimal(d1);
	repo.addAnimal(d2);
	repo.addAnimal(d3);

	Controller ctrl{ repo };
	UI ui{ ctrl };
	ui.run();

	return 0;
}