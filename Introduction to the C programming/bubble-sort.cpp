#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define BOYUT 99
/*bubble sort algorithm of sorting algorithm
	1.Ýlk iki sayýyý al
	2.Aldýðýn iki sayýyý karþýlaþtýr
	3.Küçük olaný yaz diðerini aklýnda tut
	4.Dizinin sonuna geldiysen aklýndaki sayýyý diziye yazarak bitir
	5.Dizinin sonu deðilse yeni bir sayý al
	6.-->2.adýma geri git
*/
int bubblesort(int d[],int boyut);
int main() {
	int dizi[BOYUT];
	int b;
	printf("Bir dizi olusturmak icin once boyut giriniz :\n");
	scanf("%d",&b);
	printf("Simdi dizinin terimlerini giriniz :\n");
	for(int i=0;i<b;i++) {
		scanf("%d",&dizi[i]);
		}
	bubblesort(dizi,b);
	printf("Dizinizin terimleri :\n");
	for(int i=0;i<b;i++) 
		printf("%d, ",dizi[i]);
		
	getch();
	return 0;
}
int bubblesort(int d[],int boyut) {
	int temp=0;
	for(int j=0;j<boyut;j++) {
		for(int i=0;i<boyut-1;i++) {
			if(d[i]>d[i+1]) {
				temp = d[i];
				d[i] = d[i+1];
				d[i+1] = temp;
			}
		}
			
	}
	
	
}

