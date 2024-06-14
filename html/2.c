#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STANOVNIKA 1000
#define MAX_DUZINA 50

typedef struct {
    int sifra;
    char ime[MAX_DUZINA];
    char vrsta[MAX_DUZINA];
    int starost;
    char datum_rodjenja[MAX_DUZINA];
    int godina_dolaska;
    char prebivaliste[MAX_DUZINA];
    char hrana[MAX_DUZINA];
    char veterinar[MAX_DUZINA];
    float troskovi_odrzavanja;
} Stanovnik;

Stanovnik stanovnici[MAX_STANOVNIKA];
int broj_stanovnika = 0;

void ucitajStanovnike(const char *ime_datoteke) {
    FILE *file = fopen(ime_datoteke, "r");
    if (!file) {
        printf("Greska pri otvaranju datoteke %s\n", ime_datoteke);
        return;
    }
    while (fscanf(file, "%d %s %s %d %s %d %s %s %s %f",
                  &stanovnici[broj_stanovnika].sifra,
                  stanovnici[broj_stanovnika].ime,
                  stanovnici[broj_stanovnika].vrsta,
                  &stanovnici[broj_stanovnika].starost,
                  stanovnici[broj_stanovnika].datum_rodjenja,
                  &stanovnici[broj_stanovnika].godina_dolaska,
                  stanovnici[broj_stanovnika].prebivaliste,
                  stanovnici[broj_stanovnika].hrana,
                  stanovnici[broj_stanovnika].veterinar,
                  &stanovnici[broj_stanovnika].troskovi_odrzavanja) != EOF) {
        broj_stanovnika++;
    }
    fclose(file);
}

void sacuvajStanovnike(const char *ime_datoteke) {
    FILE *file = fopen(ime_datoteke, "w");
    if (!file) {
        printf("Greska pri otvaranju datoteke %s\n", ime_datoteke);
        return;
    }
    for (int i = 0; i < broj_stanovnika; i++) {
        fprintf(file, "%d %s %s %d %s %d %s %s %s %.2f\n",
                stanovnici[i].sifra, stanovnici[i].ime, stanovnici[i].vrsta,
                stanovnici[i].starost, stanovnici[i].datum_rodjenja,
                stanovnici[i].godina_dolaska, stanovnici[i].prebivaliste,
                stanovnici[i].hrana, stanovnici[i].veterinar,
                stanovnici[i].troskovi_odrzavanja);
    }
    fclose(file);
}

int stanovnikPostoji(int sifra) {
    for (int i = 0; i < broj_stanovnika; i++) {
        if (stanovnici[i].sifra == sifra) {
            return 1;
        }
    }
    return 0;
}

void dodajStanovnika() {
    if (broj_stanovnika >= MAX_STANOVNIKA) {
        printf("Nema mesta za nove stanovnike.\n");
        return;
    }
    Stanovnik novi_stanovnik;
    printf("Unesite sifru: ");
    scanf("%d", &novi_stanovnik.sifra);
    if (stanovnikPostoji(novi_stanovnik.sifra)) {
        printf("Stanovnik sa tom sifrom vec postoji.\n");
        return;
    }
    printf("Unesite ime: ");
    scanf("%s", novi_stanovnik.ime);
    printf("Unesite vrstu: ");
    scanf("%s", novi_stanovnik.vrsta);
    printf("Unesite starost: ");
    scanf("%d", &novi_stanovnik.starost);
    printf("Unesite datum rodjenja: ");
    scanf("%s", novi_stanovnik.datum_rodjenja);
    printf("Unesite godinu dolaska: ");
    scanf("%d", &novi_stanovnik.godina_dolaska);
    printf("Unesite prebivaliste: ");
    scanf("%s", novi_stanovnik.prebivaliste);
    printf("Unesite hranu: ");
    scanf("%s", novi_stanovnik.hrana);
    printf("Unesite veterinara: ");
    scanf("%s", novi_stanovnik.veterinar);
    printf("Unesite troskove odrzavanja: ");
    scanf("%f", &novi_stanovnik.troskovi_odrzavanja);
    stanovnici[broj_stanovnika++] = novi_stanovnik;
    sacuvajStanovnike("ZooloskiVrt.txt");
}

