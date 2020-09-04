#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define LENGTH 99

int bubblesort(int[],int);
int binarysearch(int[],int,int);
int copyEliminate(int[],int);

int main() {
	srand(time(NULL));
	int dizi[LENGTH];
	int uzunluk,istenen;
	printf("Dizinin uzunlugunu belirleyiniz:");
	scanf("%d",&uzunluk);
	
	for(int i=0;i<uzunluk;i++) 
		dizi[i] = rand()%uzunluk+1;	
	
	for(int i=0;i<uzunluk;i++)
		printf("%d ,",dizi[i]);	
	printf("\nDiziden istediginiz sayiyi aratiniz:");
	scanf("%d",&istenen);
	
	bubblesort(dizi,uzunluk);	
	binarysearch(dizi,uzunluk,istenen);
		
	getch();
	return 0;
}

int binarysearch(int c[],int f,int aranan) {
	int enb,enk,flag = 0;
	enb = f;
	enk = -1;
	while(enb-enk > 1) {
		int bakilan = (enb+enk) / 2;
		if(c[bakilan] == aranan) {
			flag = 1;
			printf("bulunan : %d. elemandir.",bakilan+1);
			break;
		}
		else if(c[bakilan]<aranan) {
			enk = bakilan;
		}
		else 
			enb = bakilan;
	}
	if(flag == 0)
		printf("sayi bulunamadi");
	
}

int bubblesort(int d[],int b) {
	int temp=0,tur,flag=0;
	tur = b;
	for(int j=0;j<b;j++) {
		for(int i=0;i<tur-1;i++) {
			if(d[i]>d[i+1]) {
				temp = d[i];
				d[i] = d[i+1];
				d[i+1] = temp;
				flag++;
			}
		}
		if(flag == 0)
			j = b;
		tur--;
	}
	
}

int copyEliminate(int e[],int g) {
	for(int i=0;i<g;i++) {
		for(int j=0;j<g;j++) {
			if(e[i] == e[j])
				
		}
	}
}


