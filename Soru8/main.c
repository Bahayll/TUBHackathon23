#include <stdio.h>
#include <stdlib.h>


int main() {
    int sayi;
    printf("Bir sayi giriniz : ");
    scanf("%d", &sayi);

  int isUlonachi = 1; // Sayýmýzýn ulonachi sayýsý olup olmadýðýný tutan bir deðiþken belirledim

  int f0 = 1; // iki tane 1 deðiþkeni belirledim çünkü fibonaccim 2'den baþlamalý
  int f1 = 1;
  int fn; // fibonacci sayým

  while(1) { // Þartýmý saðlamayana kadar devam ettiriyorum
    fn = f0 + f1;
    f0 = f1;
    f1 = fn;
    if(fn > sayi){ // eðer sýradaki sayým benim girdiðim sayýdan büyükse döngüyü kýrýyorum
        break;
    }

    if(sayi % fn == 0){ // ya da þu an ki fibonacci sayým benim sayýmý bölüyorsa döngü gereksiz dönmesin diye döngüyü kýrýyorum
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
