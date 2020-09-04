#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define LENGTH 1000

/*Eratosthenes Eleði:
	1-ilk önce bütün dizi 1 e atandý.
	2-daha sonra çifte for döngüsü ile i yi 2 den baþlatýp j yi i+1 yapýp asal olup olmadýklarýna bakýldý
	3-asal olmayanlar 0 a atandý 
	4-1 dizide olanlar sýra ile ekrana yazdýrýldý.  
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
