#pragma once
#include "animal.h"

class Sheep : public Animal {
public:
	Sheep(int x, int y, World& world);
	Animal* newAnimal(int x, int y) override;
};
