#ifndef OGRENCI_H
#define OGRENCI_H

#include "ders.h"

#define MAX_OGRENCI 50

typedef struct {
    char ad[30];
    char soyad[30];
    char mail[50];
    int okulNo;
    Notlar notlar;
} Ogrenci;

extern Ogrenci ogrenciler[MAX_OGRENCI];
extern int ogrenciSayisi;

void ogrenci_ekle();
void ogrenci_guncelle();
void ogrenci_sil();
void not_gir();
void ortalama_hesapla();
void ogrenci_listele();

#endif
