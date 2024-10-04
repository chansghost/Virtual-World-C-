#include <iostream>
#include "animal.h"
#include "organism.h"
#include "world.h"

Animal::Animal(int x, int y, World&world):Organism(x,y,world){}

void Animal::action() {
	int changeX = 0, changeY = 0, rNum;
	int x2, y2;
		
	while (true)
	{
		rNum = (rand() % 100) % 4;
		if (rNum == 0) {
			changeX = -1;
		}
		else if (rNum == 1) {
			changeX = 1;
		}
		else if (rNum == 2) {
			changeY = -1;
		}
		else {
			changeY = 1;
		}
		if (x + changeX < world.GetW() && y + changeY < world.GetH() && x + changeX >= 0 && y + changeY >= 0) {
			x2 = x + changeX;
			y2 = y + changeY;
			break;
		}
		else {
			changeX = 0;
			changeY = 0;
		}
	}
	if (world.isEmpty(x2, y2) == nullptr) {
		std::cout << name << "has moved from (" << x << ", " << y << ") to (" << x2 << ", " << y2 << ")" << std::endl;
		this->SetX(x2);
		this->SetY(y2);
		world.updatemap(sign, x2, y2);
	}
	else {
		std::cout << "kolizja " << x << " " << y << " z " << x2 << " " << y2 << std::endl;
		std::cout << world.map[x][y] << " " << world.map[x2][y2] << std::endl;
		collision(*(world.isEmpty(x2, y2)));
	}
	
}

bool Animal::win(Organism& other) {
	if (strength > other.GetS()) {
		std::cout << "wohoo survived"<<std::endl;
		return true;
	}
	std::cout << "bohoo died" << std::endl;
	return false;
}

void Animal::collision(Organism&second) {
	if (second.GetId() == id) {
		procreate(x, y, second.GetX(), second.GetY());
	}
	else {
		if (win(second)) {
			world.kill(second);
		}
		else {
			world.kill(*this);
		}
	}
}

void Animal::procreate(int x1, int x2, int y1, int y2) {
	bool success = false;
	int newx, newy;
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			if (world.isEmpty(x1 + j, y1 + i) == nullptr) {
				newx = x1 + j;
				newy = y1 + i;
				Animal* babyanimal = newAnimal(newx, newy);
					
				world.addOrganism(babyanimal);
				success = true;
				break;
			}
			else if (world.isEmpty(x2 + j, y2 + i) == nullptr) {
				newx = x2 + j;
				newy = y2 + i;
				Animal* babyanimal = newAnimal(newx, newy);
					
				world.addOrganism(babyanimal);
				success = true;
				break;
			}
			if (success) {
				world.updatemap(sign, newx, newy);
				std::cout << "congrats new child" << std::endl;
				return;
			}
		}
		
	}
	std::cout << "bohoo no new spawn" << std::endl;
}

void Animal::print() {
	world.addtomap(x, y, sign);
}