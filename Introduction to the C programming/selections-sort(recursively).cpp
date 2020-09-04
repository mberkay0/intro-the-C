#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#define LENGTH 99
//Selection sort
int array[LENGTH] = {0};
int selectionSort(int[],int);

int main() {
	int len;
	printf("Dizinin uzunlugunu giriniz:");
	scanf("%d",&len);
	printf("Simdi dizinin elemanlarini giriniz:");
	for(int i=0;i<len;i++) {
		scanf("%d",&array[i]);
	}
	printf("Siralamadan once :\n");
	for(int i=0;i<len;i++) {
		printf("%d, ",array[i]);	
	}
	printf("\n");
	printf("Siralamadan sonra :\n");
	selectionSort(array,len);
	for(int i=0;i<len;i++) {
		printf("%d, ",array[i]);	
	}
	
	getch();
	return 0;
}

int selectionSort(int a[],int size) {
	int temp;
	if(size >= 1) {
		for(int i=0;i<size;i++) {
			if(a[i]<a[0]) {
				temp = a[i];
				a[i] = a[0];
				a[0] = temp;
			}
		}
		selectionSort(&a[1],size -1);	
	}
}
