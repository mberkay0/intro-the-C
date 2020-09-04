#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main() {
	int hesap_no1=100,hesap_no2=200,sifre1=111,sifre2=222, sayac=0;
	int gecici_no,gecici_sifre=1,secim,deneme_sifre1,param ;
	int top_param=0, deneme_sifre2,gecici_sifre1;
	int para_cek;
	char harf,harf2;


	baslangic_noktasi: 
	printf("\BANKAMIZA HOSGELDINIZ\n");
	printf("\t-------------------------------------\n");
	printf("\tbanka hesap numaranizi giriniz: ");
	scanf("%d",&gecici_no);


	while(gecici_no!=hesap_no1 && gecici_no!=hesap_no2) {
		if(gecici_no==-1)
			break;
		printf("\tYanlis hesap numarasi!!!!\n");
		printf("\tlutfen tekrar deneyiniz: \n");
		scanf("%d",&gecici_no);

	}

	if(gecici_no==hesap_no1) {
		while(gecici_sifre!=sifre1) {
			if(sayac==3) {
				printf("\tHesabiniz kilitlendi\n");
				printf("\tBanka yoneticinizle gorusunuz\n");
				goto baslangic_noktasi;

			}
			printf("\n\tsifrenizi giriniz: ");
			scanf("%d",&gecici_sifre);
			sayac++;
		} 

		while(secim!=5) {
			printf("\n\tBANKA ISLEMLERI MENUSU\n");
			printf("\t1. Sifre Degistirme\n");
			printf("\t2. Para Yatirma\n");
			printf("\t3. Para Cekme\n");
			printf("\t4. Hesap Yazdir\n");
			printf("\t5. Cikis\n");
			printf("\t>>Seciminiz");
			scanf("%d",&secim);
			if(secim==1) {
				printf("\tyeni Sifreniz");
				scanf("%d",&deneme_sifre1);
				printf("\n\tyeniden sifrenizi giriniz");
				scanf("%d",&deneme_sifre2); 
				while(deneme_sifre1!=deneme_sifre2) {
					printf("\n\tEslesme Yapilamadi\n");
					printf("\tyeniden sifrenizi giriniz:");
					scanf("%d",&deneme_sifre2); 
				}
				if(deneme_sifre1==deneme_sifre2) {
					sifre1=deneme_sifre1;
					printf("\tSifreniz Degistirilmistir\n");
				} 

			}
			if(secim==2) {
				printf("\tYatirilacak Miktar: ");
				scanf("%d",&param); 
				top_param+=param;
				printf("\tParaniz Hesabiniza Yatirilmistir.\n"); 
				printf("\tHesabinizdaki Para: %d\n",top_param); 
			} 
			if(secim==3) {
				printf("\tCekilecek para miktari: ");
				scanf("%d",&para_cek); 

				if(top_param>para_cek) {
					printf("\tcekilen para miktari: %d\n",para_cek);
					top_param=(top_param)-(para_cek);
					printf("\thesabinizda %d kalmistir.\n",top_param); 
				}

				if(top_param<para_cek) {
					printf(">>Bankaya borclanacaksiniz devam etmek istiyormusunuz(E(e)/H(h)): ");
					scanf("%2c",&harf2,&harf);

					switch(harf) {
						case 'e':
						case 'E': top_param=(top_param)-(para_cek);
							printf("\tCekilen tutar %d Bankaya %d borclandiniz.\n",para_cek,top_param);
							break;
						case 'h':
						case 'H': printf("\tisleminiz iptal Olmustur..\n");
					} 
				}
			} 
			if(secim==4) {
				printf("\tBanka Hesap Numaraniz: %d\n",hesap_no1);
				printf("\tBakiyeniz: %d",top_param); 
			} 
			if(secim==5)
				printf("\t\tHOSCAKALiN...!!!\n");


		} 
	}




	if(gecici_no==hesap_no2) {
while(gecici_sifre!=sifre2)
{
if(sayac==3)
{
printf("Hesabiniz kilitlendi\n");
printf("Banka yoneticinizle gorusunuz\n");
goto baslangic_noktasi;

}
printf("sifrenizi giriniz\n");
scanf("%d",&gecici_sifre);
sayac++;
}  


while(secim!=5)
{
printf("\nBANKA ISLEMLERI MENUSU\n");
printf("1. Sifre Degistirme\n");
printf("2. Para Yatirma\n");
printf("3. Para Cekme\n");
printf("4. Hesap Yazdir\n");
printf("5. Cikis\n");
printf(">>Seciminiz");
scanf("%d",&secim);
if(secim==1)
{
printf("yeni Sifreniz\n");
scanf("%d",&deneme_sifre1);
printf("yeniden sifrenizi giriniz\n");
scanf("%d",&deneme_sifre2); 
while(deneme_sifre1!=deneme_sifre2)
{
printf("Eslesme Yapilamadi\n");
printf("yeniden sifrenizi giriniz\n");
scanf("%d",&deneme_sifre2); 
}
if(deneme_sifre1==deneme_sifre2)
{
sifre2=deneme_sifre1;
printf("Sifreniz Degistirilmistir\n");
} 

}
if(secim==2)
{
printf("Yatirilacak Miktar: ");
scanf("%d",&param); 
top_param+=param;
printf("Paraniz Hesabiniza Yatirilmistir.\n"); 
printf("Hesabinizdaki Para: %d\n",top_param); 
} 
if(secim==3)
{

printf("Cekilecek para miktari: ");
scanf("%d",&para_cek); 

if(top_param>para_cek)
{
printf("cekilen para miktari: %d\n",para_cek);
top_param=(top_param)-(para_cek);
printf("hesabinizda %d kalmistir.\n",top_param); 

}

if(top_param<para_cek) 
{
printf(">>Bankaya borclanacaksiniz devam etmek istiyormusunuz(E(e)/H(h)): ");
scanf("%2c",&harf2,&harf);

switch(harf)
{
case 'e':
case 'E': top_param=(top_param)-(para_cek);
printf("Cekilen tutar %d Bankaya %d borclandiniz.\n",para_cek,top_param);
break;
case 'h':
case 'H': printf("isleminiz iptal Olmustur..\n");
} 

}
} 
if(secim==4)
{
printf("Banka Hesap Numaraniz: %d\n",hesap_no2);
printf("Bakiyeniz: %d",top_param); 
}
if(secim==5)
printf("HOSCAKALiN...!!!\n");

} 
} 

printf("\n\t***********\n\n");
system("PAUSE");
return 0; 
}
