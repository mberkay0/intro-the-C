#include <stdio.h>
#include <conio.h>
#define LEN 1000
void bubblesort(int*,const int,int(*)(int,int));
int artan(int,int);
int azalan(int,int);

int main() {
	int array[LEN],size,secim;
	
	printf("Bir dizi olusturacak uzunlugunu giriniz:");
	scanf("%d",&size);
	
	for(int i=0;i<size;i++)
		scanf("%d",&array[i]);
	printf("Dizi siralanmadan once : ");
	
	for(int i=0;i<size;i++)
		printf("%d, ",array[i]);
	
	printf("\nArtan siralama icin -> 1\n"
	"Azalan siralama icin -> 2 girin:\n");
	scanf("%d",&secim);
	
	if(secim == 1) {
		bubblesort(array,size,artan);	
		printf("Veriler artan sirasinda : ");
	}
	else {
		bubblesort(array,size,azalan);
		printf("Veriler azalan sirasinda : ");
	}
	
	for(int i=0;i<size;i++)
		printf("%d, ",array[i]);
	
	getch();
	return 0;
}

void bubblesort(int *aPtr,const int length,int(*karsilastir)(int,int)) {
	void place_change(int*,int*);
	for(int i=0;i<length;i++) {
		for(int j=0;j<length -1;j++)
			if((*karsilastir)(aPtr[j],aPtr[j+1]))
				place_change(&aPtr[j],&aPtr[j+1]);
	}
}

void place_change(int *p1,int *p2) {
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

int artan(int a,int b) {
	return b < a;
}

int azalan(int a,int b) {
	return b > a;
}



