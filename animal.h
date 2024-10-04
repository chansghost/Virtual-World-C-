#pragma once
#include "organism.h"
#include "world.h"

class Animal : public Organism {
public:
	Animal(int x, int y, World&world);
	void action() override;
	void collision(Organism&second ) override;
	void print() override;
	void procreate(int x1, int x2, int y1, int y2);
	virtual Animal* newAnimal(int x, int y)=0;
	bool win(Organism& other);
};
