#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
/*
Eriþilebilirlik stratejisi ve Euler yaklaþýmý 
yanda satranç tahtasý verilmiþtir ve eriþelebilirlik numaralari belirtilmiþtir 
numarasi en düþük olandan baþlanir ve uðrana yere bir daha uðranilmaz.
											  2 3 4 4 4 4 3 2
											  3 4 6 6 6 6 4 3
											  4 6 8 8 8 8 6 4
											  4 6 8 8 8 8 6 4
											  4 6 8 8 8 8 6 4
											  4 6 8 8 8 8 6 4 
											  3 4 6 6 6 6 6 3
											  2	3 4 4 4 4 4 2		
*/
int tahta[8][8][2]=
{
    {{0,2}, {0,3}, {0,4}, {0,4}, {0,4}, {0,4}, {0,3}, {0,2}},
    {{0,3}, {0,4}, {0,6}, {0,6}, {0,6}, {0,6}, {0,4}, {0,3}},
    {{0,4}, {0,6}, {0,8}, {0,8}, {0,8}, {0,8}, {0,6}, {0,4}},       //tahta koordinatlarý  ve  o koordinatýn  gidebilecegi yer sayýsý
    {{0,4}, {0,6}, {0,8}, {0,8}, {0,8}, {0,8}, {0,6}, {0,4}},           //tahta[][][0] kordinat için tahta[][][1] o koordinatin yapabilecegi hamle
    {{0,4}, {0,6}, {0,8}, {0,8}, {0,8}, {0,8}, {0,6}, {0,4}},            //sayisi
    {{0,4}, {0,6}, {0,8}, {0,8}, {0,8}, {0,8}, {0,6}, {0,4}},
    {{0,3}, {0,4}, {0,6}, {0,6}, {0,6}, {0,6}, {0,4}, {0,3}},
    {{0,2}, {0,3}, {0,4}, {0,4}, {0,4}, {0,4}, {0,3}, {0,2}}
};


int Gid_X[8]= {0},Gid_Y[8]= {0},GYS=0;              //  Gid_X, Gid_Y  gidebilecegi yerleri tutan dizi.   GYS(gidebilecegi yer sayisi)
int sayac=0,konumX,konumY;                          // konumX konumY anlýk konumu;
void Eksilt();                                      // eksilt() degisen konuma göre tahtadan tahta[][][1] hamle sayýsý azaltma
void tahtagoster();
void GYDoldur(int,int);                             // gidilen yerleri  1 ile dolduruyoruz
void tahtasifirla();                                //  tekrar etmesi halinde sýfýrlama
int Gidebilecegi_yerler(int,int);                   // anlýk konuma göre gidebilecegi yerler
void Gkarar(int);                                    // hangi hamleyi oynucaðýný belirleye karar mekanizmasi
int main()
{
    int ilkKonumx,ilkKonumy;
    printf("Atin ilkKonumunu secin: ");
    scanf("%d %d",&ilkKonumx,&ilkKonumy);
            tahtasifirla();
            sayac=0;
                konumX=ilkKonumx-1;
                konumY=ilkKonumy-1;
            GYDoldur(konumX,konumY);

            while(sayac<64)
            {

                sayac++;
                printf("%d. hamle (%d,%d) konumunda \n",sayac,konumX+1,konumY+1);
                GYS=Gidebilecegi_yerler(konumX,konumY);
                Eksilt();
                if(GYS==0 && sayac<64)
                {
                    printf("(%d,%d) %s \n",ilkKonumx+1,ilkKonumy+1,"At tahtanin her yerini gezmeyi basaramadi  \n(tekrar denemek icin t tusuna basyn: ");
                   char tekrar;
                   tekrar=getchar();                                                                 // BAÞARISIZ OLMA ÝHTÝMALÝNDE HEREÞEYÝ SIFIRLAYIP BAÞA DÖNDÜRÜYOR.   
                   if(getchar()=='t')
                   {
                    sayac=0; tahtasifirla();printf("Atin ilkKonumunu secin: "); scanf("%d %d",&ilkKonumx,&ilkKonumy);konumX=ilkKonumx-1;
                konumY=ilkKonumy-1;continue;
                   }
                }
                Gkarar(GYS);
                GYDoldur(konumX,konumY);
            }
            if(sayac==64)
            {
                printf("(%d,%d) %s\n",ilkKonumx,ilkKonumy,"Basari ile at tahtanin her yerinde dolasti") ;
                getch();
            }
}
int Gidebilecegi_yerler(int konumX,int konumY)
{
    int X[8]= {2,2,1,1,-1,-1,-2,-2};
    int Y[8]= {1,-1,2,-2,2,-2,1,-1};
    int i=0,j=0;
    for(; i<8; i++)
    {
        if(konumX+X[i]<8 && konumX+X[i]>=0)
            if(konumY+Y[i]<8 && konumY+Y[i]>=0)
                if(tahta[konumX+X[i]][konumY+Y[i]][0]!=1)
                {
                    Gid_X[j]=konumX+X[i];
                    Gid_Y[j]=konumY+Y[i];
                    j++;
                }
    }
    return j;
}
void Gkarar(int GYS)
{
    int i=0,kucuk=tahta[Gid_X[0]][Gid_Y[0]][1];
    konumX=Gid_X[i];
    konumY=Gid_Y[i];
    for(; i<(GYS); i++)
    {
        if(kucuk<tahta[Gid_X[i]][Gid_Y[i]][1])
        {
            continue;
        }
        else if(kucuk==tahta[Gid_X[i]][Gid_Y[i]][1])
        {
            int a=rand()%2;
            if(a==0)
            {
             konumX=Gid_X[i];
             konumY=Gid_Y[i];
             kucuk=tahta[Gid_X[i]][Gid_Y[i]][1];
            }
        }
        else
        {
            konumX=Gid_X[i];
            konumY=Gid_Y[i];
            kucuk=tahta[Gid_X[i]][Gid_Y[i]][1];
        }
    }
}
void GYDoldur(int konumX,int konumY)
{
    tahta[konumX][konumY][0]=1;
    GYS=0;
    int i=0;
    for(; i<8; i++)
    {
        Gid_X[i]=0;
        Gid_Y[i]=0;
    }
}

