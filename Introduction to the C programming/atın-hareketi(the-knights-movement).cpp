#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define LENGTH 8
int tahta[LENGTH][LENGTH] = {{0}};
int print(void);

int main() {
	int yatay[LENGTH] = {2,1,-1,-2,-2,-1,1,2};
	int dikey[LENGTH] = {-1,-2,-2,-1,1,2,2,1};
	int bulunanSatir = 3,bulunanSutun = 3,hamle,sayac;
	tahta[bulunanSatir][bulunanSutun] = 1;
	print();
	printf("\nYukarida atin bulundugu konum verilmistir.\n\n");
	while(1) {
		printf("0'dan 7'ye bir hamle secin:\nCikis yapmak icin -1 e basin.");
		scanf("%d",&hamle);
		if(hamle == -1)
			return 0;
		else {
			bulunanSatir += dikey[hamle];
			bulunanSutun += yatay[hamle];
			tahta[bulunanSatir][bulunanSutun] = 1;
			tahta[3][3] = 0;
			print();
		}
		tahta[bulunanSatir][bulunanSutun] = 0;
		tahta[3][3] = 1;
		bulunanSatir = 3;
		bulunanSutun = 3;
	}
	getch();
}
int print(void) {
	printf(" A  B  C  D  E  F  G  H\n");
	printf(" _  _  _  _  _  _  _  _\n");
	for(int i=0;i<LENGTH;i++) {
		for(int j=0;j<LENGTH;j++) {
				if(tahta[i][j] == 1)
					printf("|%d|",tahta[i][j]);
				else
					printf("|_|",tahta[i][j]);
		}
		printf(" %d\n",i+1);

	}
}
