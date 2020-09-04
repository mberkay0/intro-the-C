#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define ENTER 13
#define PAUSE 112
#define EXIT 27


char name[2][30];
char xox[3][3];
int ex;

void gotoxy(short x,short y) { 
	COORD pos = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);	
}


char waitForAnyKey(void) {
	int pressed;
	
	while(!kbhit());
	pressed = getch();
	
	return((char)pressed);
}


void showframe(int,int);
int youWinScreen(void);
void pauseMenu(void);
void move(void);
void enterbox(int,int,int);
void winner(char[][3]);
void check(char a);
void names();

int main() {
	printf("\t\t\tTIC TAC TOE\n\t\t\t");
	for(int i=0;i<11;i++) printf("%c",223);
	printf("\n\n  Oyun 2 kisiliktir ve ENTER tusu ile oynanir\n sirasi gelen oyuncu ENTER tusuna basip X ya da O harflerini istedigi kutuya yerlestirir.");
	printf("\n\n\n\tHerhangi bir tusa basiniz...\n");
	waitForAnyKey();
	system("cls");
	names();
	system("cls");
	showframe(24,15);
	move();
	
	getch();
	return 0;
}


void names() {
	printf("\nPlayer 1, lutfen isminizi giriniz:"); fgets(name[0], 30, stdin);
    printf("\nPlayer 2, lutfen isminizi giriniz:"); fgets(name[1], 30, stdin);
	printf("\n%s, X'i sen aldin.\n",name[0]);
	printf("\n%s, O'yu sen aldin.\n",name[1]);
    
}


//kutularý gösterme;
void showframe(int posx, int posy) {
	int p;
	int hr = 196,vr = 179;     //196,179,197
	int crossbr = 197;    
	int x = posx,y = posy;
	int i,j;

	printf("\t\t\tTIC TAC TOE\n\t\t\t");
	for(int i=0;i<11;i++) printf("%c",223);
	printf("\n\n\n\n\n\t\t");


	for(i=0;i<2;i++) {   
		for(j=1;j<=6;j++) {
			gotoxy(x,y);
			printf("%c",hr);
			x++;p;    x++;
		}
		x=posx; y+=2;
	}
	x=posx+3; y=posy-1;

	for(i=0;i<2;i++) {   
		for(j=1;j<=5;j++) {
			gotoxy(x,y);
			printf("%c",vr);
			y++;
		}
		x+=4;y=posy-1;
	}


	x=posx+3; y=posy;  
	gotoxy(x,y);
	printf("%c",crossbr);

	x=posx+7; y=posy;      
	gotoxy(x,y);
	printf("%c",crossbr);

	x=posx+3; y=posy+2;                    
	gotoxy(x,y);
	printf("%c",crossbr);

	x=posx+7; y=posy+2;         
	gotoxy(x,y);
	printf("%c",crossbr);

}
      

//x o x yer slotu;
void move(void) {
	int dirx=26,diry=16,sayac=2,secim;
	char dir;
	ex = 1;
	while(ex != 0) {
		switch(dir = getch()) {
			case UP:
				diry -= 2;
				gotoxy(dirx,diry);	
				break;
			case DOWN:
				diry += 2;	
				gotoxy(dirx,diry);
				break;
			case LEFT:
				dirx -= 3;
				gotoxy(dirx,diry);				
				break;			
			case RIGHT:
				dirx += 3;
				gotoxy(dirx,diry);
				break;
			case ENTER:
				if(sayac % 2 == 0) {
					enterbox(dirx,diry,0);
					winner(xox);
				}
				else {
					enterbox(dirx,diry,1);
					winner(xox);
				}
				sayac++;
				break;	
			case PAUSE:
				pauseMenu();
				break;
			case EXIT:
				pauseMenu();
				break;
			default :
				break;
		}
	}
	printf("\n\n\n\n\n\n\t\t\t\tTekrar bekleriz...");
}



