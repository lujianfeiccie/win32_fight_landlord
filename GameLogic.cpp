#include "StdAfx.h"
#include "GameLogic.h"
#include<stdlib.h>
#include<time.h>
#include <string.h>
#define NUM_OF_A_TO_K 13
#define NUM_OF_PLAYER_CARDS 17
void initSrand()
{
	srand((int)time(0));
}
void initCard(const CARD_ENUM* card_char,int size_of_card_char,Card* cards,int numOfCards){
 
 for(int i=0;i<numOfCards-2;i++) //Initial the card without kings
 {
	 int index = i % NUM_OF_A_TO_K;
	 //printf("index = %d card_char = %d\n",index,card_char[index]);
	 cards[i].card = card_char[index];
	 cards[i].state = NotShuffle;
 }
 //Initial  the card with kings
 for(int i=numOfCards-2,j=size_of_card_char-2;
	 i<numOfCards;
	 i++,j++)
 {
   cards[i].card = card_char[j];
   cards[i].state = NotShuffle;
 }
}
void shuffle(Card* cards,const int size_of_cards,const CARD_ENUM* card_char,const int size_of_card_char){
 
 int pos;
 Card* tmp_cards = new Card[size_of_cards];

 for(int card=0;card<size_of_cards;card++){
	 tmp_cards[card].card = cards[card].card;
 }
 for(int card=0;card<size_of_cards;card++){
 
  do
  {
   pos = rand()%size_of_cards;
  }
  while(cards[pos].state!=NotShuffle); //find the blank index to fill in

  cards[pos].card= tmp_cards[card].card;
  cards[pos].state= IsShuffle;   
 }
 delete[] tmp_cards;
}
void showCards(const Card* cards,int start,int end)
{
 int a_count = 0;
 int count_j = 0;
 int count_q = 0;
 int count_k = 0;
 for(int i=start;i<=end;i++)
 {
	 switch(cards[i].card)
	 {
	 case CARD_3:
		 {
			 printf("3\t");
		 }
		 break;
	 case CARD_4:
		 {
			 printf("4\t");
		 }
		 break;
	 case CARD_5:
		 {
			 printf("5\t");
		 }
		 break;
	 case CARD_6:
		 {
			 printf("6\t");
		 }
		 break;
	 case CARD_7:
		 {
			 printf("7\t");
		 }
		 break;
	 case CARD_8:
		 {
			 printf("8\t");
		 }
		 break;
	 case CARD_9:
		 {
			 printf("9\t");
		 }
		 break;
	 case CARD_10:
		 {
			 printf("10\t");
		 }
		 break;
	 case CARD_J:
		 {
			 printf("J\t");
			 count_j++;
		 }
		 break;
	 case CARD_Q:
		 {
			 printf("Q\t");
			 count_q++;
		 }
		 break;
	 case CARD_K:
		 {
			 printf("K\t");
			 count_k++;
		 }
		 break;
	case CARD_A:
		{
			printf("A\t");
			a_count++;
		}
		 break;
	case CARD_2:
		{
			printf("2\t");
		}
		 break;
	 case CARD_SMALL_KING:
		 {
			 printf("SKing\t");
		 }
		 break;
	 case CARD_BIG_KING:
		 {
			 printf("BKing\t");
		 }
		 break;	
	 } 
 }
 
 printf("\n");

 //printf("a_count=%d,count_j=%d,count_q=%d,count_k=%d\n",a_count,count_j,count_q,count_k);
}
int getSize(int card)
{
	switch(card)
	{
	case CARD_3: 
	{
			return 1;
	}
	case CARD_4: 
	{
			return 2;
	}
	case CARD_5: 
	{
			return 3;
	}
	case CARD_6: 
	{
			return 4;
	}
	case CARD_7: 
	{
			return 5;
	}
	case CARD_8: 
	{
			return 6;
	}
	case CARD_9: 
	{
			return 7;
	}
	case CARD_10: 
	{
			return 8;
	}
	case CARD_J: 
	{
			return 9;
	}
	case CARD_Q: 
	{
			return 10;
	}
	case CARD_K: 
	{
			return 11;
	}
	case CARD_A: //A
	{
			return 12;
	}
	case CARD_2://2
	{
			return 13;
	}
	case CARD_SMALL_KING://Small King
	{
			return 14;		
	}
	case CARD_BIG_KING://Big King
	{
			return 15;
	}
  }
	return card;
}
void swap(Card* cards,int a,int b)
{
	CARD_ENUM tmp_card = cards[a].card;
	cards[a].card = cards[b].card;
	cards[b].card = tmp_card;
}
void sort(Card* cards,int start,int end)
{
  int i,j;
  int length = end - start+1;  
  printf("length=%d\n",length);
  for(i=0;i< length-1;i++)
  {
   for(j= length-2;j>=i;j--)
   {
	   //length-2 > length-1 (这里,length-1是边界)
    if( getSize(cards[j].card) > getSize(cards[j+1].card) )//前者大于后者
	{ 		
		 swap(cards,j,j+1); //两两交换
    }
   }
  }
}
void initCardHand(CardHand* carhand,int size,CardType cardType)
{
	for(int i=0;i<size;i++){
		carhand[i].index = -1;
		carhand[i].cardType = cardType;
		carhand[i].index_next= -1;
	}
}
//numOfCards: 连续张数
int contains(const CardHand* cardhand ,int numOfHands,int index)
{
	for(int i=0;i<numOfHands;i++)
	{
		for(int j=0;j<cardhand[i].length;j++){
			if(cardhand[i].index!=-1 && cardhand[i].index+j == index)//找到的情况下判断是否存在交集
			{
			//	printf("cardhand[%d].index=%d",i,cardhand[i].index);
				return i;
			}
		}
	}
	return -1;
}
void showNumOfLots(const Card* cards,int start,int end)
{
	//Two king
	CardHand twoKing;
	twoKing.cardType = KING_BLOW;
	twoKing.index = -1;

	//Four blow ( 5 at most )
	CardHand fourBlow[5];
	int sizeOfFourBlow = sizeof(fourBlow)/sizeof(CardHand);
	initCardHand(fourBlow,sizeOfFourBlow,FOUR_BLOW);

	//Three cards
	CardHand threeBlow[6];
	int sizeOfThreeBlow = sizeof(threeBlow)/sizeof(CardHand);
	initCardHand(threeBlow,sizeOfThreeBlow,THREE_CARDS);

	//Single flush
	/*CardHand singleFlush[4];
	int sizeOfThreeBlow = sizeof(threeBlow)/sizeof(CardHand);
	initCardHand(threeBlow,sizeOfThreeBlow,THREE_CARDS);*/

	for(int i=start;i<=end;)
	{
		//Two king
		if(i<end && cards[i].card == CARD_SMALL_KING && cards[i+1].card ==CARD_BIG_KING)
		{			
			twoKing.index  = i;
			twoKing.length = 2;
			i+=2;
		}
		//Four blow
		else if(i<= (end-3) && 
			cards[i  ].card == cards[i+1].card && 
			cards[i+1].card == cards[i+2].card &&
			cards[i+2].card == cards[i+3].card )
		{			
			for(int j = 0;j<sizeOfFourBlow;j++)
			{
				if(fourBlow[j].index == -1) //存放四炸
				{
					fourBlow[j].index = i;
					fourBlow[j].length = 4;
					break;
				}
			}
			i+=4;
			printf("i=%d\n",i);
		}
		//Three cards
		else if(i<= (end-2) && -1==contains(fourBlow,sizeOfFourBlow,i) &&
			cards[i  ].card == cards[i+1].card && 
			cards[i+1].card == cards[i+2].card)
		{			
			for(int j = 0;j<sizeOfThreeBlow;j++)
			{
				if(threeBlow[j].index == -1)
				{
					threeBlow[j].index = i;
					threeBlow[j].length =3;

					if(j>0 && getSize(cards[threeBlow[j-1].index].card) < getSize(CARD_SMALL_KING)) //排除大小王
					{
						int sizeBefore = getSize(cards[threeBlow[j-1].index].card);
						int sizeAfter  = getSize(cards[threeBlow[j].index].card);
						printf("sizeBefore=%d sizeAfter=%d\n",sizeBefore,sizeAfter);
						if( sizeBefore + 1 == sizeAfter )//上一个三条和这个三条可以构成三顺
						{
							threeBlow[j-1].index_next = threeBlow[j].index;//下一个索引指向这个三条的开始索引							
						}
					}
					break;
				}
			}//end of for
			i+=3;
		}
		//Single flush
		else
		{
		   i+=1;
		}
	} //End of for
	///////////////////////////////////////Show cards/////////////////////////////////////////////
	if(twoKing.index!=-1)
	{
		printf("----------------------------Two Kings-------------------------------------\n");
		showCards(cards,twoKing.index,twoKing.index + twoKing.length -1);
	}

	printf("----------------------------Four Blow-------------------------------------\n");
	for(int i =0; i <sizeOfFourBlow;i++)
	{
		if(fourBlow[i].index!=-1)
		{
			showCards(cards,fourBlow[i].index,fourBlow[i].index + fourBlow[i].length - 1);
		}
	}
		printf("-------------------------Three cards-------------------------------------\n");
	for(int i =0; i <sizeOfThreeBlow;)
	{
		if(threeBlow[i].index!=-1)
		{
			while(threeBlow[i].index_next!=-1)
			{
				showCards(cards,threeBlow[i].index,threeBlow[i].index + threeBlow[i].length - 1);
				++i;
			}		
			printf("--------------------------------------------------------------\n");
			showCards(cards,threeBlow[i].index,threeBlow[i].index + threeBlow[i].length - 1);
		}
	}
	
}

void showNumOfLots(const Card* cards,int player)
{
	int start = player * NUM_OF_PLAYER_CARDS;
	int end = start + NUM_OF_PLAYER_CARDS-1;
	showNumOfLots(cards,start,end);
}