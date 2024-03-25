#include <stdio.h>
#include <stdlib.h>


void dosyayaYaz(char *array); // dosyayayaz yazmak için kullanacaðýmýz fonksiyon prototipi -- mainden char dizisi göndereliecek burada pointer karþýlýlýyor.

int main()
{
    char metin[] = "Cumhuriyetin100.YILIKutluOlsun"; // Metinimizi bir karakter dizisi olarak tanýmladýk ve atama yaptýk.
    dosyayaYaz(metin); // metini verilen formatta file.txt dosyasýna yazmasý için soruda verilen prototipe uygun fonksiyonu çaðýrdýk
}


void dosyayaYaz(char *array)
{
     FILE *dosya = fopen("file.txt", "w"); // file.txt dosyasýný yazma modunda(w) açýyoruz eðer file.txt dosyasý yoksa oluþturur varsa içeriðinin üzerine yazar.

    //fopen den null dönerse bellek hatasý dosya hatasi oluþmuþtur kontrolünü gerçekleþtiriyoruz.
    if (dosya == NULL) {
        printf("Dosya acma hatasi!\n"); //
        return;
    }

     int metin_uzunluk=0; // metin uzunluðunu hazýr fonksiyon kullanmadan bulmak için bir deðiþken tanýmladýk.

    // Ýlk döngü : Metni her adýmda bir karakteri fazladan yazdýrarak file.txt dosyayasýna yaz
   //metin dizisini karþýlayan arrayi i deðiþkeniyele baþtan eof deðiþkenine \0 kadar tarayacaðýz.
     for (int i = 0; array[i] != '\0'; i++) {
        // Her adýmda bir karakteri yazdýr ve yeni satýra geç
        for (int j = 0; j <= i; j++) {
            fputc(array[j], dosya); //fputc fonksiyonu belirtilen karakteri dosyaya yazar

        }
        metin_uzunluk++; // metin uzunluðunu buluyoruz..
        fputc('\n', dosya);
    }


    // Ýkinci döngü: Metnin uzunluðunu kullanarak ters yönde yaz
    for (int i = metin_uzunluk - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            fputc(array[j], dosya);
        }
        if(i==0){ // dosya sonuna boşluk yazdırmaması için dosya sonuna gelindiğinde döngüyü kırsın
            break;
        }
        fputc('\n', dosya);
    }



    fclose(dosya); //dosyayý kapat
}