void ispisiStanovnikeIzPrebivalista(const char *prebivaliste) {
    Stanovnik sortirani_stanovnici[MAX_STANOVNIKA];
    int broj_sortiranih = 0;

    for (int i = 0; i < broj_stanovnika; i++) {
        if (strcmp(stanovnici[i].prebivaliste, prebivaliste) == 0) {
            sortirani_stanovnici[broj_sortiranih++] = stanovnici[i];
        }
    }

    for (int i = 0; i < broj_sortiranih - 1; i++) {
        for (int j = i + 1; j < broj_sortiranih; j++) {
            if (strcmp(sortirani_stanovnici[i].ime, sortirani_stanovnici[j].ime) > 0 ||
                (strcmp(sortirani_stanovnici[i].ime, sortirani_stanovnici[j].ime) == 0 &&
                 strcmp(sortirani_stanovnici[i].vrsta, sortirani_stanovnici[j].vrsta) > 0)) {
                Stanovnik temp = sortirani_stanovnici[i];
                sortirani_stanovnici[i] = sortirani_stanovnici[j];
                sortirani_stanovnici[j] = temp;
            }
        }
    }

    char ime_izlazne_datoteke[MAX_DUZINA * 3];
    snprintf(ime_izlazne_datoteke, sizeof(ime_izlazne_datoteke), "PREBIVALISTE_%s_STATISTIKA.txt", prebivaliste);

    FILE *file = fopen(ime_izlazne_datoteke, "w");
    if (!file) {
        printf("Greska pri otvaranju datoteke %s\n", ime_izlazne_datoteke);
        return;
    }

    for (int i = 0; i < broj_sortiranih; i++) {
        fprintf(file, "%d %s %s %d %s %d %s %s %s %.2f\n",
                sortirani_stanovnici[i].sifra, sortirani_stanovnici[i].ime,
                sortirani_stanovnici[i].vrsta, sortirani_stanovnici[i].starost,
                sortirani_stanovnici[i].datum_rodjenja, sortirani_stanovnici[i].godina_dolaska,
                sortirani_stanovnici[i].prebivaliste, sortirani_stanovnici[i].hrana,
                sortirani_stanovnici[i].veterinar, sortirani_stanovnici[i].troskovi_odrzavanja);
    }

    fclose(file);
    printf("Podaci su sacuvani u datoteku %s\n", ime_izlazne_datoteke);
}

void ispisiUkupneTroskoveZaHranu(const char *hrana) {
    float ukupni_troskovi = 0;
    for (int i = 0; i < broj_stanovnika; i++) {
        if (strcmp(stanovnici[i].hrana, hrana) == 0) {
            ukupni_troskovi += stanovnici[i].troskovi_odrzavanja;
        }
    }
    printf("Ukupni troskovi odrzavanja za stanovnike koji jedu %s: %.2f\n", hrana, ukupni_troskovi);
}

void obrisiStanovnikePrekoTroskova(float troskovi) {
    int novi_broj_stanovnika = 0;
    for (int i = 0; i < broj_stanovnika; i++) {
        if (stanovnici[i].troskovi_odrzavanja <= troskovi) {
            stanovnici[novi_broj_stanovnika++] = stanovnici[i];
        }
    }
    broj_stanovnika = novi_broj_stanovnika;
    sacuvajStanovnike("ZooloskiVrt.txt");
}

void prikaziMeni() {
    printf("\nMeni:\n");
    printf("1. Dodavanje novog stanovnika\n");
    printf("2. Ispis svih stanovnika na osnovu zadatog prebivalista\n");
    printf("3. Ispis ukupnih troskova odrzavanja za sve stanovnike koji trose zadatu hranu\n");
    printf("4. Brisanje stanovnika na osnovu troskova odrzavanja vecih od unetih troskova\n");
    printf("5. Izlaz\n");
}

int main() {
    ucitajStanovnike("ZooloskiVrt.txt");

    int izbor;
    do {
        prikaziMeni();
        printf("Izaberite opciju: ");
        scanf("%d", &izbor);

        switch (izbor) {
            case 1:
                dodajStanovnika();
                break;
            case 2: {
                char prebivaliste[MAX_DUZINA];
                printf("Unesite prebivaliste: ");
                scanf("%s", prebivaliste);
                ispisiStanovnikeIzPrebivalista(prebivaliste);
                break;
            }
            case 3: {
                char hrana[MAX_DUZINA];
                printf("Unesite hranu: ");
                scanf("%s", hrana);
                ispisiUkupneTroskoveZaHranu(hrana);
                break;
            }
            case 4: {
                float troskovi;
                printf("Unesite maksimalne troskove odrzavanja: ");
                scanf("%f", &troskovi);
                obrisiStanovnikePrekoTroskova(troskovi);
                break;
            }
            case 5:
                printf("Izlaz\n");
                break;
            default:
                printf("Nepostojeca opcija\n");
        }
    } while (izbor != 5);

    return 0;
}