void Eksilt()
{
    int i=0;
    for(; i<GYS; i++)
        tahta[Gid_X[i]][Gid_Y[i]][1]--;
}


void tahtasifirla()
{
    int i=0,j=0;
    tahta[0][0][1]=2;
    tahta[1][0][1]=3;
    tahta[2][0][1]=4;
    tahta[3][0][1]=4;
    tahta[4][0][1]=4;
    tahta[5][0][1]=4;
    tahta[6][0][1]=3;
    tahta[7][0][1]=2;
    tahta[0][1][1]=3;
    tahta[1][1][1]=4;
    tahta[2][1][1]=6;
    tahta[3][1][1]=6;
    tahta[4][1][1]=6;
    tahta[5][1][1]=6;
    tahta[6][1][1]=4;
    tahta[7][1][1]=3;
    tahta[0][2][1]=4;
    tahta[1][2][1]=6;
    tahta[2][2][1]=8;
    tahta[3][2][1]=8;
    tahta[4][2][1]=8;
    tahta[5][2][1]=8;
    tahta[6][2][1]=6;
    tahta[7][2][1]=4;
    tahta[0][3][1]=4;
    tahta[1][3][1]=6;
    tahta[2][3][1]=8;
    tahta[3][3][1]=8;
    tahta[4][3][1]=8;
    tahta[5][3][1]=8;
    tahta[6][3][1]=6;
    tahta[7][3][1]=4;
    tahta[0][4][1]=4;
    tahta[1][4][1]=6;
    tahta[2][4][1]=8;
    tahta[3][4][1]=8;
    tahta[4][4][1]=8;
    tahta[5][4][1]=8;
    tahta[6][4][1]=6;
    tahta[7][4][1]=4;
    tahta[0][5][1]=4;
    tahta[1][5][1]=6;
    tahta[2][5][1]=8;
    tahta[3][5][1]=8;
    tahta[4][5][1]=8;
    tahta[5][5][1]=8;
    tahta[6][5][1]=6;
    tahta[7][5][1]=4;
    tahta[0][6][1]=3;
    tahta[1][6][1]=4;
    tahta[2][6][1]=6;
    tahta[3][6][1]=6;
    tahta[4][6][1]=6;
    tahta[5][6][1]=6;
    tahta[6][6][1]=4;
    tahta[7][6][1]=3;
    tahta[0][7][1]=2;
    tahta[1][7][1]=3;
    tahta[2][7][1]=4;
    tahta[3][7][1]=4;
    tahta[4][7][1]=4;
    tahta[5][7][1]=4;
    tahta[6][7][1]=3;
    tahta[7][7][1]=2;
    for(; i<8; i++)
    {
        for(; j<8; j++)
        {
            tahta[i][j][0]=0;
        }
        j=0;
    }
}
void tahtagoster()
{
    int i=0,j=0;
    for(; i<8; i++)
    {
        for(; j<8; j++)
        {
            printf("%d ",tahta[j][i][1]);
            if(j==7)
                printf("\n");
        }
        j=0;
    }
}
