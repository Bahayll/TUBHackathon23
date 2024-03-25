#include <stdio.h>
#include <stdlib.h>

void enUzunBitonikAltDizi(int dizi[], int boyut) {
    int maxLength = 1;  // En uzun bitonik alt dizinin uzunlu�u
    int start = 0;      // En uzun bitonik alt dizinin ba�lang�� indeksi
    int end = 0;        // En uzun bitonik alt dizinin biti� indeksi

    int currentLength = 1;  // Mevcut bitonik alt dizinin uzunlu�u
    int currentStart = 0;   // Mevcut bitonik alt dizinin ba�lang�� indeksi

    int isAscending = 0;  // false / 0: Artan s�raya g�re, true / 1: Azalan s�raya g�re

    for (int i = 1; i < boyut; i++) {
        if (dizi[i] > dizi[i - 1]) { // �ki dizi eleman�n� kar��la�t�r�yoruz
            if (isAscending == 1) {  // e�er azalan ise
                currentStart = i - 1; // bir �nceki index �zerinden kontrol yap�l�yor
                currentLength = 2;  // ilk ad�m oldugu i�in ba�lang�� olarak 2 �eklinde tan�ml�yoruz

            } else {
                currentLength++;  // azalan s�raya g�reyse yine artt�r
            }
            isAscending = 0;
        } else if (dizi[i] < dizi[i - 1]) {  // e�er artan ise
            currentLength++;   // mevcut uzunlu�u rtt�r
            isAscending = 1;   // artan olarak ayarla
        } else {
            // E�er iki ard���k eleman e�itse bitonik diziyi ba�tan ba�lat
            currentStart = i;
            currentLength = 1;
            isAscending = 0;
        }

        // Mevcut bitonik alt dizinin uzunlu�u, en uzun olan� a��yorsa g�ncelle
        if (currentLength > maxLength) {
            maxLength = currentLength;
            start = currentStart;
            end = i;
        }
    }

    printf("En uzun bitonik alt dizinin uzunlugu %d dir\n", maxLength);
    printf("Bu dizinin konumu %d ile %d arasindadir\n", start+1, end+1); //start ve end indeks 0 dan ba�lar
}

int main() {

    /*
        E�er elle girilmeyecekse

        int dizi[] = { 3, 5, 8, 4, 5, 9, 10, 8, 5, 3, 4, 11, 13, 12, 10, 5, 2, 5, 8, 11 };
        int boyut = sizeof(dizi)/sizeof(dizi[0]);

        �eklinde yap�n�z
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
