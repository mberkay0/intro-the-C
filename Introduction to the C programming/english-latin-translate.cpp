#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#define SIZE 1000
//ingilizce-latince çeviri;


void latins(char *word) {
	unsigned int i;
	
	for( i =1; i < strlen( word ); i++ ) {
		printf("%c", word[ i ] );
	}
	printf("%c%s", word[0 ],"ay" );
		
}




int main() {
	char c[SIZE];
	int chose;

	while(chose != -1) {
		printf("Bir kelime giriniz:");
		scanf("%s",c);
		latins(c);
		printf("\nBaska bir kelime girmek ister misiniz?(EVET(0)/HAYIR(-1))\n");
		scanf("%d",&chose);	
	}
	
	
	getch();
	return 0;
}
