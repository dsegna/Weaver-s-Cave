#include "main.h"
npc::npc(){
	resp=0;
}

void npc::selmys(){
	message msgOut;
	switch(resp){
	case 0:
		msgOut.set("Alas, you have found the good wizard JOHN SELMYS... Ask him for some    guidance. You never know, if he's in a good mood, and not marking any   LINUX assignments, he might actually help you!");
		break;
	case 1:
		msgOut.set("Be careful of the links associated  with stairways & bridges. They can  lead you to skewed and isolated     caverns if you're not careful...");
		break;
	case 2:
		msgOut.set("It is said that a particular        crystal's effect can momentarily    blind the wizard Weaver...");
		break;
	case 3:
		msgOut.set("If you can't find a particular item in a cavern, try looking again, and again, and again...");
		break;
	case 4:
		msgOut.set("Why are you going after Weaver      anyway? This wouldn't have anything to do with a particular C++ course  would it?");
		break;
	case 5:
		msgOut.set("What? More help? OK,OK... If you    manage to stun the wizard Weaver,   legend has it that a Jedi's weapon  can destroy him!");
		break;	
	}
	resp++;
	if(resp>5)
		resp=1;
	msgOut.draw();
}
int npc::weaver(player &p1){
	int i=0, inputMode=0, itemID=-1,offs=0;
	bool valid=false, combat=true;
	message msgOut;
	char input[20];
	if(resp<0){
		switch(resp){
		case -1:
			offs=1;
			break;
		case -2:
			offs=2;
			break;
		}
		int offs=1;
	}
	resp=0;
	while(combat){
	switch(resp){
	case 0:
		msgOut.set("Alas...Before you stands the image  of the wizard EVAN WEAVER! Be       careful of what actions you take,   for the wizard can (cast)(int *)    some very powerful  spells...");
		inputMode=1;
		break;
	case -1:
		msgOut.set("You Fool! You can't defeat the      wizard Weaver with that paultry     weapon... Weaver stuns you with an  overly complex and obfuscated       walkthrough. You fall to your knees and are transported to Lechuguilla's entrance...");
		break;
	case -3:
		msgOut.set("For annoying the wizard Weaver yet  again with your mediocre weapons, he fills all available memory on your terminal with a huge <vector>,      causing a segmentation fault which  sends you to an unknown cavern...");
		break;
	case -2:
		msgOut.set("You Fool!You can't defeat the wizard Weaver with that paultry weapon... Weaver hits you over the  head with a (* pointer)(to_a_function) and you again fall to your knees and are   transported to Lechuguilla's        entrance...");
		break;
	case -4:
		msgOut.set("Impressive...Very impressive...So   young jedi, I see that the wizard   Selmys has taught you well! But     never underestimate the power of the Dark-Side...Weaver confuses you    with a circular linked list embedded in a <template>, and transports    your Light Saber to an unknown      cavern within Lechuguilla...");
		break;
	case 1:
		msgOut.set("Alas! You have blinded the wizard   Weaver with the TRI-LITHIUM crystal! Now, what will you do?");
		inputMode=1;
		break;
	case 2:
		return resp;
	}
	msgOut.draw();
	if(inputMode==1){
		msgOut.set("What weapon will you use? Or will   you just run?");	
		valid=false;
		while(!valid){
			msgOut.draw(1);
			i=0;
			do{
				input[i]=consoleGetKey();
				consolePutC(input[i]);
			}
			while(input[i++]!=ENTER && i<19);
			input[i-1]='\0';
			if(strcmp(input,"torch")==0)
				itemID=1;
			else if(strcmp(input,"poison")==0)
				itemID=2;
			else if(strcmp(input,"sword")==0)
				itemID=3;
			else if(strcmp(input,"tri-lithium")==0)
				itemID=4;
			else if(strcmp(input,"lightsaber")==0)
				itemID=5;
			else if(strcmp(input,"run")==0){
				valid=true;
				inputMode=0;
				combat=false;
			}
			if(p1.checkItems(itemID)){
				valid=true;
				if (itemID<4 && resp>(-3))
					resp=resp-1-offs;
				else if (itemID<4 && resp==1)
					resp=resp-2-offs;
				else if (itemID==4)
					resp=1;
				else if (itemID==5 && resp!=1)
					resp=-4;
				else if (itemID==5 && resp==1)
					resp=2;
			}
			if(resp<0)
				inputMode=0;
		}
	}
	else 
		combat=false;
	}
	return resp;
}