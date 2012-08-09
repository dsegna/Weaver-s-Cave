#include "main.h"

player::player(){
	sprite='O';
	posx=5;
	posy=5;
	torch=false;
}
int player::getx(){
	return posx;
}
int player::gety(){
	return posy;
}
bool player::getTorch(){
	return torch;
}
void player::setStart(map inMap,int entrance){
	int *entr;
	entr=inMap.getEntrance(entrance);
	posx=entr[0];
	posy=entr[1];
}
void player::draw(){
	consoleMove(posy,posx);
	consolePutC(sprite);
	if (posy-5<0)
		consoleMove(0,0);
	else 
		consoleMove(posy+5,0);
}
int player::move(int x,int y, map map1){
	int valid;
	int newy=posy+y;
	int newx=posx+x;
	valid=map1.checkSpace(newy,newx);
	if(valid>=0 && valid!='S' && valid!='W'){
		consoleMove(posy,posx);
		consolePutC(' ');
		posx=newx;
		posy=newy;
	}
	return valid;
}
bool player::getItem(int itemId){
	char messageOut[50];
	bool done=false,got=false;
	for (int i=0;i<10 && !done;i++){
		if(inventory[i].getId()==0){
			item copy(itemId);
			inventory[i]=copy;
			sprintf(messageOut,"You got the %s!",inventory[i].getName());
			message mess(messageOut);
			mess.draw();
			done=true;
			got=true;
			if(itemId==1)
				torch=true;
		}
		else if(inventory[i].getId()==itemId){
			done=true;
		}
	}
	return got;
}
bool player::checkItems(int itemID){
	bool found=false;
	for (int i=0;i<10 && !found;i++){
		if(inventory[i].getId()==itemID)
			found=true;
	}
	return found;
}
void player::removeItem(int itemID){
	item copy;
	for (int i=0;i<10;i++){
		if(inventory[i].getId()==itemID){
			inventory[i]=copy;
		}
	}
}