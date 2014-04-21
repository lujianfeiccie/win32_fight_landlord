#include "StdAfx.h"
#include "GameLogic.h"
#include<stdlib.h>
#include<time.h>
#include <string.h>
void initSrand()
{
	srand((int)time(0));
}
void initCard(const char* card_char,int size_of_card_char,Card* cards,int numOfCards){
 
 for(int i=0;i<numOfCards;i++)
 {
  cards[i].card = NOT_FILL;
 }
}
void shuffle(Card* cards,const int size_of_cards,const char* card_char,const int size_of_card_char){
 
 int pos;
 
 for(int card=0;card<size_of_cards;card++){
  do{
   pos = rand()%size_of_cards;
  }while(cards[pos].card!=NOT_FILL); //find the blank index to fill in
  cards[pos].card= card_char[card % size_of_card_char];
  switch(card/size_of_card_char){
  case 0:
   cards[pos].flag = BLACK;
   break;
  case 1:
   cards[pos].flag = RED;
   break;
  case 2:
   cards[pos].flag = PLUM;
   break;
  case 3:
   cards[pos].flag = SQUARE;
   break;
  }
 
 }
}
void showCards(const Card* cards,int start,int end){
 
 for(int i=start;i<=end;i++)
 {
  if(cards[i].card=='0')
  {
   printf("10\t");
  }else{
   printf("%c\t",cards[i].card);
  }
 }
 printf("\n");
}
void showPlayerCards(const Card* cards,int player,int numOfPlayers)
{
 int start = player*5;
 int end = start + 4;
 if(player<numOfPlayers-1){
  printf("���%d\t:",player);
 }else{
  printf("�Լ�\t:");
 }
 showCards(cards,start,end);
}
int getCardSize(char c)
{
 if(c == 'A')
 {
  return 1;
 }
 if(c>='2' && c <='9')
 {
  return c-48;
 }
 if(c == '0')
 {
  return 10;
 }
 if(c == 'J' || c == 'Q' || c == 'K')
 {
  return 10;
 }
}
Result getResult(int card1,int card2,int card3,int player,const Card* cards)
{
 if(card1 == -1 || card2 ==-1 || card3 ==-1){
  return NO_GOOD;
 }
 int firstThree=0,lastTwo=0;
 int start = player*5;
 int end = start + 4;
 
 ///////////////////��Сţ//////////////////
 ///ÿ����С���壬����С��10
 int small_cow = 1;
 int small_cow_count = 0;
 for(int i=start;i<=end;i++){
  int size = getCardSize(cards[i].card);
  if(size >=5){
   small_cow = 0;
  }
  small_cow_count +=size;
 }
 if(small_cow ==1 && small_cow_count<=10)
 {
  return FIVE_SMALL;
 }
 ///////////////////end ��Сţ//////////////////
 //////////////////�廨ţ///////////////////
 /////���Ŷ��ǻ���
 int five_cow = 1;
 for(int i=start;i<=end;i++){
  if(cards[i].card != 'J' &&
     cards[i].card != 'Q' &&
     cards[i].card != 'K')
  {
   five_cow = 0;
  }
 }
 if(five_cow ==1){
  return FIVE_FLOWER;
 }
 ////////////////////��ը///////////////////
 //////����һ������
 int same_count = 0;
 for(int i=start;i<=end;i++)
 {
  same_count = 0;
  for(int j=start;j<=end;j++)
  {
   if(cards[i].card == cards[j].card){
    ++same_count;
   }
  }
  if(same_count>=4){
   return FORTH_BLOW;
  }
 }
 ////////////////////END��ը//////////////
 for(int i=start;i<=end;i++){
  if(i==start+card1 || i==start+card2 || i==start+card3){
   firstThree += getCardSize(cards[i].card);
  }else{
   lastTwo += getCardSize(cards[i].card);
  }
 }
 //printf("\nǰ����֮��=%d, ������֮��=%d\n",firstThree,lastTwo);
 if( firstThree % 10 ==0 ) //ǰ����֮����ʮ��������
 {
  if(lastTwo % 10 ==0){ //������֮����Ҳ��ʮ��������=ţţ
   return NN;
  }
  if(lastTwo>10){//������֮�ʹ���10,��ȡ��λ��
   lastTwo = lastTwo % 10;
   //printf("1digit:%d\n",lastTwo);
  }
  switch(lastTwo){ //�ж���ţ��
  case 1:
   return ND;
  case 2:
   return N2;
  case 3:
   return N3;
  case 4:
   return N4;
  case 5:
   return N5;
  case 6:
   return N6;
  case 7:
   return N7;
  case 8:
   return N8;
  case 9:
   return N9;
  }
 }
 return NO_GOOD;
}
void showResult(Result result)
{
 switch(result){
 case NO_GOOD:
  printf("ûţ\n");
  break;
 case ND:
  printf("ţ��\n");
  break;
 case N2:
  printf("ţ��\n");
  break;
 case N3:
  printf("ţ��\n");
  break;
 case N4:
  printf("ţ��\n");
  break;
 case N5:
  printf("ţ��\n");
  break;
 case N6:
  printf("ţ��\n");
  break;
 case N7:
  printf("ţ��\n");
  break;
 case N8:
  printf("ţ��\n");
  break;
 case N9:
  printf("ţ��\n");
  break;
 case NN:
  printf("ţţ\n");
  break;
 case FORTH_BLOW:
  printf("��ը\n");
  break;
 case FIVE_FLOWER:
  printf("�廨ţ\n");
  break;
 case FIVE_SMALL:
  printf("��Сţ\n");
  break;
 }
}
Result getAIResult(int player,const Card* cards)
{
 int start= player * 5;
 int end = start+4;
 int count = 0;
 int firstThreeSum = 0;
 //C(5,3)���Ѱ��ǰ������֮��Ϊ10��������
 for(int card1 = start;card1<=end;card1++)
 {
  for(int card2 = card1+1;card2<=end;card2++)
  {
     if(card2 == card1) continue;
   for(int card3 = card2+1;card3<=end;card3++)
   {
    if(card3 == card2 || card2 == card1) continue;
    int sizeOfCard1 = getCardSize(cards[card1].card);
    int sizeOfCard2 = getCardSize(cards[card2].card);
    int sizeOfCard3 = getCardSize(cards[card3].card);
    firstThreeSum = sizeOfCard1 + sizeOfCard2 + sizeOfCard3;
    //printf("%d+%d+%d=%d\n",sizeOfCard1,sizeOfCard2,sizeOfCard3,firstThreeSum);
   
    if(firstThreeSum % 10 == 0){
     return getResult(card1,card2,card3,player,cards);
    }
    ++count;
   }
  }
 }
 //printf("count=%d\n",count);
 return NO_GOOD;
}
int getPoint(Result result)
{
  //�ο�ţţ��Ϸ�Ĺ���
  switch(result)
  {
  //��Сţ���廨ţ��Ӯ5��
  case FIVE_SMALL:
  case FIVE_FLOWER:{
   return 5;
  }
  //��ը��Ӯ4��
  case FORTH_BLOW:{
   return 4;
  }
  case NN:{
   return 3;
  }
  //ţ��ţ����Ӯ2��
  case N9:
  case N8:{
   return 2;
  }
  //������Ӯ1��
  case N7:
  case N6:
  case N5:
  case N4:
  case N3:
  case N2:
  case ND:
  case NO_GOOD:{
   return 1;
  }
 }
 return 0;
}
int compare(Result result1,Result result2)
{
 return result2 - result1;
}

