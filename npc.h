#ifndef _NPC_H_
    #define _NPC_H_
#include "main.h"
class npc{
private:
	int resp;
public:
	npc();

	void interact(player &p1);
	void selmys();
	int weaver(player &p1);
};
#endif