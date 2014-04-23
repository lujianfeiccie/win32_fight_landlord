#pragma once


typedef enum 
{
	CARD_A,
	CARD_2,
	CARD_3,
	CARD_4,
	CARD_5,
	CARD_6,
	CARD_7,
	CARD_8,
	CARD_9,
	CARD_10,
	CARD_J,
	CARD_Q,
	CARD_K,
	CARD_SMALL_KING,
	CARD_BIG_KING,
}CARD_ENUM;

enum ShuffleState
{
	IsShuffle,
	NotShuffle
};

typedef enum 
{
	KING_BLOW,
	FOUR_BLOW,
	THREE_CARDS,
	THREE_CARDS_SORT,
}CardType;


struct CardHand
{
  CardType cardType;
  int index;
  int length;
  int index_next;
};
struct Card{
 CARD_ENUM card;
 ShuffleState state;
};
void initSrand();
void initCard(const CARD_ENUM* card_char,int size_of_card_char,Card* cards,int numOfCards);
void shuffle(Card* cards,const int size_of_cards,const CARD_ENUM* card_char,const int size_of_card_char);
int getSize(int card);
void sort(Card* cards,int start,int end);
void showCards(const Card* cards,int start,int end);
void showNumOfLots(const Card* cards,int start,int end);
void showNumOfLots(const Card* cards,int player);