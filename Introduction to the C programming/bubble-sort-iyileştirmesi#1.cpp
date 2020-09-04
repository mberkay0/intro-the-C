#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define BOYUT 99
//bubble sort iyileþtirmesi #1
int bubblesort(int d[],int boyut);
int main() {
	int str[BOYUT];
	int length;
	printf("Bir dizi olusturmak icin once boyutunu giriniz:\n");
	scanf("%d",&length);
	printf("Pekala simdi dizinin elemanlarini giriniz:\n");
	for(int i=0;i<length;i++) 
		scanf("%d",&str[i]);
	bubblesort(str,length);
	printf("Simdi elemanlarin siralanmis hallerine bakalim:\n");
	for(int i=0;i<length;i++)
		printf("%d, ",str[i]);
	getch();
	return 0;
}
int bubblesort(int d[],int boyut) {
	int temp=0,tur;
	tur = boyut;
	for(int j=0;j<boyut;j++) {
		for(int i=0;i<tur-1;i++) {
			if(d[i] > d[i+1]) {
				temp = d[i];
				d[i] = d[i+1];
				d[i+1] = temp;
			}
		}
		tur--;
	}	
}

