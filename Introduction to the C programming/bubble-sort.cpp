#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define BOYUT 99
/*bubble sort algorithm of sorting algorithm
	1.�lk iki say�y� al
	2.Ald���n iki say�y� kar��la�t�r
	3.K���k olan� yaz di�erini akl�nda tut
	4.Dizinin sonuna geldiysen akl�ndaki say�y� diziye yazarak bitir
	5.Dizinin sonu de�ilse yeni bir say� al
	6.-->2.ad�ma geri git
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

