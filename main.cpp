#include "includes.h"
#include <iostream>
#include <cstdlib>;
#include <time.h>

using namespace std;

int main() {
	srand(static_cast<unsigned int>(std::time(nullptr)));
	int height, width;
	cout << "height" << endl;
	cin >> height;
	cout << endl;
	cout << "width" << endl;
	cin >> width;
	cout << endl << endl;
	World* world;
	world=new World(height, width);
	world->setmap();
	world->newgame();
	world->play();
	world->~World();
}