#include <stdio.h>
#include <conio.h>

int main() {
	char *digits[10 ] = {"","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
	char *teens[10 ] = {"TEN","ELEVEN","TWELVE","THIRTEEN","FOURTEEN","FIFTEEN","SIXTEEN","SEVENTEEN","EIGHTEEN","NINETEEN"};
	char *tens[10 ] = {"","TEN","TWENTY","THIRTY","FORTY","FIFTY","SIXTY","SEVENTY","EIGHTY","NINETY"};
	int dollars;
	int cents;
	int digit1;
	int digit2;
	printf("Enter the check amount ( 0.00 to 99.99 ): " );
	scanf("%d.%d", &dollars, &cents );
	printf("\nThe check amount in words is:\n" );

	if ( dollars <10 ) 	
		printf("%s ", digits[ dollars ] );
 
	else if ( dollars <20 ) 
		printf("%s ", teens[ dollars -10 ] );
	else {
		digit1 = dollars /10;
		digit2 = dollars %10;
		if ( digit2 ==0 ) 
			printf("%s ", tens[ digit1 ] );

		else 
			printf("%s-%s ", tens[ digit1 ], digits[ digit2 ] );

	}
	printf("and %d/100\n", cents );
	getch();
	return 0;
}
