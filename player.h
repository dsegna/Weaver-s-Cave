#ifndef _PLAYER_H_
    #define _PLAYER_H_
#include "main.h"
class player{
private:
	char sprite;
	int posx, posy;
	bool torch;
	item inventory[10];
public:
	player();
	void draw();
	void setStart(map inMap, int entrance=1);
	int move(int x, int y, map map1);
	bool getItem(int itemId);
	int getx();
	int gety();
	bool getTorch();
	bool checkItems(int ItemID);
	void removeItem(int ItemID);
};
#endif