void enterbox(int xe,int ye,int players) {
	
	if(players == 0) {
		if(xe == 26 && ye == 14) {
			if(xox[0][0] == 'x' || xox[0][0] == 'o') {
				gotoxy(28,23);
				printf("Dolu kutuyu sectiniz...Tekrar deneyin");
				waitForAnyKey();
				gotoxy(28,23);
				printf("                                     ");
			}
			else {
				xox[0][0] = 'x';
				printf("%c",xox[0][0]);
			}
		}
			
		if(xe == 29 && ye == 14) {
			if(xox[0][1] == 'x' || xox[0][1] == 'o') {
				gotoxy(28,23);
				printf("Dolu kutuyu sectiniz...Tekrar deneyin");
				waitForAnyKey();
				gotoxy(28,23);
				printf("                                     ");
			}
			else {
				xox[0][1] = 'x';
				printf("%c",xox[0][1]);
			}
		}

		if(xe == 32 && ye == 14) {
			if(xox[0][2] == 'x' || xox[0][2] == 'o') {
				gotoxy(28,23);
				printf("Dolu kutuyu sectiniz...Tekrar deneyin");
				waitForAnyKey();
				gotoxy(28,23);
				printf("                                     ");
			}
			else {
				xox[0][2] = 'x';
				printf("%c",xox[0][2]);
			}
		}
		
		if(xe == 26 && ye == 16) {
			if(xox[1][0] == 'x' || xox[1][0] == 'o') {
				gotoxy(28,23);
				printf("Dolu kutuyu sectiniz...Tekrar deneyin");
				waitForAnyKey();
				gotoxy(28,23);
				printf("                                     ");
			}
			else {
				xox[1][0] = 'x';
				printf("%c",xox[1][0]);
			}
		}
		
		if(xe == 29 && ye == 16) {
			if(xox[1][1] == 'x' || xox[1][1] == 'o') {
				gotoxy(28,23);
				printf("Dolu kutuyu sectiniz...Tekrar deneyin");
				waitForAnyKey();
				gotoxy(28,23);
				printf("                                     ");
			}
			else {
				xox[1][1] = 'x';
				printf("%c",xox[1][1]);
			}
		}
		
		if(xe == 32 && ye == 16) {
			if(xox[1][2] == 'x' || xox[1][2] == 'o') {
				gotoxy(28,23);
				printf("Dolu kutuyu sectiniz...Tekrar deneyin");
				waitForAnyKey();
				gotoxy(28,23);
				printf("                                     ");
			}
			else {
				xox[1][2] = 'x';
				printf("%c",xox[1][2]);
			}
		}
		
		if(xe == 26 && ye == 18) {
			if(xox[2][0] == 'x' || xox[2][0] == 'o') {
				gotoxy(28,23);
				printf("Dolu kutuyu sectiniz...Tekrar deneyin");
				waitForAnyKey();
				gotoxy(28,23);
				printf("                                     ");
			}	
			else {
				xox[2][0] = 'x';
				printf("%c",xox[2][0]);
			}
		}
		
		if(xe == 29 && ye == 18) {
			if(xox[2][1] == 'x' || xox[2][1] == 'o') {
				gotoxy(28,23);
				printf("Dolu kutuyu sectiniz...Tekrar deneyin");
				waitForAnyKey();
				gotoxy(28,23);
				printf("                                     ");
			}
			else {	
				xox[2][1] = 'x';
				printf("%c",xox[2][1]);
			}
		}
	
		if(xe == 32 && ye == 18) {
			if(xox[2][2] == 'x' || xox[2][2] == 'o') {
				gotoxy(28,23);
				printf("Dolu kutuyu sectiniz...Tekrar deneyin");
				waitForAnyKey();
				gotoxy(28,23);
				printf("                                     ");
			}
			else {
				xox[2][2] = 'x';
				printf("%c",xox[2][2]);
			}
		}
	}
	else if(players == 1) {
		if(xe == 26 && ye == 14) {
			if(xox[0][0] == 'x' || xox[0][0] == 'o') {
				gotoxy(28,23);
				printf("Dolu kutuyu sectiniz...Tekrar deneyin");
				waitForAnyKey();
				gotoxy(28,23);
				printf("                                     ");
			}
			else {
				xox[0][0] = 'o';
				printf("%c",xox[0][0]);
			}
		}
			
		if(xe == 29 && ye == 14) {
			if(xox[0][1] == 'x' || xox[0][1] == 'o') {
				gotoxy(28,23);
				printf("Dolu kutuyu sectiniz...Tekrar deneyin");
				waitForAnyKey();
				gotoxy(28,23);
				printf("                                     ");
			}
			else {
				xox[0][1] = 'o';
				printf("%c",xox[0][1]);
			}
		}

		if(xe == 32 && ye == 14) {
			if(xox[0][2] == 'x' || xox[0][2] == 'o') {
				gotoxy(28,23);
				printf("Dolu kutuyu sectiniz...Tekrar deneyin");
				waitForAnyKey();
				gotoxy(28,23);
				printf("                                     ");
			}
			else {
				xox[0][2] = 'o';
				printf("%c",xox[0][2]);
			}
		}
		
		if(xe == 26 && ye == 16) {
			if(xox[1][0] == 'x' || xox[1][0] == 'o') {
				gotoxy(28,23);
				printf("Dolu kutuyu sectiniz...Tekrar deneyin");
				waitForAnyKey();
				gotoxy(28,23);
				printf("                                     ");
			}
			else {
				xox[1][0] = 'o';
				printf("%c",xox[1][0]);
			}
		}
		
		if(xe == 29 && ye == 16) {
			if(xox[1][1] == 'x' || xox[1][1] == 'o') {
				gotoxy(28,23);
				printf("Dolu kutuyu sectiniz...Tekrar deneyin");
				waitForAnyKey();
				gotoxy(28,23);
				printf("                                     ");
			}	
			else {
				xox[1][1] = 'o';
				printf("%c",xox[1][1]);
			}
		}
		
		if(xe == 32 && ye == 16) {
			if(xox[1][2] == 'x' || xox[1][2] == 'o') {
				gotoxy(28,23);
				printf("Dolu kutuyu sectiniz...Tekrar deneyin");
				waitForAnyKey();
				gotoxy(28,23);
				printf("                                     ");
			}
			else {
				xox[1][2] = 'o';
				printf("%c",xox[1][2]);
			}
		}
		
		if(xe == 26 && ye == 18) {
			if(xox[2][0] == 'x' || xox[2][0] == 'o') {
				gotoxy(28,23);
				printf("Dolu kutuyu sectiniz...Tekrar deneyin");
				waitForAnyKey();
				gotoxy(28,23);
				printf("                                     ");
			}
			else {
				xox[2][0] = 'o';
				printf("%c",xox[2][0]);
			}
		}
		
		if(xe == 29 && ye == 18) {
			if(xox[2][1] == 'x' || xox[2][1] == 'o') {
				gotoxy(28,23);
				printf("Dolu kutuyu sectiniz...Tekrar deneyin");
				waitForAnyKey();
				gotoxy(28,23);
				printf("                                     ");
			}	
			else {
				xox[2][1] = 'o';
				printf("%c",xox[2][1]);
			}
		}
	
		if(xe == 32 && ye == 18) {
			if(xox[2][2] == 'x' || xox[2][2] == 'o') {
				gotoxy(28,23);
				printf("Dolu kutuyu sectiniz...Tekrar deneyin");
				waitForAnyKey();
				gotoxy(28,23);
				printf("                                     ");
			}
			else {
				xox[2][2] = 'o';
				printf("%c",xox[2][2]);
			}
		}
	}
}



