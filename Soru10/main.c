#include <stdio.h>
#include <stdlib.h>


void daire_merkezi_bul(int x, int y, int r) {
    // F(p) = x^2 + y^2 - r^2
    int F_p = x * x + y * y - r * r;

    if (F_p == 0) {
        printf("Nokta çember çevresi üzerindedir.\n");
        printf("(%d, %d) (%d, %d) (%d, %d) (%d, %d)\n",
               x + r, y, x - r, y, x, y + r, x, y - r);
    }
    else  {
    if (F_p < 0) {
        printf("Nokta dairenin içindedir.\n");
        printf("(%d, %d) (%d, %d) (%d, %d) (%d, %d)\n",
               x + r, y, x - r, y, x, y + r, x, y - r);
    }
    else {
        printf("Nokta dairenin dýþýndadýr.\n");
        printf("(%d, %d) (%d, %d) (%d, %d) (%d, %d)\n",
               x + r, y, x - r, y, x, y + r, x, y - r);
    }

    }
}

int main() {
    // Örnek girdiler
    printf("Noktanin x ve y koordinatlarini giriniz : ");
    int x,y,yaricap;
    int nokta[]={ scanf("%d",&x),scanf("%d",&y)};
   printf("Yaricapi giriniz= ");
    scanf("%d",&yaricap);

    // Örnek çýktýlar
    daire_merkezi_bul(nokta[0], nokta[1], yaricap);


    return 0;
}
