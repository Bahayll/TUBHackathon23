#include <stdio.h>
#include <stdlib.h>

#include <ctype.h>

// Karakter sayısını hesaplayan fonksiyon
void countChars() {
    FILE *file = fopen("pg45631.txt", "r");
    if (file == NULL)
        return;

    char c;
    int charArr[128] = {0};

    // Dosya sonuna kadar karakterleri oku ve say
    while ((c = fgetc(file)) != EOF) {
        charArr[c]++;
    }
    fclose(file);

    int biggestBH = 'A';  // 'A' ile başlatılır
    int biggestKH = 'a';  // 'a' ile başlatılır
    int biggestOther = 0; // 0 ile başlatılır
    // En fazla geçen büyük harfi, küçük harfi ve diðer karakteri bul
    for (int i = 0; i < 128; i++) {
        if (!isalpha(i) && i != 10 && i != 13 && i != 32 && charArr[i] > charArr[biggestOther]) {
            biggestOther = i;
        }

        if (isupper(i) && charArr[i] > charArr[biggestBH]) {
            biggestBH = i;
        }

        if (islower(i) && charArr[i] > charArr[biggestKH]) {
            biggestKH = i;
        }
    }

    printf("En fazla geçen büyük harf: %c(%d adet)\n", biggestBH, charArr[biggestBH]);
    printf("En fazla geçen küçük harf: %c(%d adet)\n", biggestKH, charArr[biggestKH]);
    printf("En fazla geçen diðer karakter: %c(%d adet)\n", biggestOther, charArr[biggestOther]);
}

int main()
{
    countChars();
    return 0;
}
