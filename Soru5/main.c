#include <stdio.h>
#include <stdlib.h>
int SIZE;
int det(int dizi[SIZE][SIZE]){
    if(SIZE==2){//2 satýr 2 sutun olan bir kare matris ise;
       return (dizi[0][0])*(dizi[1][1]) - (dizi[0][1])*(dizi[1][0]); //a*d-b*c
    }//matris büyük ise
    else{
        int satir_fre[SIZE];//en çok 0 olan satýr veya sutunu arýyoruz
        int sutun_fre[SIZE];

        for(int i=0;i<SIZE;i++){//baþlangýç deðerlerini 0 verdik
            satir_fre[i]=0;
            sutun_fre[i]=0;
        }

        for(int i=0;i<SIZE;i++){//burda 0 larý saydik
            for(int j=0;j<SIZE;j++){
               if(dizi[i][j]==0) {
                    satir_fre[i]++;
                    sutun_fre[j]++;
               }
            }
        }

        int max=0;//en fazla olan satir veya sutunun deðerini tutucak
        int max_index=0;//en fazla olan satýr veya sütünun indexi
        int satirmi=0;//max deðeri bir satýr için mi sutun için mi 0-1
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
        if(satirmi){//eðer en fazla 0 bulunan line satir ise
            for(int i=0;i<SIZE;i++){
                if(dizi[max_index][i]!=0){
                    int kalan_dizi[SIZE-1][SIZE-1];//minör
                    int satir_atlandi=0;
                    int sutun_atlandi=0;
                    for(int k=0;k<SIZE-1;k++){//kalan diziyi hesaplýyoruz minör
                        if(k==max_index){//Aij nin satýrýysa atla
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
                    }//minor hesabý


                    int katsayi=1;
                    if(i+max_index%2==1)katsayi=-1;//katsayý -1^i+j hsabý
                    SIZE--;
                    deter += (det(kalan_dizi))*(katsayi)*(dizi[max_index][i]);
                    printf("%d",deter);
                    SIZE++;
                }

            }
        }
        else{//eðer en fazla 0 bulunan line sutun ise
            for(int i=0;i<SIZE;i++){
                if(dizi[i][max_index]!=0){
                    int kalan_dizi[SIZE-1][SIZE-1];//minör
                    int satir_atlandi=0;
                    int sutun_atlandi=0;
                    for(int k=0;k<SIZE-1;k++){//kalan diziyi hesaplýyoruz minör
                        if(k==i){//Aij nin satýrýysa atla
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
                    }//minor hesabý

                    int katsayi=1;
                    if(i+max_index%2==1)katsayi=-1;//katsayý -1^i+j hesabý
                    SIZE--;
                    deter+= katsayi*dizi[i][max_index]*det(kalan_dizi);
                    printf("%d",deter);
                    SIZE++;
                }
            }
        }//else
        return deter;
    }//else boyut 4 elemanlýdan büyükse
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
