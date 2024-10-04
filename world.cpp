#include "includes.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

World::World(int height, int width) : height(height), width(width) {
	map = new char* [height];
	for (int i = 0; i < height; i++) {
		map[i] = new char[width];
	}
	organisms = new Organism * [height * width];

}

int World::GetH() const {
	return height;
}

int World::GetW() const {
	return width;
}
void World::setmap() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j] = '.';
		}
	}
}
Organism* World::isEmpty(int x, int y) {
	if (map[x][y] == '.') {
		return nullptr;
	}
	for (int i = 0; i < organismcount; i++) {
		if (organisms[i] != nullptr)
			if (organisms[i]->GetX() == x && organisms[i]->GetY() == y)
				return organisms[i];
	}
}


void World::newgame() {
	int x, y;
	int amount = rand() % 5;
	amount++;
	for (int i = 0; i < 5; i++) {
		while (true) {
			x = (rand() % width);
			y = (rand() % height);
			if (isEmpty(x, y) == nullptr) {
				organisms[organismcount] = new Sheep(x, y, *this);
				organisms[organismcount]->SetArrid(organismcount);
				organismcount++;
				break;
			}
		}
	}
}

void World::kill(Organism& dead) {
	updatemap('.', dead.GetX(), dead.GetY());
	int i = dead.GetArrid();
	delete organisms[i];
}



void World::updatemap(char sign, int x, int y) {
	map[y][x] = sign;
}

void World::addOrganism(Organism* organism) {
	organisms[organismcount] = organism;
	organism->SetArrid(organismcount);
	organismcount++;
}
void World::play() {
	char choice=' ';
	
	cout << "siema" << endl;
	printmap();
	cout << endl;
	while (choice != 'q') {
		choice = _getch();
		switch (choice) {
		case 't':
			system("CLS");
			turn();
			
			printmap();
			break;
		case 'q':
			break;
		}
		

	}

}

void World::turn() {
	for (int i = 0; i < organismcount; i++) {
		if (organisms[i] != nullptr) {
			if (organisms[i]->GetId() < 6) {//id 6 i wyzej to rosliny
				organisms[i]->action();
			}
		}
	}
}

void World::printmap() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j] = '.';
		}
	}
	for (int i = 0; i < organismcount; i++) {
		organisms[i]->print(); //addtomap essentially
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}


}

void World::incr_organismcount() {
	organismcount += 1;
}

void World::addtomap(int x, int y, char sign) {
	map[x][y] = sign;
}

World::~World() {
	for (int i = 0; i < width * height; i++) {
		if (organisms[i] != nullptr) {
			delete organisms[i];
		}
	}
}