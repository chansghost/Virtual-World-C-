#pragma once
#include "world.h"
#include <string>

class Organism {
protected:
	int strength, initiative, age;
	int x, y;
	int id, arrid=0;
	char sign;
	std::string name;
	World& world;
public:
	Organism(int x, int y, World&world);
	virtual void action()=0;
	virtual void collision(Organism& second) = 0;

	int GetS() const;
	int GetI() const;
	void SetS(int strength);
	void SetI(int initiative);

	int GetX() const;
	void SetX(int x);
	int GetY() const;
	void SetY(int y);

	int GetAge() const;
	void SetAge(int age);

	int GetId() const;
	void SetId(int id);

	int GetArrid() const;
	void SetArrid(int id);

	virtual void print() = 0;
};
