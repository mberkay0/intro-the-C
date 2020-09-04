#include <stdio.h>
#include <conio.h>
#define VEZIRLER 8          /* vezir sayisi ve tahta boyu */
#define int unsigned        /* isaretsiz tamsayi kullan */

int sayi = 0;               /* cozum sayisi */
int tahta [VEZIRLER];       /* her eleman bir sirayi gosterir */

int tahtaTamam              /* tahtanin gecerliligini kontrol et */
(register int sira) {
   register int r;
	for (r = 0; r < sira; r++) /* onceki tum siralari  kontrol et */
		if (tahta[sira] == tahta[r] ||
        	tahta[sira] == tahta[r] << sira-r ||
        	tahta[sira] == tahta[r] >> sira-r)
		return 0;             /* uyusmazlik varsa */
	return 1;                 /* uyusmazlik yoksa */
}

void cozumyaz (void) {  /* cozumu goster; sayiyi artir  */ 
	register int t, r;
	printf("\n\n\t[COZUM]:%u\n\n", ++sayi);
	for (r = 0; r < VEZIRLER; r++) { /* sira */
		for (t = 1<<VEZIRLER-1; t > 0; t >>= 1)
			printf(" %c", tahta[r] == t ? 'V' :  '.');
		printf("\n");
	}
}

void yerlestir (int sira) {   /* bir sonraki siraya yerlestir  */
   if (sira == VEZIRLER)     /* tum siralar dolu ve kontrol  edilmis */
    	cozumyaz();
   else
    	for (tahta[sira]=1; tahta[sira]<1<<VEZIRLER;  tahta[sira]<<=1)
    		if (tahtaTamam(sira))
        		yerlestir(sira+1);  /* bir sonraki sirayi dene */
}

signed main (void) {
	yerlestir(0);             /* ilk siradan basla */
	printf("\n\n%d vezir probleminin %u cozumu vardir.\n",VEZIRLER, sayi);
	getch();
	return 0;
}