void winner(char xox[][3]) {
	int term=0;  	
//rows
	if((xox[0][0] == xox[0][1]) && (xox[0][1] == xox[0][2])) check(xox[0][0]);
	else if((xox[1][0] == xox[1][1]) && (xox[1][1] == xox[1][2])) check(xox[1][0]);
	else if((xox[2][0] == xox[2][1]) && (xox[2][1] == xox[2][2])) check(xox[2][0]);

//coloums
	else if((xox[0][0] == xox[1][0]) && (xox[1][0] == xox[2][0])) check(xox[0][0]);
	else if((xox[0][1] == xox[1][1]) && (xox[1][1] == xox[2][1])) check(xox[0][1]);
	else if((xox[0][2] == xox[1][2]) && (xox[1][2] == xox[2][2])) check(xox[0][2]);

//diagonal
	else if((xox[0][0] == xox[1][1]) && (xox[1][1] == xox[2][2])) check(xox[0][0]);
	else if((xox[0][2] == xox[1][1]) && (xox[1][1] == xox[2][0])) check(xox[0][2]);
	
	
	else {
		for(int i=0;i<3;i++) {
			for(int j=0;j<3;j++) {
				if(xox[i][j] == 'x' || xox[i][j] == 'o') {
					term++;
				}
			}
		}
		if(term == 9) {
			gotoxy(28,23);	
			printf("Berabere bitti...");
			ex = 0;
		}
	}	
	
}



void check(char a) {
	if(a == 'x') {
		gotoxy(28,23);
		printf("KAZANAN:%s",name[0]);
		gotoxy(28,23);
		waitForAnyKey();
		youWinScreen();
	}
	else if(a == 'o') {
		gotoxy(28,23);
		printf("KAZANAN:%s",name[1]);
		waitForAnyKey();
		youWinScreen();
	}
	
}

//durdurma
void pauseMenu(void) {
	int i;
	
	gotoxy(28,23);
	printf("*Durduruldu*");
	
	waitForAnyKey();
	gotoxy(28,23);
	printf("            ");
	gotoxy(26,16);

	return;
}


int youWinScreen(void) {
	int x = 6, y = 7;
	system("cls");
	
	gotoxy(x,y++);
	printf("'##:::'##::'#######::'##::::'##::::'##:::::'##:'####:'##::: ##:'####:");
	gotoxy(x,y++);
	printf(". ##:'##::'##.... ##: ##:::: ##:::: ##:'##: ##:. ##:: ###:: ##: ####:");
	gotoxy(x,y++);
	printf(":. ####::: ##:::: ##: ##:::: ##:::: ##: ##: ##:: ##:: ####: ##: ####:");
	gotoxy(x,y++);
	printf("::. ##:::: ##:::: ##: ##:::: ##:::: ##: ##: ##:: ##:: ## ## ##:: ##::");
	gotoxy(x,y++);
	printf("::: ##:::: ##:::: ##: ##:::: ##:::: ##: ##: ##:: ##:: ##. ####::..:::");
	gotoxy(x,y++);
	printf("::: ##:::: ##:::: ##: ##:::: ##:::: ##: ##: ##:: ##:: ##:. ###:'####:");
	gotoxy(x,y++);
	printf("::: ##::::. #######::. #######:::::. ###. ###::'####: ##::. ##: ####:");
	gotoxy(x,y++);
	printf(":::..::::::.......::::.......:::::::...::...:::....::..::::..::....::");
	gotoxy(x,y++);	
	
	waitForAnyKey();
	system("cls"); 
	ex = 0;
	return ex;
}








