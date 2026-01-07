#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>

char gezegenler[9][15] ={
    "merkur","venus","dunya","mars","jupiter","saturn","uranus","neptun","pluton"
};

void serbest_dusme(double *g_ptr);
void yukari_atis(double *g_ptr);
void agirlik_deneyi(double *g_ptr);
void potansiyel_enerji(double *g_ptr);
void hidrostatik_basinc(double *g_ptr);
void arsimet_kaldirma(double *g_ptr);
void basit_sarkac(double *g_ptr);
void ip_gerilmesi(double *g_ptr);
void asansor_deneyi(double *g_ptr);

void menuyu_goster(){
    printf("\n*** UZAY SIMULASYONU DENEY MENUSU ***\n");
    printf("1. Serbest Dusme Deneyi\n");
    printf("2. Yukari Atis Deneyi\n");
    printf("3. Agirlik Deneyi\n");
    printf("4. Kutlecekimsel Potansiyel Enerji Deneyi\n");
    printf("5. Hidrostatik Basinc Deneyi\n");
    printf("6. Arsimet Kaldirma Kuvveti Deneyi\n");
    printf("7. Basit Sarkac Periyodu Deneyi\n");
    printf("8. Sabit Ip Gerilmesi Deneyi\n");
    printf("9. Asansor Deneyi\n");
    printf("-1. CIKIS\n");
    printf("Bir Secim Yapiniz: ");
}

int main(){
    char bilim_insani[50];
    int secim=0;

    double g_degerleri[9]={3.70, 8.87, 9.81, 3.71, 24.79, 10.44, 8.69, 11.15, 0.62};

    printf("*** Uzay Simulasyonu ***\n");
    printf("Bilim insani adi soyadi: ");
    fgets(bilim_insani, 50, stdin);

    printf("\nHosgeldiniz, Sayin %s. \n", bilim_insani);
    printf("Deneylerinizi simule etmek icin lutfen bir secim yapiniz.\n");

    while (secim != -1) {
        menuyu_goster();
        scanf("%d", &secim);

        if (secim == 1) serbest_dusme(g_degerleri);
        else if (secim == 2) yukari_atis(g_degerleri);
        else if (secim == 3) agirlik_deneyi(g_degerleri);
        else if (secim == 4) potansiyel_enerji(g_degerleri);
        else if (secim == 5) hidrostatik_basinc(g_degerleri);
        else if (secim == 6) arsimet_kaldirma(g_degerleri);
        else if (secim == 7) basit_sarkac(g_degerleri);
        else if (secim == 8) ip_gerilmesi(g_degerleri);
        else if (secim == 9) asansor_deneyi(g_degerleri);
        else if (secim == -1) {
            printf("Simulasyon sonlandiriliyor! %s\n", bilim_insani);
        }
        else {
            printf("Hatali secim! Lutfen listeden bir numara giriniz.\n");
        }
    }

return 0;
}

void serbest_dusme(double *g_ptr) {
    double t, h;
    printf("\n*** SERBEST DUSME DENEYI ***\n");
    printf("Dusus suresini giriniz (t [saniye]): ");
    scanf("%lf", &t);

    t = (t < 0) ? -t : t;

    printf("\nSonuclar (t = %.2f saniye icin):\n", t);
    printf("%-10s | %-15s\n", "Gezegen", "Mesafe (h)");
    printf("--------------------------\n");

    int i;
    for (i = 0; i < 9; i++) {
        double g = *(g_ptr + i);
        h = 0.5 * g * t * t;

        printf("%-10s : %.2f metre\n", gezegenler[i], h);
    }
}


void yukari_atis(double *g_ptr) {
    double v0, h_max;
    printf("\n*** YUKARI ATIS DENEYI ***\n");
    printf("Firlatma hizini giriniz (v0 [m/s]): ");
    scanf("%lf", &v0);

    v0 = (v0 < 0) ? -v0 : v0;

    printf("\nSonuclar (v0 = %.2f m/s icin):\n", v0);
    int i;
    for (i = 0; i < 9; i++) {
        double g = *(g_ptr + i);
        h_max = (v0 * v0) / (2 * g);
        printf("%-10s : Maks Yukseklik = %.2f metre\n", gezegenler[i], h_max);
    }
}


void agirlik_deneyi(double *g_ptr) {
    double m, G;
    printf("\n*** AGIRLIK DENEYI ***\n");
    printf("Cismin kutlesini giriniz (m [kg]): ");
    scanf("%lf", &m);

    m = (m < 0) ? -m : m;

    printf("\nSonuclar (m = %.2f kg icin):\n", m);
    int i;
    for (i = 0; i < 9; i++) {
        double g = *(g_ptr + i);
        G = m * g;
        printf("%-10s : Agirlik = %.2f Newton\n", gezegenler[i], G);
    }
}


