#include <stdio.h>
#include <string.h>

void giris()
{
    char ad[50], sifre[50];

    while (1)
    {
        printf("Kullanici adini giriniz: ");
        scanf("%s", ad);
        printf("Kullanici sifresini giriniz: ");
        scanf("%s", sifre);

        if (strcmp(ad, "ruhi") == 0 && strcmp(sifre, "ruhi123") == 0)
        {
            printf("Kullanici adi ve sifre dogru\n");
            break;
        }
        else
            printf("Kullanici adi veya sifre yanlis!\n");
    }
}

int main() {
    float ucretler[50];
    int binisDurak, inisDurak, tarife;
    int index = 0;
    float birimFiyat = 0.2;
    char ad[50], sifre[50], devam[10];

    float durakDegerleri[8] = {0.0, 10.8, 28.1, 36.5, 48.0, 62.8, 69.1, 79.3};

    giris();

    while (1)
    {
        while (1)
        {
            printf("Binmek istediginiz duragi seciniz\n1- Yenikoy\n2- Kotekli\n3- Yogurtcu Parki\n4- KYK\n"
                   "5- Egitim Fakultesi\n6- Hastane\n7- Tip fakultesi\n8- Turgutreis\n");
            scanf("%d", &binisDurak);

            if (binisDurak >= 1 && binisDurak <= 8)
                {
                    break;
                }
            else
                {
                    printf("Gecersiz durak! Lutfen 1 ile 8 arasinda bir durak seciniz.\n");
                }
        }

        while (1)
        {
            printf("Inmek istediginiz duragi seciniz\n1- Yenikoy\n2- Kotekli\n3- Yogurtcu Parki\n4- KYK\n"
                   "5- Egitim Fakultesi\n6- Hastane\n7- Tip fakultesi\n8- Turgutreis\n");
            scanf("%d", &inisDurak);

            if (inisDurak >= 1 && inisDurak <= 8 && inisDurak != binisDurak)
                {
                    break;
                }
            else
                {
                    printf("Gecersiz durak! Lutfen 1 ile 8 arasinda bir durak seciniz.\n");
               }
        }

        float fark = durakDegerleri[inisDurak - 1] - durakDegerleri[binisDurak - 1];
        if (fark < 0)
            {
                fark = -fark;
            }

        printf("65 yas ustu icin 1'e\nOgrenci icin 2'ye\nNormal icin 3'e basiniz\n ");
        scanf("%d", &tarife);

        float toplamUcret = fark * birimFiyat;

        switch (tarife)
        {
            case 1:
                printf("65 yas ustu tarifeyi sectiniz. Toplam ucretiniz 0 TL olucaktir\n");
                toplamUcret = 0;
                break;
            case 2:
                printf("Ogrenci tarifesini sectiniz. Yuzde 25 indirim kazandiniz\n");
                toplamUcret *= 0.75;
                break;
            case 3:
                printf("Normal tarifeyi sectiniz. Herhangi bir indirim uygulanmicaktir.\n");
                break;
            default:
                printf("Gecersiz tarife! Normal tarifeye geciliyor.\n");
        }

        ucretler[index++] = toplamUcret;
        printf("Bu yolculuk icin toplam ucret: %.2f TL\n\n", toplamUcret);


        FILE *dosya = fopen("yolculuk_ucretleri.txt", "a");
        if (dosya != NULL) {
            fprintf(dosya, "Yolculuk %d - Ucret: %.2f TL\n", index, toplamUcret);
            fclose(dosya);
        } else {
            printf("Dosya acilamadi!\n");
        }

        while (1) {
            printf("Devam etmek istiyorsaniz 'E', cikmak istiyorsaniz 'H' giriniz: ");
            scanf("%s", devam);
            if (strcmp(devam, "H") == 0 || strcmp(devam, "h") == 0)
                {
                printf("Cikis yapiliyor...\n");
                float genelToplam = 0;
                for (int i = 0; i < index; i++)
                    {
                    genelToplam += ucretler[i];
                    }
                printf("Tum yolculuklar icin toplam ucret: %.2f TL\n", genelToplam);
                return 0;
                }
                    else if (strcmp(devam, "E") == 0 || strcmp(devam, "e") == 0)
                    {
                        break;
                    }
                    else
                    {
                        printf("Gecersiz deger girdiniz! Lutfen 'E' veya 'H' giriniz.\n");
                    }
        }
    }

}
