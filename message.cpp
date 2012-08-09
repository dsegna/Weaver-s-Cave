#include "main.h"
message::message(){
	str=NULL;
}
message::message(char *in){
	str= new char[strlen(in)+1];
	strcpy(str,in);
}
message & message::operator=(const message &copy){
	str= new char[strlen(copy.str)+1];
	strcpy(str,copy.str);
	return *this;
}
void message::draw(int inputMode){
	int stringLen=strlen(str), lines=stringLen/36;
	int ypos= 5 ,xpos= (consoleGetCols() / 2)-20, strpos=0;
	char input=NULL;
	consoleClear();
	consoleMove(ypos,xpos);
	consolePutS("##########################################");
	consoleMove(++ypos,xpos);
	consolePutS("#                                        #");
	for(int i=0;i<lines+1;i++){
		consoleMove(++ypos,xpos);
		consolePutS("#  ");
		for(int j=0;j<36;j++){
			if(strpos<stringLen)
				consolePutC(*(str+(strpos++)));
			else
				consolePutC(' ');
		}
		consolePutS("  #");
	}
	consoleMove(++ypos,xpos);
	consolePutS("#                                        #");
	consoleMove(++ypos,xpos);
	consolePutS("##########################################");
	consoleMove(++ypos,xpos);
	if (inputMode==1)
		consolePutS("->");
	else{
		while(input != ENTER)
			input=consoleGetKey();
	}
}
void message::set(char *in){
	delete [] str;
	str= new char[strlen(in) +1];
	strcpy(str,in);
}
message::~message(){
	delete [] str;
}