void potansiyel_enerji(double *g_ptr) {
    double m, h, Ep;
    printf("\n*** POTANSIYEL ENERJI DENEYI ***\n");
    printf("Kutle (m [kg]): ");
    scanf("%lf", &m);
    printf("Yukseklik (h [m]): ");
    scanf("%lf", &h);

    m = (m < 0) ? -m : m;
    h = (h < 0) ? -h : h;

    printf("\nSonuclar:\n");
    int i;
    for (i = 0; i < 9; i++) {
        double g = *(g_ptr + i);
        Ep = m * g * h;
        printf("%-10s : Enerji = %.2f Joule\n", gezegenler[i], Ep);
    }
}


void hidrostatik_basinc(double *g_ptr) {
    double rho, h, P;
    printf("\n*** HIDROSTATIK BASINC DENEYI ***\n");
    printf("Sivi yogunlugu (rho [kg/m^3]): ");
    scanf("%lf", &rho);
    printf("Derinlik (h [m]): ");
    scanf("%lf", &h);

    rho = (rho < 0) ? -rho : rho;
    h = (h < 0) ? -h : h;

    printf("\nSonuclar:\n");
    int i;
    for (i = 0; i < 9; i++) {
        double g = *(g_ptr + i);
        P = rho * g * h;
        printf("%-10s : Basinc = %.2f Pascal (Pa)\n", gezegenler[i], P);
    }
}


void arsimet_kaldirma(double *g_ptr) {
    double rho, V, Fk;
    printf("\n*** ARSIMET KALDIRMA KUVVETI DENEYI ***\n");
    printf("Sivi yogunlugu (rho [kg/m^3]): ");
    scanf("%lf", &rho);
    printf("Batan Hacim (V [m^3]): ");
    scanf("%lf", &V);

    rho = (rho < 0) ? -rho : rho;
    V = (V < 0) ? -V : V;

    printf("\nSonuclar:\n");
    int i;
    for (i = 0; i < 9; i++) {
        double g = *(g_ptr + i);
        Fk = rho * g * V;
        printf("%-10s : Kaldirma Kuvveti = %.2f Newton\n", gezegenler[i], Fk);
    }
}


void basit_sarkac(double *g_ptr) {
    double L, T;
    double pi_sayisi = 3.1415926535;

    printf("\n*** BASIT SARKAC PERIYODU DENEYI ***\n");
    printf("Sarkac Uzunlugu (L [m]): ");
    scanf("%lf", &L);

    L = (L < 0) ? -L : L;

    printf("\nSonuclar:\n");
    int i;
    for (i = 0; i < 9; i++) {
        double g = *(g_ptr + i);
        T = 2 * pi_sayisi * sqrt(L / g);
        printf("%-10s : Periyot = %.2f saniye\n", gezegenler[i], T);
    }
}


void ip_gerilmesi(double *g_ptr) {
    double m, T;
    printf("\n*** SABIT IP GERILMESI DENEYI ***\n");
    printf("Asili Cismin Kutlesi (m [kg]): ");
    scanf("%lf", &m);

    m = (m < 0) ? -m : m;

    printf("\nSonuclar:\n");
    int i;
    for (i = 0; i < 9; i++) {
        double g = *(g_ptr + i);
        T = m * g;
        printf("%-10s : Gerilme = %.2f Newton\n", gezegenler[i], T);
    }
}


void asansor_deneyi(double *g_ptr) {
    double m, a, N;
    int durum;

    printf("\n*** ASANSOR DENEYI ***\n");
    printf("Cismin Kutlesi (m [kg]): ");
    scanf("%lf", &m);
    printf("Asansor Ivmesi (a [m/s^2]): ");
    scanf("%lf", &a);

    m = (m < 0) ? -m : m;
    a = (a < 0) ? -a : a;

    printf("Durum Seciniz:\n");
    printf("1. Yukari Hizlanma VEYA Asagi Yavaslama\n");
    printf("2. Asagi Hizlanma VEYA Yukari Yavaslama\n");
    printf("Secim (1 veya 2): ");
    scanf("%d", &durum);

    printf("\nSonuclar (Hissedilen Agirlik):\n");
    int i;
    for (i = 0; i < 9; i++) {
        double g = *(g_ptr + i);

        if (durum == 1) {
            N = m * (g + a);
        } else {
            N = m * (g - a);
        }

        printf("%-10s : Hissedilen Agirlik = %.2f Newton\n", gezegenler[i], N);
    }
}



