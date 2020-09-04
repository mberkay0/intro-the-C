#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define BOYUT 99
//bubblesort iyileþtirmesi #2
int bubblesort(int d[],int b);
int main() {
	int str[BOYUT],length;
	printf("Dizinin boyutunu giriniz:\n");
	scanf("%d",&length);
	printf("Simdi ise dizinin elemanlarini giriniz:\n");
	for(int i=0;i<length;i++)
		scanf("%d",&str[i]);
	bubblesort(str,length);
	printf("Girdiginiz elemanlarin siralanmis halleri:\n");
	for(int i=0;i<length;i++)
		printf("%d, ",str[i]);
	getch();
	return 0;
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
