#include "main.h"
map::map(){
	file=NULL;
}
map::map(const map &copy){
	file=new char[strlen(copy.file)+1];
	strcpy(file,copy.file);
	readmap();
}
map::map(char *filename){
	file= new  char[strlen(filename)+1];
	strcpy(file,filename);
	readmap();
}
map& map::operator=(const map &copy){
	delete [] file;
	file=new char[strlen(copy.file)+1];
	strcpy(file,copy.file);
	for (int i=0; i<50;i++){
		for (int j=0; j<100;j++){
			mapc[i][j]=copy.mapc[i][j];
		}
	}
	return *this;
}
void map::readmap(){
	for (int i=0;i<50;i++){
		for(int j=0;j<100;j++){
			mapc[i][j]=NULL;
		}
	}
	ifstream ifs(file);
	for (int i=0; !ifs.eof();i++){
		ifs.getline(mapc[i],100);
		for (int j=0;j<100;j++){
			switch(mapc[i][j]){
			case 'E':
				enter1[0]=j;
				enter1[1]=i;
				break;
			case 'e':
				enter2[0]=j;
				enter2[1]=i;
				break;
			case 'X':
				exit1[0]=j;
				exit1[1]=i;
				break;
			case 'x':
				exit2[0]=j;
				exit2[1]=i;
				break;
			}
		}
	}

	ifs.close();
}
void map::visibleMap(int x, int y, bool torch){
	int left=x-3,right=x+3,top=y-2, bottom=y+2;
	if(torch){
		left=x-6;
		right=x+6;
		top=y-4;
		bottom=y+4;
	}
	if(left<0)
		left=0;
	if(top<0)
		top=0;
	for(int i=top;i<=bottom;i++){
		consoleMove(i,left);
		for (int j=left;j<=right;j++){
			consolePutC(mapc[i][j]);
		}
	}
}
void map::drawmap(){
	for(int i=0;mapc[i][0]!=NULL;i++){
		consoleMove(i,0);
		consolePutS(mapc[i]);
	}
}
int* map::getEntrance(int num){
	switch(num){
	case 1:
		return enter1;
		break;
	case 2:
		return enter2;
		break;
	case 3:
		return exit1;
		break;
	case 4:
		return exit2;
		break;
	}
}
int map::checkSpace(int y, int x){
	switch (mapc[y][x]){
	case ' ':
	case 'E':
	case 'e':
	case 'X':
	case 'x':
	case 'i':
	case 'S':
	case 'W':
		return mapc[y][x];
	}
	return -1;
}
void map::edit(int x, int y, char input){
	mapc[y][x]=input;
}
map::~map(){
	delete [] file;
}