#pragma once

class Organism;
//dziala na zasadzie library chyba
class World {
public:
	World(int height, int width);
	void setmap();
	void newgame();
	void printmap();
	void turn();
	void addOrganism(Organism* organism);
	void updatemap(char sign, int x, int y);
	void incr_organismcount();
	void addtomap(int x, int y, char sign);
	void kill(Organism& dead);
	void play();
	int GetH() const;
	int GetW() const;
	char** map;
	Organism* isEmpty(int x, int y);
	~World();
private:
	int height;
	int width;
	
	int organismcount = 0;
	Organism** organisms;
	//*organizm organizm
};