#include "sheep.h"

Sheep::Sheep(int x, int y, World& world) :Animal(x, y, world) {
	strength = 4;
	initiative = 4;
	sign = 'S';
	id = 2;
	name = "Sheep";
}

Animal* Sheep::newAnimal(int x, int y) {
	Animal* babyanimal = new Sheep(x, y, world);
	return babyanimal;
}