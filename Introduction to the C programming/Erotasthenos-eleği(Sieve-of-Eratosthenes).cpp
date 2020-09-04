#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define LENGTH 1000

/*Eratosthenes Ele�i:
	1-ilk �nce b�t�n dizi 1 e atand�.
	2-daha sonra �ifte for d�ng�s� ile i yi 2 den ba�lat�p j yi i+1 yap�p asal olup olmad�klar�na bak�ld�
	3-asal olmayanlar 0 a atand� 
	4-1 dizide olanlar s�ra ile ekrana yazd�r�ld�.  
*/

int dizi[LENGTH];

int main() {

	for(int i=0;i<LENGTH;i++)
		dizi[i] = 1;
		
	for(int i=2;i<LENGTH;i++) {
		for(int j=i+1;j<LENGTH;j++) {
			if(j%i == 0)
				dizi[j] = 0;
		}
	}
	
	for(int i=2;i<LENGTH;i++) {
		if(dizi[i] == 1)
			printf("%d, ",i);
	}
	
	getch();
	return 0;
}
