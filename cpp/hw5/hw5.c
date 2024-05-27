#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_BOOKS 1000

// Kitap yapısı
typedef struct {
    char kitap_adi[MAX_LINE_LENGTH];
    char yazar_adi[MAX_LINE_LENGTH];
    char yayin_yili[MAX_LINE_LENGTH];
    char ISBN[MAX_LINE_LENGTH];
} Kitap;

// Dosyadan verileri okuyup uygun bir veri yapısına aktaran fonksiyon
int dosyadan_veri_oku(const char *dosya_adi, Kitap kitaplar[], int *kitap_sayisi) {
    FILE *dosya = fopen(dosya_adi, "r");
    if (dosya == NULL) {
        printf("Dosya acilamadi.\n");
        return -1;
    }

    int i = 0;
    while (fscanf(dosya, "%[^,],%[^,],%[^,],%[^\n]\n", kitaplar[i].kitap_adi, kitaplar[i].yazar_adi, kitaplar[i].yayin_yili, kitaplar[i].ISBN) == 4) {
        i++;
    }
    *kitap_sayisi = i;

    fclose(dosya);
    return 0;
}

// Lineer arama işlevi
Kitap *lineer_arama(Kitap kitaplar[], int kitap_sayisi, const char *anahtar) {
    for (int i = 0; i < kitap_sayisi; i++) {
        if (strstr(kitaplar[i].kitap_adi, anahtar) || strstr(kitaplar[i].yazar_adi, anahtar)) {
            return &kitaplar[i];
        }
    }
    return NULL;
}

// Hash tablosu ile arama işlevi
Kitap *hash_tablosu_ile_arama(Kitap kitaplar[], int kitap_sayisi, const char *anahtar) {
    // Basit bir hash fonksiyonu: anahtarın ilk harfinin ASCII değerini kullan
    int hash_index = (int)(anahtar[0]) % kitap_sayisi;

    for (int i = hash_index; i < kitap_sayisi; i++) {
        if (strstr(kitaplar[i].kitap_adi, anahtar) || strstr(kitaplar[i].yazar_adi, anahtar)) {
            return &kitaplar[i];
        }
    }

    // Başa dön ve geri kalanı kontrol et
    for (int i = 0; i < hash_index; i++) {
        if (strstr(kitaplar[i].kitap_adi, anahtar) || strstr(kitaplar[i].yazar_adi, anahtar)) {
            return &kitaplar[i];
        }
    }

    return NULL;
}

// Ana program
int main() {
    Kitap kitaplar[MAX_BOOKS];
    int kitap_sayisi = 0;

    if (dosyadan_veri_oku("tr_books.csv", kitaplar, &kitap_sayisi) == -1) {
        return -1;
    }

    char secim;
    char anahtar[MAX_LINE_LENGTH];
    Kitap *sonuc;

    while (1) {
        printf("\nArama secenekleri:\n");
        printf("1. Kitap adiyla arama yap\n");
        printf("2. Yazar adiyla arama yap\n");
        printf("3. Cikis\n");

        printf("Lutfen yapmak istediginiz islemi secin: ");
        scanf(" %c", &secim);

        switch (secim) {
            case '1':
                printf("Aramak istediginiz kitabin adini girin: ");
                scanf(" %[^\n]", anahtar);
                sonuc = lineer_arama(kitaplar, kitap_sayisi, anahtar);
                if (sonuc != NULL) {
                    printf("Kitap bulundu:\n");
                    printf("Kitap adi: %s\nYazar adi: %s\nYayin yili: %s\nISBN: %s\n", sonuc->kitap_adi, sonuc->yazar_adi, sonuc->yayin_yili, sonuc->ISBN);
                } else {
                    printf("Kitap bulunamadi.\n");
                }
                break;
            case '2':
                printf("Aramak istediginiz yazarin adini girin: ");
                scanf(" %[^\n]", anahtar);
                sonuc = hash_tablosu_ile_arama(kitaplar, kitap_sayisi, anahtar);
                if (sonuc != NULL) {
                    printf("Yazar bulundu:\n");
                    printf("Kitap adi: %s\nYazar adi: %s\nYayin yili: %s\nISBN: %s\n", sonuc->kitap_adi, sonuc->yazar_adi, sonuc->yayin_yili, sonuc->ISBN);
                } else {
                    printf("Yazar bulunamadi.\n");
                }
                break;
            case '3':
                printf("Programdan cikiliyor...\n");
                return 0;
            default:
                printf("Gecersiz secim. Lutfen tekrar deneyin.\n");
        }
    }

    return 0;
}
