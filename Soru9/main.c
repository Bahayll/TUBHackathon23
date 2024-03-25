#include <stdio.h>
#include <stdlib.h>

int findPathRecursive(int points[], int arrSize, int startPoint, int currentPoint, int legalMove) {
    // Eðer mevcut nokta son noktaysa, robot sona ulaşabilir
    if (currentPoint == arrSize - 1)
        return 1;

    // Mevcut noktadan başlayarak adımları dolaş
    for (int i = currentPoint; i < arrSize - 1; i++) {
        // Robotun legalMove'a bağlı olarak bir sonraki adıma geçip geçemediğini kontrol et
        if (points[startPoint] + legalMove - points[i] >= -1 &&
            points[startPoint] + legalMove - points[i] <= 1) {
            // Mevcut adımdan başlayarak yolu recursive olarak kontrol et
            if (findPathRecursive(points, arrSize, i, i + 1, points[i] - points[startPoint]))
                return 1;
        }
    }

    // Eðer geçerli bir hareket bulunamazsa, 0 döndür
    return 0;
}

int main() {
    /*
    int arrSize;
    printf("Enter the number of points( > 0): ");
    scanf("%d", &arrSize);
    while(arrSize < 0){
        printf("Error! Enter the number of points( > 0): ");
        scanf("%d", &arrSize);
    }
    int points[arrSize];
    for(int i = 0; i < arrSize; i++){
        printf("Enter the %d. point( > 0 and the previous point): ", i+1);
        scanf("%d", &points[i]);
        while(points[i] < 0 || (i > 0 && points[i] < points[i-1]) ){
            printf("Error! Enter the %d. point( > 0 and the previous point): ", i+1);
            scanf("%d", &points[i]);
        }
    }*/
    // Örnek giriş
    int arrSize = 8;
    //int points[8] = {0,1,3,5,6,8,12,17}
    int points[8] = {0, 1, 2, 3, 4, 8, 9, 11};

    // Başlangıç noktasýndan sonraki noktaya geçebilen geçerli bir yol olup olmadığını kontrol et
    if (findPathRecursive(points, arrSize, 0, 1, points[1] - points[0])) {
        printf("True!\n");
    } else { // Geçerli bir yol bulunamazsa False yazdır
        printf("False!\n");
    }

    return 0;
}
