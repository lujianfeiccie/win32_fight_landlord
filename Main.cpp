// FightLandlord.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "GameLogic.h"
#define NUM_OF_CARDS 54 //Except for two Kings

int _tmain(int argc, _TCHAR* argv[])
{
	char card_char[]={'A1','2','3','4','5','6','7','8','9','10','J','Q','K','BK','SK'};
	Card cards[NUM_OF_CARDS];
	//initCard(card_char,sizeof(card_char)/sizeof(char),cards,NUM_OF_CARDS);
	printf("%c",card_char[0]);
	return 0;
}

