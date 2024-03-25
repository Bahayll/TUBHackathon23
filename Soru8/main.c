#include <stdio.h>
#include <stdlib.h>


int main() {
    int sayi;
    printf("Bir sayi giriniz : ");
    scanf("%d", &sayi);

  int isUlonachi = 1; // Say�m�z�n ulonachi say�s� olup olmad���n� tutan bir de�i�ken belirledim

  int f0 = 1; // iki tane 1 de�i�keni belirledim ��nk� fibonaccim 2'den ba�lamal�
  int f1 = 1;
  int fn; // fibonacci say�m

  while(1) { // �art�m� sa�lamayana kadar devam ettiriyorum
    fn = f0 + f1;
    f0 = f1;
    f1 = fn;
    if(fn > sayi){ // e�er s�radaki say�m benim girdi�im say�dan b�y�kse d�ng�y� k�r�yorum
        break;
    }

    if(sayi % fn == 0){ // ya da �u an ki fibonacci say�m benim say�m� b�l�yorsa d�ng� gereksiz d�nmesin diye d�ng�y� k�r�yorum
        isUlonachi = 0;
        printf("%d sayisi %d sayisini tam boldugu icin ", fn,sayi);
        break;
    }
  }
  if(isUlonachi){
    printf(" \n %d sayisi bir Ulonachi sayidir",sayi);
  }else{
    printf("%d sayisi bir Ulonachi sayi degildir\n ",sayi);
  }
  return 0;
}
