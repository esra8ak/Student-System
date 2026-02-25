#include <stdio.h>
#include "ogrenci.h"

int main() {
    int secim;

    do {
        printf("\n1-Ekle\n2-Guncelle\n3-Sil\n4-Not Gir\n5-Ortalama\n6-Listele\n0-Cikis\n");
        scanf("%d", &secim);

        switch (secim) {
            case 1: ogrenci_ekle(); break;
            case 2: ogrenci_guncelle(); break;
            case 3: ogrenci_sil(); break;
            case 4: not_gir(); break;
            case 5: ortalama_hesapla(); break;
            case 6: ogrenci_listele(); break;
        }
    } while (secim != 0);

    return 0;
}
