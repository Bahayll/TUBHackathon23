#include <stdio.h>
#include <stdlib.h>
int SIZE;
int det(int dizi[SIZE][SIZE]){
    if(SIZE==2){//2 sat�r 2 sutun olan bir kare matris ise;
       return (dizi[0][0])*(dizi[1][1]) - (dizi[0][1])*(dizi[1][0]); //a*d-b*c
    }//matris b�y�k ise
    else{
        int satir_fre[SIZE];//en �ok 0 olan sat�r veya sutunu ar�yoruz
        int sutun_fre[SIZE];

        for(int i=0;i<SIZE;i++){//ba�lang�� de�erlerini 0 verdik
            satir_fre[i]=0;
            sutun_fre[i]=0;
        }

        for(int i=0;i<SIZE;i++){//burda 0 lar� saydik
            for(int j=0;j<SIZE;j++){
               if(dizi[i][j]==0) {
                    satir_fre[i]++;
                    sutun_fre[j]++;
               }
            }
        }

        int max=0;//en fazla olan satir veya sutunun de�erini tutucak
        int max_index=0;//en fazla olan sat�r veya s�t�nun indexi
        int satirmi=0;//max de�eri bir sat�r i�in mi sutun i�in mi 0-1
        for(int i=0;i<SIZE;i++){
            if(satir_fre[i]>max){
                max=satir_fre[i];
                max_index=i;
                satirmi=1;
            }
        }
        for(int i=0;i<SIZE;i++){
            if(sutun_fre[i]>max){
                max=sutun_fre[i];
                max_index=i;
                satirmi=0;
            }
        }

        int deter=0;
        if(satirmi){//e�er en fazla 0 bulunan line satir ise
            for(int i=0;i<SIZE;i++){
                if(dizi[max_index][i]!=0){
                    int kalan_dizi[SIZE-1][SIZE-1];//min�r
                    int satir_atlandi=0;
                    int sutun_atlandi=0;
                    for(int k=0;k<SIZE-1;k++){//kalan diziyi hesapl�yoruz min�r
                        if(k==max_index){//Aij nin sat�r�ysa atla
                            continue;
                            satir_atlandi=1;
                        }
                        for(int m=0;m<SIZE-1;m++){
                            if(m==i){//Aij nin sutunuysa atla
                                continue;
                                sutun_atlandi=1;
                            }
                            kalan_dizi[k][m]=dizi[k+satir_atlandi][m+sutun_atlandi];
                        }
                    }//minor hesab�


                    int katsayi=1;
                    if(i+max_index%2==1)katsayi=-1;//katsay� -1^i+j hsab�
                    SIZE--;
                    deter += (det(kalan_dizi))*(katsayi)*(dizi[max_index][i]);
                    printf("%d",deter);
                    SIZE++;
                }

            }
        }
        else{//e�er en fazla 0 bulunan line sutun ise
            for(int i=0;i<SIZE;i++){
                if(dizi[i][max_index]!=0){
                    int kalan_dizi[SIZE-1][SIZE-1];//min�r
                    int satir_atlandi=0;
                    int sutun_atlandi=0;
                    for(int k=0;k<SIZE-1;k++){//kalan diziyi hesapl�yoruz min�r
                        if(k==i){//Aij nin sat�r�ysa atla
                            continue;
                            satir_atlandi=1;
                        }
                        for(int m=0;m<SIZE-1;m++){
                            if(m=max_index){//Aij nin sutunuysa atla
                                continue;
                                sutun_atlandi=1;
                            }
                            kalan_dizi[k][m]=dizi[k+satir_atlandi][m+sutun_atlandi];
                        }
                    }//minor hesab�

                    int katsayi=1;
                    if(i+max_index%2==1)katsayi=-1;//katsay� -1^i+j hesab�
                    SIZE--;
                    deter+= katsayi*dizi[i][max_index]*det(kalan_dizi);
                    printf("%d",deter);
                    SIZE++;
                }
            }
        }//else
        return deter;
    }//else boyut 4 elemanl�dan b�y�kse
}

int main()
{
    printf("bir n sayisi giriniz : ");
    int n;scanf("%d",&n);
    SIZE =n;
    int matris[n][n];
    for(int i=0;i<n;i++){//matris init
       for(int j=0;j<n;j++){
            matris[i][j]=rand()%10;
            printf("%3d",matris[i][j]);
       }
       printf("\n");
    }
    printf("kodu yazdim hata yaptim 2*2 lik matriste caslisiyor fakat zaman yetmedi 10. soru icin cok zaman kaybettim bu haksizlikk bu yuzden bu soruyu tamamlayamadim \n");
    printf("determinant = %d",det(matris));

    //for(int i=0;i<)
    return 0;
}
