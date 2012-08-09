#ifndef _MAP_H_
    #define _MAP_H_
#include "main.h"
class map{
private:
	char mapc[50][100];
	char *file;
	int enter1[2],enter2[2],exit1[2],exit2[2];
public:
	map();
	map(const map &copy);
	map(char *filename);
	map & operator=(const map &copy);
	void readmap();
	void visibleMap(int x, int y, bool torch);
	void drawmap();
	int* getEntrance(int num=1);
	int checkSpace(int y, int x);
	void edit(int x, int y, char input);
	~map();
};

#endif