int getDealer(const int numOfPlayers){
  int dealer = rand() % numOfPlayers;
  return dealer;
}
void showDealer(const int dealer,int numOfPlayers)
{
 if(dealer!=numOfPlayers-1){
  printf("ׯ��:���%d",dealer);
 }else{
  printf("ׯ��:�Լ�");
 }
 printf("\n");
}

void showScore(Player *player,const int num,const int dealer)
{
 Result result_dealer = player[dealer].result;
 
 int other_player_score_count = 0;//���ڼ����мҵ���Ӯ���
 int* score = new int[num];
 memset(score,0,sizeof(int)*num);

 for(int i=0;i<num;i++)
 {
  if(dealer==i) continue;

  if(compare(player[i].result,result_dealer) > 0 )//�мұ�ׯ�Ҵ�
  {
	//�м�ӮǮ
	  score[i] = getPoint(player[i].result);
  }
  else//�м�С�ڻ����ׯ��
  {
	//�м���Ǯ
	  score[i] = (-1) * getPoint(player[i].result);
  }
  player[i].score += score[i];
  other_player_score_count += score[i];
 }
 
  score[dealer]  += (-1)*other_player_score_count;
  player[dealer].score += score[dealer];
  for(int i=0;i<num;i++)
  {
	 if(i<num-1)
	 {
		 printf("���%d\t����:%d\t�ܷ�:%d",player[i].player,score[i],player[i].score);
	 }
	 else
	 {
		 printf("�Լ�\t����:%d\t����:%d",score[i],player[i].score);
	 }
	 printf("\n");
  }
}