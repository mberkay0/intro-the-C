#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define LENGTH 25
//lineer search
int array[LENGTH];
int lineerSearch(int[],int,int,int);

int main() {
	int search;
	srand(time(NULL));
	for(int i=0;i<LENGTH;i++)
		array[i] = rand()%9+1;
	for(int i=0;i<LENGTH;i++)
		printf("%d, ",array[i]);
	printf("\nAramak istediginiz rakami belirtiniz:\nNot:Rakam -1 ise sonuc bulunamamistir.");
	scanf("%d",&search);
	printf("Aradiginiz sonuc bu mu? %d",lineerSearch(array,0,LENGTH-1,search));
	
	
	getch();
	return 0;
}

int lineerSearch(int a[],int low,int high,int key) {
	if(a[low] == key)
		return a[low];
	else if(low == high)
		return -1;
	else 
		return lineerSearch(a,low+1,high,key);
	
	
}
