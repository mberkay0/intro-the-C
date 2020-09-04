#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
//kaplumbaða ve tavþan yariþi için bahis programi :))
void moveTurtle(int *turtptr);
void moveRabbit(int *rabptr);
void print(int *snapper,int*bunny);

int main() {
	int turtle = 1;
	int bugsy = 1;
	int timer = 0;
	int bahis,yarismaci,secim;
	
	srand(time(NULL));
	while(secim != 2) {
		printf("Bahisi yatirmak istediginiz yarismaciyi seciniz:Tavsan(1)/Kaplumbaga(2)\n");
		printf("Tavsan bahis orani * 2 / Kaplumbaga bahis orani * 3\n");
		scanf("%d",&yarismaci);
		printf("Bahis miktarini belirleyiniz:");
		scanf("%d",&bahis);
		printf("\tHerkes Hazir!!!\n\tVe Iste Basladilar...\n");
		printf("\tBANG!\n");
		while(turtle != 70 && bugsy != 70) {
			moveTurtle(&turtle);
			moveRabbit(&bugsy);
			print(&turtle,&bugsy);
			++timer;
		}
		if(turtle >= bugsy) 
			printf("\nKaplumbaga Kazandi!!YAY!!\n");
		else
			printf("\nTavsan Kazandi!!YAY!!\n");
		printf("Gecen sure : %d",timer);
		switch(yarismaci) {
			case 1:
				if(turtle >= bugsy) {
					printf("\nBahsi kaybettiniz tekrar deneyin..\n");
					bahis = 0;
					printf("\nKazandiginiz tutar : %d\n",bahis);
				}
				else {
					printf("\nBahsi kazandiniz..\n");
					bahis = bahis * 2;
					printf("\nKazandiginiz tutar : %d\n",bahis); 
				}	
					
				break;
			case 2:
				if(bugsy >= turtle) {
					printf("\nBahsi kaybettiniz tekrar deneyin..\n");
					bahis = 0;
					printf("\nKazandiginiz tutar : %d\n",bahis);
				}
				else {
					printf("\nBahsi kazandiniz..\n");
					bahis = bahis * 3;
					printf("\nKazandiginiz tutar : %d\n",bahis); 
				}	
				
				break;
		}
		printf("\nTekrar oynamak ister misiniz ?E(1)/H(2)");
		scanf("%d",&secim);
		if(secim == 1) {
			turtle = 1;
			bugsy = 1;
			timer =  0;
		}
	}
	getch();	
	return 0;
}

void moveTurtle(int *turtptr) {
	int x;
	x = rand()%10 + 1;
	if(x >= 1 && x <= 5)		//hýzlý gitme;
		*turtptr += 3;
	else if(x == 6 || x == 7)	//uyuma;
		*turtptr -= 6;
	else						//yavaþ gitme;
		++( *turtptr);
	if(*turtptr < 1)
		*turtptr = 1;
	if(*turtptr > 70)
		*turtptr = 70;
}

void moveRabbit(int *rabptr) {
	int y;
	y = rand()%10 + 1;
	if(y == 3 || y == 4)		//büyük zýplama;
		*rabptr += 9;
	else if(y == 5)				//uyuma;
		*rabptr -= 12;
	else if(y >= 6 && y <= 8)	//yavaþ hop;
		++( *rabptr);
	else if(y == 10)
		*rabptr -= 2;
	if(*rabptr < 1)
		*rabptr = 1;
	if(*rabptr > 70)
		*rabptr = 70;
}

void print(int *snapper,int *bunny) {
	int count;
	for(count = 1;count <= 70;count++)
		if(count == *snapper && count == *bunny)
			printf("**OUCH**");
		else if(count == *bunny)
			printf("T");
		else if(count == *snapper)
			printf("K");
		else
			printf(" ");
		printf("\n");	
}















