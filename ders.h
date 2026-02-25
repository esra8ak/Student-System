#ifndef DERS_H
#define DERS_H

typedef struct {
    int sinav1;
    int sinav2;
    int sinav3;
} Ders;

typedef struct {
    Ders matematik;
    Ders fizik;
    Ders kimya;
} Notlar;

float ders_ortalamasi(Ders d);

#endif
