#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
//hanoi kuleleri
void hanoi(int,char,char,char);
int main() {
	int disks;
	printf("lutfen disk sayisini giriniz:\n");
	scanf("%d",&disks);
	printf("Hanoi kulelerine disklerin haraketleri:\n");
	hanoi(disks, 'A', 'C', 'B');
	getch();
	return 0;
}
void hanoi(int num,char cubuk1,char cubuk2,char cubuk3) {
	if(num == 1) {
		printf("Disk 1 %c den %c ye hareket ettirildi.\n",cubuk1,cubuk2);
		return;
	}
	hanoi(num - 1,cubuk1,cubuk3,cubuk2);
	printf("Disk %d %c den %c ye hareket ettirildi.\n",num,cubuk1,cubuk2);
	hanoi(num -1,cubuk3,cubuk2,cubuk1);
}
