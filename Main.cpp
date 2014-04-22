// FightLandlord.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "GameLogic.h"
#define NUM_OF_CARDS 54 //Except for two Kings

int _tmain(int argc, _TCHAR* argv[])
{
	CARD_ENUM card_values[]={
		CARD_3, //0
		CARD_4, //1
		CARD_5, //2
		CARD_6, //3
		CARD_7, //4
		CARD_8, //5
		CARD_9, //6
		CARD_10,//7
		CARD_J, //8
		CARD_Q, //9
		CARD_K, //10
		CARD_A, //11
		CARD_2, //12
		CARD_SMALL_KING,
		CARD_BIG_KING
	};
	Card cards[NUM_OF_CARDS];
	int size_of_card_values = sizeof(card_values)/sizeof(int);

	initSrand();

	initCard(card_values,size_of_card_values,cards,NUM_OF_CARDS);
	//printf("%c",card_char[0]);
	showCards(cards,0,NUM_OF_CARDS-1);
	printf("After shuffle:\n");

	shuffle(cards,
		NUM_OF_CARDS,
		card_values,
		size_of_card_values);

	showCards(cards,0,NUM_OF_CARDS-1);

	printf("My cards:\n");
	//showCards(cards,0,NUM_OF_CARDS-1);
	sort(cards,0,NUM_OF_CARDS-1);
	printf("After sorted ! My cards:\n");
	showCards(cards,0,NUM_OF_CARDS-1);
	printf("My cards type:\n");
	showNumOfLots(cards,0,NUM_OF_CARDS-1);
	return 0;
}

