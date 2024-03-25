#include <stdlib.h>

//fonksiyon prototipleri
void katsayilar_al(int dizi[],size_t boyut); //klavyeden katsayiları alıp bir dizide sırayla tutmak için bir fonksiyon tanımladık
                                             //buradaki dizi katsayılar dizisidir boyut ise dizinin boyutudur ve boyut=>0 olacağı için tipini size_t yaptık

int polinom_turevi_hesapla(int dizi[],size_t boyut,int derece); // polinomun türevini hesaplatmak için bir fonksiyon prototipi oluþturduk dizi--katsayilar dizisi boyutu--katsayilar dizisi boyutu
                                                                //derece ise polinomun derecesidir.

void polinom_yazdir(const int dizi[], size_t boyut);//girilen polinomu görüntülemek ve türev doğruluğunu görmek için  bir fonksiyon prototipi oluşturduk.

                                                    //const dizi yazmamızın nedeni dizide herhangi bir değişiklik yapmayacağımız içindir

int main()
{
     int polinom_derecesi; // klavyeden katsayıları aldığımız zaman katsayilar dizinin boyutunu belirlemek içinde kullanacağız
     printf("Polinom derecesini giriniz= ");
     scanf("%d",&polinom_derecesi);

     size_t boyut=polinom_derecesi+1;// polinom derecesinin 1 fazlası kadar katsayı olacaktır.

    int katsayilar[boyut];//katsayıları sıralı bir şekilde bir dizide tutmak için int bir dizi tanımladık.

    katsayilar_al(katsayilar, boyut); // katsayıları bir diziye toplamak için fonksiyonla katsayiları alacağız diziler adres üzerine işlem yaptıkları için geri
                                      // değer döndürmeden dizi elamanları kalıcı olacaktır.


    polinom_yazdir(katsayilar,boyut);  // polinomu yazdıracağız

    polinom_turevi_hesapla(katsayilar,boyut,polinom_derecesi); // polinom türevini hesaplayıp yazdıracağız


}



//polinom katsayilarýný almak için fonksiyon
void katsayilar_al(int dizi[],size_t boyut){
    printf("Polinomun katsayilarini sirasiyla giriniz :\n");
    for(int i=0;i<boyut;i++){
        printf("a%d:",i);
        scanf("%d",&dizi[i]); // katsayilari sırayla diziye atıyoruz
    }
}

//polinom türevini almak ve istenilen formatta yazdýrmak için bir fonksiyon
int polinom_turevi_hesapla(int dizi[],size_t boyut,int derece){
    printf("Polinomun Turevi: ");
    for (int i = 1; i < boyut; i++) {
        printf("%dx^%d", i * dizi[i], i - 1); // katsayı ve dizinin derecesini alıyoruz ve dereceyi 1 azaltıyoruz
        if (i < boyut - 1 && dizi[i + 1] > 0) {
            printf(" + ");
        } else if (i < boyut - 1 && dizi[i + 1] < 0) {
            printf(" - ");
        }
    }
    printf("\n");
}

// polinomu yazdırmak ve türev doğruluğunu terminalde görüntülemek için bir fonksiyon.
void polinom_yazdir(const int dizi[], size_t boyut) {
    printf("Polinom: ");
    if(dizi[0] != 0)
        printf("%d", dizi[0]);
    for (int i = 1; i < boyut-1; i++) {
        if(dizi[i] == 1){
            printf(" + x^%d", i);
        }
        else if(dizi[i] == -1){
            printf(" - x^%d", i);
        }
        else if(dizi[i] > 0){
            printf(" + %dx^%d", dizi[i], i);
        }else if(dizi[i] < 0){
            printf(" - %dx^%d", -1*dizi[i], i);
        }
    }
    if(dizi[boyut-1] == 1)
        printf(" + x^%d", boyut-1);
    else if(dizi[boyut-1] == -1)
        printf(" - x^%d", boyut-1);
    else if(dizi[boyut-1] > 0)
        printf(" + %dx^%d", dizi[boyut-1], boyut-1);
    else if(dizi[boyut-1] < 0)
        printf(" - %dx^%d", -1*dizi[boyut-1], boyut-1);

    printf("\n");
}
