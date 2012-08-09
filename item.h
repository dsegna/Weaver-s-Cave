#ifndef _ITEM_H_
    #define _ITEM_H_
#include "main.h"
class item{
private:
	char * name;
	int id;
public:
	item();
	item(int iNum);
	item & operator=(const item &copy);
	int getId();
	char * getName();
	~item();
};
#endif