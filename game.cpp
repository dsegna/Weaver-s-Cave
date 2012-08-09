#include "main.h"
game::game(){
	consoleOn();
	loadMaps();
	map1=level1;
	running=true;
	currLevel=1;
}
void game::execute(){
	message messageCopy("You are in a dark cavern with only  flickering crystals to guide your   path. A familliar yet haunting voice summons you forward from 2 levels  above.");
	currMessage=messageCopy;
	consoleClear();
	p1.setStart(map1);
	currMessage.draw();
	while(running){
		render();
		pollEvent();
		
		Sleep(1);
	}
}
void game::pollEvent(){
	int input,res,random,random2;
	int validinput=-1;
	srand(time(NULL));
	while(validinput==-1){
		input=consoleGetKey();
		switch(input){
		case LEFT:
			validinput=p1.move(-1,0,map1);
			break;
		case RIGHT:
			validinput=p1.move(1,0,map1);
			break;
		case UP:
			validinput=p1.move(0,-1,map1);
			break;
		case DOWN:
			validinput=p1.move(0,1,map1);
			break;
		case END:
		case ESC:
			running=false;
			validinput=0;
			break;
		}
	}
	if (validinput != ' '){
		switch(validinput){
		case 'x':
		case 'X':
			changeLevel(1);
			if (validinput=='X')
				p1.setStart(map1);
			else if (validinput=='x')
				p1.setStart(map1,2);	
			break;
		case 'e':
		case 'E':
			if (currLevel>1){
				changeLevel(-1);
				if (validinput=='E')
				{	p1.setStart(map1,3);	}
				else if (validinput=='e')
				{	p1.setStart(map1,4);	}	
			}
			break;
		case 'i':
			if(p1.getItem(currLevel))
			{	map1.edit(p1.getx(),p1.gety(),' ');		}
			break;
		case 'S':
			encounter[0].selmys();
			break;
		case 'W':
			res=encounter[1].weaver(p1);
			switch(res){
			case -1:
			case -2:
				changeLevel(-4);
				p1.setStart(map1);
				break;
			case -3:
				random=rand() % 4 + 2;
				changeLevel(3-random);
				srand(time(NULL));
				if(random==2 || random == 3)
					random2=rand() % 3 + 1;
				else
					random2=rand() % 2 +1;
				p1.setStart(map1,random2);
				break;
			case -4:
				p1.removeItem(5);
				level5.readmap();
				break;
			case 2:
				victory();
				break;
			}
			break;
		}
	}
}
void game::loadMaps(){
	map copyMap1("level1.txt"),copyMap2("level2.txt"),copyMap3("level3.txt"),copyMap4("level4.txt"),copyMap5("level5.txt");
	level1=copyMap1;
	level2=copyMap2;
	level3=copyMap3;
	level4=copyMap4;
	level5=copyMap5;
}
void game::changeLevel(int change){
	if(change==0)
		return;
	switch (currLevel){
	case 1:
		level1=map1;
		break;
	case 2:
		level2=map1;
		break;
	case 3:
		level3=map1;
		break;
	case 4:
		level4=map1;
		break;
	case 5:
		level5=map1;
		break;
	}
	currLevel=currLevel+change;
	if (currLevel<1)
	{	currLevel=1;	}
	switch (currLevel){
	case 1:
		map1=level1;
		break;
	case 2:
		map1=level2;
		break;
	case 3:
		map1=level3;
		break;
	case 4:
		map1=level4;
		break;
	case 5:
		map1=level5;
		break;
	}
}
void game::render(){
	consoleClear();
	map1.visibleMap(p1.getx(),p1.gety(), p1.getTorch());
	p1.draw();
}
void game::victory(){
	message msgOut("Congratulations! You have defeated  the wizard Weaver! You will go down in OOP history, and C++ students    everywhere will rejoice in your     name!");
	msgOut.draw();
	running=false;
}
game::~game(){
	consoleOff();
}