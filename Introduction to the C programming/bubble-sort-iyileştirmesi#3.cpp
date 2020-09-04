#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define BOYUT 99
//bubblesort iyileþtirmesi #3
void bubblesort(int d[],int b);
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
void bubblesort(int d[],int b) {
	for(int j=0;j<b;j++) {
		bool flag = false;
		for(int i=0;i<b-1;i++) {
			if(d[i]>d[i+1]) {
				flag = true;
				int temp = d[i];
				d[i] = d[i+1];
				d[i+1] = temp;
			}
			if(!flag)
				return;
		}
	}
	
}
