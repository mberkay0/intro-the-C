#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define LENGTH 10
//Binary search
int binarySearch(int[],int,int,int);

int main() {
	int array[LENGTH] = {0,1,2,3,4,5,8,9,6,7};
	int search;
	
	printf("Arama yapmak istediginiz rakami giriniz:");
	scanf("%d",&search);
	if(binarySearch(array,0,LENGTH-1,search) == -1)
		printf("Aradiginiz bulunamadi");
	else 
		printf("Aradiginiz bulundu --> %d",binarySearch(array,0,LENGTH-1,search));
	
	getch();
	return 0;
}

int binarySearch(int a[],int low,int size,int key) {
	if(a[low] == key || a[size] == key) 
		return key;
	else if(low == size)
		return -1;
	else 
		return binarySearch(a,low+1,size,key);
	
}
