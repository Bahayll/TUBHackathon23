#include <stdio.h>
#include <stdlib.h>


void daire_merkezi_bul(int x, int y, int r) {
    // F(p) = x^2 + y^2 - r^2
    int F_p = x * x + y * y - r * r;

    if (F_p == 0) {
        printf("Nokta �ember �evresi �zerindedir.\n");
        printf("(%d, %d) (%d, %d) (%d, %d) (%d, %d)\n",
               x + r, y, x - r, y, x, y + r, x, y - r);
    }
    else  {
    if (F_p < 0) {
        printf("Nokta dairenin i�indedir.\n");
        printf("(%d, %d) (%d, %d) (%d, %d) (%d, %d)\n",
               x + r, y, x - r, y, x, y + r, x, y - r);
    }
    else {
        printf("Nokta dairenin d���ndad�r.\n");
        printf("(%d, %d) (%d, %d) (%d, %d) (%d, %d)\n",
               x + r, y, x - r, y, x, y + r, x, y - r);
    }

    }
}

int main() {
    // �rnek girdiler
    printf("Noktanin x ve y koordinatlarini giriniz : ");
    int x,y,yaricap;
    int nokta[]={ scanf("%d",&x),scanf("%d",&y)};
   printf("Yaricapi giriniz= ");
    scanf("%d",&yaricap);

    // �rnek ��kt�lar
    daire_merkezi_bul(nokta[0], nokta[1], yaricap);


    return 0;
}
