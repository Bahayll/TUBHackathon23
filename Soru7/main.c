#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int maxWhistleBlow = 10;

// Fonksiyon: Bir sayının asal olup olmadığını kontrol eder
int isPrime(int number) {
    // 1 ve 1'den küçük sayılar asal değildir
    if (number <= 1) {
        return 0;
    }
    // 2 ve 3 asal sayılardır
    if (number == 2 || number == 3) {
        return 1;
    }

    if (number % 2 == 0 || number % 3 == 0) {
        return 0;
    }

    // Sayının kareköküne kadar olan bölenler kontrol edilir
    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return 0;
        }
    }

    return 1;
}

// Fonksiyon: Askerlerin hizasını belirler
void setOrder(char arr[], int n) {
    for (int i = 0; i < n; i++) {
        // Eğer indis bir asal sayıya karşılık geliyorsa, askeri 'R' (sağa) yerleştir, aksi takdirde 'L' (sola) yerleştir
        if (isPrime(i + 1))
            arr[i] = 'R';
        else
            arr[i] = 'L';
    }
}

// Fonksiyon: Asker hizasını ekrana yazdırır
void printOrder(char arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%c ", arr[i]); // Karakteri yazdır
    }
    puts(""); // Yeni satıra geç
}

// Fonksiyon: Düdük üfleme
int blowWhistle(char arr[], int n) {
    static int whistleBlown = 0;
    if (whistleBlown >= maxWhistleBlow)
        return 0;

    // İki farklı askerin yer değiştirmesi için rastgele indisler seçilir
    int soldierOne = rand() % n;
    int soldierTwo = rand() % n;
    while (soldierTwo == soldierOne) {
        soldierTwo = rand() % n;
    }

    // İki askeri yer değiştirmek için
    if (arr[soldierOne] != arr[soldierTwo]) {
        switch (arr[soldierOne]) {
        case 'L':
            arr[soldierOne] = 'R';
            arr[soldierTwo] = 'L';
            break;
        case 'R':
            arr[soldierOne] = 'L';
            arr[soldierTwo] = 'R';
            break;
        }
    }

    whistleBlown++;
    return 1;
}

int main() {
    srand(time(NULL));
    /*
    int n;
    printf("Asker sayısını girin (0'dan büyük): ");
    scanf("%d", &n);

    while(n <= 0 ){
        printf("Asker sayısını girin (0'dan büyük): ");
        scanf("%d", &n);
    }
    */
    int n = 1389;

    char arr[n];
    setOrder(arr, n);
    printOrder(arr, n);

    while (blowWhistle(arr, n)) {
        printOrder(arr, n);
    }

    return 0;
}
