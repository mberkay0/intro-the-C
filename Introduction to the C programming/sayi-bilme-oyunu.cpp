#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
	int tahmin,sayi,karar,sayac1=0,sayac2=0;
	srand(time(NULL));
	printf("baslamak ve devam etmek icin 1 e basin cikmak icin 0\n");
	scanf("%d",&karar);
	while(karar == 1) {
		sayi = 1 + rand()%1000;
		printf("1-1000 arasinda bir sayi tuttum.\nTahmin edebilir misin?\n");
		scanf("%d",&tahmin);
		sayac1++;
		while(tahmin != sayi) {
		if(tahmin<sayi)
			printf("Cok kucuk tekrar deneyiniz.\n");
		else if(tahmin>sayi)
			printf("Cok buyuk tekrar deneyiniz.\n");
		scanf("%d",&tahmin);
		sayac2++;
		}
		if(tahmin == sayi)
			printf("Mukemmel bildiniz.\n");
		if(sayac1+sayac2<=10)
			printf("Siz sirri biliyorsunuz ya da sanslisiniz\n");
		else
			printf("daha iyisini yapabilirsiniz :)\n");
		printf("Devam etmek istiyor musunuz?1/0\n");
		scanf("%c",&karar);
	}
	getch();
	return 0;
}
