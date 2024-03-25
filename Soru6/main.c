#include <stdio.h>
#include <stdlib.h>
int SIZE;

int yesil_alan_toplami(int dizi[SIZE][SIZE]){
    int toplam=0;
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if((i>j && i+j<(SIZE-1)) || (i<j && i+j>(SIZE-1)))//birinci k��egen i=j olan elemanlard�r ikinci k��egen i+j=uzunluk-1 olan k��egenlerdir
            //veyan�n solu ilk ye�il alan� temnsil etmekte veyan�n sa�� ikinci ye�il alan� temsil etmekte
                toplam+=dizi[i][j];
        }
    }
    return toplam;
}

int main()
{
    int n;
    do{//pozitif sayi alma
        printf("pozitif bir n tam sayisi giriniz : ");
        scanf("%d",&n);//sat�r uzunlu�u ald�k
    }while(n<=0);

    int dizi[n][n];//kare matris ol�turduk
    SIZE=n;
    for(int i=0;i<n;i++){//random elemanlar atad�k
        for(int j=0;j<n;j++){
            dizi[i][j]=rand()%10;
            printf("%3d",dizi[i][j]);//yazd�k ekrana matrisi
        }
        printf("\n");
    }
    printf("\nyesil alan toplami = %d",yesil_alan_toplami(dizi));
    scanf("%d");//console kapanmas�n diye
    return 0;
}
