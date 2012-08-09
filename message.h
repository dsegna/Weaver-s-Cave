#ifndef _MESSAGE_H_
    #define _MESSAGE_H_
#include "main.h"
class message{
private:
	char *str;
public:
	message();
	message(char *in);
	message & operator=(const message &copy);
	void draw(int inputmode=0);
	void set(char * in);
	~message();
};
#endif