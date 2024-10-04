#include "organism.h"

Organism::Organism(int x, int y, World& world) : x(x), y(y), world(world) {

}

int Organism::GetS() const{
	return strength;
}

void Organism::SetS(int strength) {
	this->strength=strength;
}

int Organism::GetI() const {
	return initiative;
}

void Organism::SetI(int initiative) {
	this->initiative = initiative;
}

int Organism::GetX() const {
	return x;
}

void Organism::SetX(int x) {
	this->x = x;
}

int Organism::GetY() const {
	return y;
}

void Organism::SetY(int y) {
	this->y = y;
}

int Organism::GetAge() const {
	return age;
}

void Organism::SetAge(int age) {
	this->age = age;
}

int Organism::GetId() const {
	return id;
}

void Organism::SetId(int id) {
	this->id = id;
}

int Organism::GetArrid() const {
	return arrid;
}

void Organism::SetArrid(int arrid) {
	this->arrid = arrid;
}