#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
//pointers
int call_by_value_cube(int n) {   //degere göre çaðýrma;
	return n*n*n;
}


void call_by_referance_cube(int *ptr) {	//referansa göre çaðýrma;
	*ptr = *ptr * *ptr * *ptr;
}


int main() {
	int a,x;
	int *aPtr;
	
	a = 7;
	aPtr = &a;//bir pointira bir tam sayiyi gösteren a nin adresi atandi;
	
	printf("a'nin adresi : %p\n",&a);
	printf("aPtr degiskeninin degeri : %p\n""a'nin degeri : %d\n",aPtr,a);
	printf("*aPtr'nin degeri : %d\n",*aPtr);
	printf("* ve & birbirlerinin eslenigidir:\n");
	printf("&*aPtr : %p\n",&*aPtr);
	printf("*&aPtr : %p\n",*&aPtr);
	printf("Simdi bir iki ornek ile call by value ve call by referance kavramlarina bakalim:\n");
	printf("Bir sayi giriniz:");
	scanf("%d",&x);
	printf("Sonuc(call by value) : %d\n",call_by_value_cube(x));
	call_by_referance_cube(&x);
	printf("Sonuc(call by referance) : %d",x);
	
	getch();
	return 0;
}




