#ifndef _GAME_H_
    #define _GAME_H_
#include "main.h"
class game{
private:
	int currLevel;
	bool running;
	player p1;
	map map1,level1,level2,level3,level4,level5;
	message currMessage;
	npc encounter[2];
public:
	game();
	void victory();
	void execute(); 
	void loadMaps();
	void changeLevel(int change);
	void pollEvent();
	void render();
	~game();
};
#endif