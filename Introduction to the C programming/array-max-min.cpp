#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define BOYUT 3

int main() {
	int dizi[BOYUT][BOYUT];
	int enbuyuk=0;
	int enkucuk=0;
	for(int i=0;i<=BOYUT-1;i++) 
		for(int j=0;j<=BOYUT-1;j++) {
			scanf("%d",&dizi[i][j]);
			if(i==0 && j==0)
				enkucuk = dizi[0][0];
			else if(dizi[i][j]<enkucuk)
				enkucuk = dizi[i][j];
			if(dizi[i][j]>enbuyuk)
				enbuyuk = dizi[i][j];
		}
	printf("dizilerimizin gösterimi\n");
	for(int i=0;i<=BOYUT-1;i++) {
		for(int j=0;j<=BOYUT-1;j++) {
			printf("Tablo[%d][%d]\n",i+1,j+1);
			printf("%d.satir %d.sutun : %d\n",i+1,j+1,dizi[i][j]);	
		}
	}
	printf("dizideki en buyuk terim : %d\n",enbuyuk);
	printf("dizideki en kucuk terim : %d",enkucuk);
	getch();
	return 0;
}
