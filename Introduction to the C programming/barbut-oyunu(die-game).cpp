#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
int zarAtma(void);
int main() {
	int oyundurumu,bahis,toplam,giris,puan,laf,bakiye=1000;
	srand(time(NULL));
	printf("Barbut oyununa HOSGELDINIZ\n\n");
	printf("Barbut oyunu iki zar ile oynanir iki zarin toplami 7 veya 11 ise kazanirsin.2,3,12 ise kaybedersin.Eger ilk atista zarlarin toplami 4,5,6,8,9,10 ise oyuncu bu toplami atmalidir eger 7 yi bulursa oyuncu kaybeder.\nBol sans :)\n\n");
	printf("Mevcut bakiyeniz 1000$ olarak ayarlandi.\n");
	while(giris != -1) {
		printf("Bahis degerinizi giriniz :\n");
		scanf("%d",&bahis);
		while(bahis>bakiye) {
			printf("Bahisiniz mevcut bakiyenizden fazla olamaz!\nLutfen tekrar giriniz:\n");
			scanf("%d",&bahis);
		}	
		toplam=zarAtma();
		switch(toplam) {
			case 7:case 11:
				oyundurumu=1;
				break;
			case 2:case 3:case 12:
				oyundurumu=2;
				break;
			default :
				oyundurumu=0;
				puan=toplam;
				printf("oyuncunun kazanacagi zar : %d\n",puan);
				break;
		}
		while(oyundurumu == 0) {
			toplam=zarAtma();
			if(toplam == puan)
				oyundurumu=1;
			else
				if(toplam == 7)
					oyundurumu = 2;
		}
		if(oyundurumu == 1) {
			printf("oyuncu kazandi\n");
			bakiye += bahis;		
			printf("yeni bakiyeniz : %d\n",bakiye);
			laf = 1 + rand()%4;
			switch(laf) {
				case 1:
					printf("Az daha kazanmaya ne dersiniz?\n");
					break;
				case 2:
					printf("Inanilmaz cok basarilisiniz.\n");
					break;
				case 3:
					printf("Milyoner olabilirsiniz.\n");
					break;
				case 4:
					printf("Hadi tekrar oyanayalim.\n");
					break;
			}
		}
		else {
			printf("oyuncu kaybeder\n");
			bakiye -= bahis;	
			printf("yeni bakiyeniz : %d\n",bakiye);
			laf = 1 + rand()%4;
			switch(laf) {
				case 1:
					printf("Tekrar deneyin kazanmak uzeresiniz.\n");
					break;
				case 2:
					printf("Zugurt olmak uzeresiniz.\n");
					break;
				case 3:
					printf("Ah az daha oluyordu.\n");
					break;
				case 4:
					printf("Hadi bir kez daha deneyin.\n");
					break;
			}
		}
		if(bakiye==0) {
			printf("Bakiyeniz kalmadigi icin oyun sona erdi.\n");
			printf("Devam etmek icin 1 cikmak icin -1 basiniz :\n");
			scanf("%d",&giris);
			if(giris != -1) {
				bakiye = 1000;
				printf("Bakiyeniz 1000$ olarak ayarlandi.\n");
			}
		}
		else {
		printf("Devam etmek icin 1 cikmak icin -1 basiniz :\n");
		scanf("%d",&giris);
		}
	}
	if(bakiye>0)
		printf("Super %d$ kazandiniz oyunumuza yine bekleriz :)\n",bakiye);
	getch();
	return 0;
}
int zarAtma(void) {
	int zar1,zar2,toplamzar;
	zar1=1+(rand()%6);
	zar2=1+(rand()%6);
	toplamzar = zar1 + zar2;
	printf("oyuncu %d atti\n",toplamzar);
	return toplamzar;
}
