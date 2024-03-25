#include <stdio.h>
#include <stdlib.h>

void enUzunBitonikAltDizi(int dizi[], int boyut) {
    int maxLength = 1;  // En uzun bitonik alt dizinin uzunluðu
    int start = 0;      // En uzun bitonik alt dizinin baþlangýç indeksi
    int end = 0;        // En uzun bitonik alt dizinin bitiþ indeksi

    int currentLength = 1;  // Mevcut bitonik alt dizinin uzunluðu
    int currentStart = 0;   // Mevcut bitonik alt dizinin baþlangýç indeksi

    int isAscending = 0;  // false / 0: Artan sýraya göre, true / 1: Azalan sýraya göre

    for (int i = 1; i < boyut; i++) {
        if (dizi[i] > dizi[i - 1]) { // Ýki dizi elemanýný karþýlaþtýrýyoruz
            if (isAscending == 1) {  // eðer azalan ise
                currentStart = i - 1; // bir önceki index üzerinden kontrol yapýlýyor
                currentLength = 2;  // ilk adým oldugu için baþlangýç olarak 2 þeklinde tanýmlýyoruz

            } else {
                currentLength++;  // azalan sýraya göreyse yine arttýr
            }
            isAscending = 0;
        } else if (dizi[i] < dizi[i - 1]) {  // eðer artan ise
            currentLength++;   // mevcut uzunluðu rttýr
            isAscending = 1;   // artan olarak ayarla
        } else {
            // Eðer iki ardýþýk eleman eþitse bitonik diziyi baþtan baþlat
            currentStart = i;
            currentLength = 1;
            isAscending = 0;
        }

        // Mevcut bitonik alt dizinin uzunluðu, en uzun olaný aþýyorsa güncelle
        if (currentLength > maxLength) {
            maxLength = currentLength;
            start = currentStart;
            end = i;
        }
    }

    printf("En uzun bitonik alt dizinin uzunlugu %d dir\n", maxLength);
    printf("Bu dizinin konumu %d ile %d arasindadir\n", start+1, end+1); //start ve end indeks 0 dan baþlar
}

int main() {

    /*
        Eðer elle girilmeyecekse

        int dizi[] = { 3, 5, 8, 4, 5, 9, 10, 8, 5, 3, 4, 11, 13, 12, 10, 5, 2, 5, 8, 11 };
        int boyut = sizeof(dizi)/sizeof(dizi[0]);

        þeklinde yapýnýz
    */


    int boyut;
    printf("Dizinin boyutunu giriniz : ");
    scanf("%d",&boyut);
    int dizi[boyut];

    for(int i = 0 ; i<boyut;i++){
            int sayi;
            printf("Dizi elemanini giriniz : ");
            scanf("%d",&sayi);
            dizi[i] = sayi;
    }

    enUzunBitonikAltDizi(dizi, boyut);

    return 0;
}
