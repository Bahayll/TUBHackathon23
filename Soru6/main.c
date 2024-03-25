#include <stdio.h>
#include <stdlib.h>
int SIZE;

int yesil_alan_toplami(int dizi[SIZE][SIZE]){
    int toplam=0;
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if((i>j && i+j<(SIZE-1)) || (i<j && i+j>(SIZE-1)))//birinci köþegen i=j olan elemanlardýr ikinci köþegen i+j=uzunluk-1 olan köþegenlerdir
            //veyanýn solu ilk yeþil alaný temnsil etmekte veyanýn saðý ikinci yeþil alaný temsil etmekte
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
        scanf("%d",&n);//satýr uzunluðu aldýk
    }while(n<=0);

    int dizi[n][n];//kare matris olþturduk
    SIZE=n;
    for(int i=0;i<n;i++){//random elemanlar atadýk
        for(int j=0;j<n;j++){
            dizi[i][j]=rand()%10;
            printf("%3d",dizi[i][j]);//yazdýk ekrana matrisi
        }
        printf("\n");
    }
    printf("\nyesil alan toplami = %d",yesil_alan_toplami(dizi));
    scanf("%d");//console kapanmasýn diye
    return 0;
}
