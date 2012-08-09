#include "main.h"
item::item(){
	name=new char[1];
	strcpy(name,"");
	id=0;
}
item::item(int iNum){
	char temp[20];
	id=iNum;
	switch(id){
	case 1:
		strcpy(temp,"Torch");
		break;
	case 2:
		strcpy(temp,"Poison");
		break;
	case 3:
		strcpy(temp,"Sword");
		break;
	case 4:
		strcpy(temp,"Tri-Lithium");
		break;
	case 5:
		strcpy(temp,"Lightsaber");
		break;
	}
	name= new char[strlen(temp)+1];
	strcpy(name,temp);
}
item & item::operator=(const item &copy){
	if(name)
		delete [] name;
	name= new char[strlen(copy.name)+1];
	strcpy(name,copy.name);
	id=copy.id;
	return *this;
}
int item::getId(){
	return id;
}
char* item::getName(){
	return  name;
}
item::~item(){
	delete [] name;
}