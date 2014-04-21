#pragma once

#define NOT_FILL 'N'

enum Result{
 FIVE_SMALL,
 FIVE_FLOWER,
 FORTH_BLOW,
 NN,
 N9,
 N8,
 N7,
 N6,
 N5,
 N4,
 N3,
 N2,
 ND,
 NO_GOOD,
};
enum Flag
{
 BLACK,
 RED,
 PLUM,
 SQUARE
};
struct Card{
 char card;
 Flag flag;
};
struct Player{
 int player;
 int score;
 Result result;
};
void initSrand();
void initCard(const char* card_char,int size_of_card_char,Card* cards,int numOfCards);
void shuffle(Card* cards,const int size_of_cards,const char* card_char,const int size_of_card_char);
void showCards(const Card* cards,int start,int end);
void showPlayerCards(const Card* cards,int player,int numOfPlayers);
int getCardSize(char c);
Result getResult(int card1,int card2,int card3,int player,const Card* cards);
void showResult(Result result);
Result getAIResult(int player,const Card* cards);
int getPoint(Result result);
int compare(Result result1,Result result2);
int getDealer(const int numOfPlayers);
void showDealer(const int dealer,int numOfPlayers);
void showScore(Player *player,const int num,const int dealer);