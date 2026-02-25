#include <stdio.h>
#include <string.h>
#include "ogrenci.h"

Ogrenci ogrenciler[MAX_OGRENCI];
int ogrenciSayisi = 0;

/* =====================
   OGRENCI SEC
   ===================== */
int ogrenci_sec() {
    int i;

    if (ogrenciSayisi == 0) {
        printf("Hic ogrenci yok!\n");
        return -1;
    }

    for (i = 0; i < ogrenciSayisi; i++) {
        printf("%d - %s %s (No:%d)\n",
               i,
               ogrenciler[i].ad,
               ogrenciler[i].soyad,
               ogrenciler[i].okulNo);
    }

    printf("Secim: ");
    scanf("%d", &i);

    if (i < 0 || i >= ogrenciSayisi) {
        printf("Gecersiz secim!\n");
        return -1;
    }

    return i;
}

/* =====================
   OGRENCI EKLE
   ===================== */
void ogrenci_ekle() {
    if (ogrenciSayisi >= MAX_OGRENCI) return;

    Ogrenci *o = &ogrenciler[ogrenciSayisi];

    printf("Ad: ");
    scanf("%s", o->ad);

    printf("Soyad: ");
    scanf("%s", o->soyad);

    printf("Mail: ");
    scanf("%s", o->mail);

    printf("Okul No: ");
    scanf("%d", &o->okulNo);

    o->notlar.matematik = (Ders){0, 0, 0};
    o->notlar.fizik     = (Ders){0, 0, 0};
    o->notlar.kimya     = (Ders){0, 0, 0};

    ogrenciSayisi++;
    printf("Ogrenci eklendi.\n");
}

/* =====================
   OGRENCI GUNCELLE
   ===================== */
void ogrenci_guncelle() {
    int i = ogrenci_sec();
    if (i == -1) return;

    int secim;
    printf("\n1-Ogrenci Bilgileri\n2-Ders Notlari\nSecim: ");
    scanf("%d", &secim);

    /* ---- Ogrenci bilgileri ---- */
    if (secim == 1) {
        printf("Yeni Ad: ");
        scanf("%s", ogrenciler[i].ad);

        printf("Yeni Soyad: ");
        scanf("%s", ogrenciler[i].soyad);

        printf("Yeni Mail: ");
        scanf("%s", ogrenciler[i].mail);

        printf("Ogrenci bilgileri guncellendi.\n");
    }

    /* ---- Ders notlari ---- */
    else if (secim == 2) {
        int ders;
        printf("1-Matematik  2-Fizik  3-Kimya: ");
        scanf("%d", &ders);

        Ders *d = NULL;

        if (ders == 1)
            d = &ogrenciler[i].notlar.matematik;
        else if (ders == 2)
            d = &ogrenciler[i].notlar.fizik;
        else if (ders == 3)
            d = &ogrenciler[i].notlar.kimya;
        else
            return;

        printf("Yeni Sinav 1: ");
        scanf("%d", &d->sinav1);

        printf("Yeni Sinav 2: ");
        scanf("%d", &d->sinav2);

        printf("Yeni Sinav 3: ");
        scanf("%d", &d->sinav3);

        printf("Ders notlari guncellendi.\n");
    }
}

/* =====================
   OGRENCI SIL
   ===================== */
void ogrenci_sil() {
    int i = ogrenci_sec();
    if (i == -1) return;

    for (; i < ogrenciSayisi - 1; i++) {
        ogrenciler[i] = ogrenciler[i + 1];
    }

    ogrenciSayisi--;
    printf("Ogrenci silindi.\n");
}

/* =====================
   NOT GIR
   ===================== */
void not_gir() {
    int i = ogrenci_sec();
    if (i == -1) return;

    int secim;
    printf("1-Matematik  2-Fizik  3-Kimya: ");
    scanf("%d", &secim);

    Ders *d = NULL;

    if (secim == 1)
        d = &ogrenciler[i].notlar.matematik;
    else if (secim == 2)
        d = &ogrenciler[i].notlar.fizik;
    else if (secim == 3)
        d = &ogrenciler[i].notlar.kimya;
    else
        return;

    printf("Sinav 1: ");
    scanf("%d", &d->sinav1);

    printf("Sinav 2: ");
    scanf("%d", &d->sinav2);

    printf("Sinav 3: ");
    scanf("%d", &d->sinav3);

    printf("Notlar girildi.\n");
}

/* =====================
   ORTALAMA
   ===================== */
void ortalama_hesapla() {
    int i = ogrenci_sec();
    if (i == -1) return;

    int secim;
    printf("1-Matematik  2-Fizik  3-Kimya: ");
    scanf("%d", &secim);

    Ders d;

    if (secim == 1)
        d = ogrenciler[i].notlar.matematik;
    else if (secim == 2)
        d = ogrenciler[i].notlar.fizik;
    else if (secim == 3)
        d = ogrenciler[i].notlar.kimya;
    else
        return;

    printf("Ortalama: %.2f\n", ders_ortalamasi(d));
}

/* =====================
   LISTELE
   ===================== */
void ogrenci_listele() {
    for (int i = 0; i < ogrenciSayisi; i++) {
        printf("\n%s %s (No:%d)\n",
               ogrenciler[i].ad,
               ogrenciler[i].soyad,
               ogrenciler[i].okulNo);

        printf("Mat: %d %d %d\n",
               ogrenciler[i].notlar.matematik.sinav1,
               ogrenciler[i].notlar.matematik.sinav2,
               ogrenciler[i].notlar.matematik.sinav3);

        printf("Fiz: %d %d %d\n",
               ogrenciler[i].notlar.fizik.sinav1,
               ogrenciler[i].notlar.fizik.sinav2,
               ogrenciler[i].notlar.fizik.sinav3);

        printf("Kim: %d %d %d\n",
               ogrenciler[i].notlar.kimya.sinav1,
               ogrenciler[i].notlar.kimya.sinav2,
               ogrenciler[i].notlar.kimya.sinav3);
    }
}
