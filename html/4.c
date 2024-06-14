#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GOSTIJU 500
#define MAX_DUZINA 50

typedef struct {
    int sifra;
    char ime[MAX_DUZINA];
    char prezime[MAX_DUZINA];
    int broj_clanova;
    int obrok;
    int brojSobe;
} Gost;

Gost gosti[MAX_GOSTIJU];
int broj_gostiju = 0;

void ucitajGoste(const char *ime_datoteke) {
    FILE *file = fopen(ime_datoteke, "r");
    if (!file) {
        printf("Greska pri otvaranju datoteke %s\n", ime_datoteke);
        return;
    }
    while (fscanf(file, "%d %s %s %d %d %d",
                  &gosti[broj_gostiju].sifra,
                  gosti[broj_gostiju].ime,
                  gosti[broj_gostiju].prezime,
                  &gosti[broj_gostiju].broj_clanova,
                  &gosti[broj_gostiju].obrok,
                  &gosti[broj_gostiju].brojSobe) != EOF) {
        broj_gostiju++;
    }
    fclose(file);
}

void sacuvajGoste(const char *ime_datoteke) {
    FILE *file = fopen(ime_datoteke, "w");
    if (!file) {
        printf("Greska pri otvaranju datoteke %s\n", ime_datoteke);
        return;
    }
    for (int i = 0; i < broj_gostiju; i++) {
        fprintf(file, "%d %s %s %d %d %d\n",
                gosti[i].sifra, gosti[i].ime, gosti[i].prezime,
                gosti[i].broj_clanova, gosti[i].obrok, gosti[i].brojSobe);
    }
    fclose(file);
}

int gostPostoji(int sifra) {
    for (int i = 0; i < broj_gostiju; i++) {
        if (gosti[i].sifra == sifra) {
            return 1;
        }
    }
    return 0;
}

void dodajGosta() {
    if (broj_gostiju >= MAX_GOSTIJU) {
        printf("Nema mesta za nove goste.\n");
        return;
    }
    Gost novi_gost;
    printf("Unesite sifru: ");
    scanf("%d", &novi_gost.sifra);
    if (gostPostoji(novi_gost.sifra)) {
        printf("Gost sa tom sifrom vec postoji.\n");
        return;
    }
    printf("Unesite ime: ");
    scanf("%s", novi_gost.ime);
    printf("Unesite prezime: ");
    scanf("%s", novi_gost.prezime);
    printf("Unesite broj clanova: ");
    scanf("%d", &novi_gost.broj_clanova);
    printf("Unesite obrok (1, 2, ili 3): ");
    scanf("%d", &novi_gost.obrok);
    printf("Unesite broj sobe: ");
    scanf("%d", &novi_gost.brojSobe);
    gosti[broj_gostiju++] = novi_gost;
    sacuvajGoste("Hotel.txt");
}

void ispisiGostePoObroku(int obrok) {
    Gost sortirani_gosti[MAX_GOSTIJU];
    int broj_sortiranih = 0;

    for (int i = 0; i < broj_gostiju; i++) {
        if (gosti[i].obrok == obrok) {
            sortirani_gosti[broj_sortiranih++] = gosti[i];
        }
    }

    for (int i = 0; i < broj_sortiranih - 1; i++) {
        for (int j = i + 1; j < broj_sortiranih; j++) {
            if (sortirani_gosti[i].broj_clanova < sortirani_gosti[j].broj_clanova) {
                Gost temp = sortirani_gosti[i];
                sortirani_gosti[i] = sortirani_gosti[j];
                sortirani_gosti[j] = temp;
            }
        }
    }

    char ime_izlazne_datoteke[MAX_DUZINA * 3];
    snprintf(ime_izlazne_datoteke, sizeof(ime_izlazne_datoteke), "OBROK_%d_STATISTIKA.txt", obrok);

    FILE *file = fopen(ime_izlazne_datoteke, "w");
    if (!file) {
        printf("Greska pri otvaranju datoteke %s\n", ime_izlazne_datoteke);
        return;
    }

    for (int i = 0; i < broj_sortiranih; i++) {
        fprintf(file, "%d %s %s %d %d %d\n",
                sortirani_gosti[i].sifra, sortirani_gosti[i].ime, sortirani_gosti[i].prezime,
                sortirani_gosti[i].broj_clanova, sortirani_gosti[i].obrok, sortirani_gosti[i].brojSobe);
    }

    fclose(file);
    printf("Podaci su sacuvani u datoteku %s\n", ime_izlazne_datoteke);
}

void ispisiUkupanBrojGostiju() {
    printf("Ukupan broj gostiju je: %d\n", broj_gostiju);
}

void promeniBrojObroka(int sifra) {
    for (int i = 0; i < broj_gostiju; i++) {
        if (gosti[i].sifra == sifra) {
            printf("Unesite novi broj obroka za %s %s: ", gosti[i].ime, gosti[i].prezime);
            scanf("%d", &gosti[i].obrok);
            sacuvajGoste("Hotel.txt");
            return;
        }
    }
    printf("Gost sa sifrom %d ne postoji.\n", sifra);
}

void prikaziMeni() {
    printf("\nMeni:\n");
    printf("1. Dodavanje novog gosta\n");
    printf("2. Ispis svih gostiju na osnovu zadatog broja obroka\n");
    printf("3. Ispisati ukupan broj gostiju\n");
    printf("4. Promena broja obroka za izabranog gosta na osnovu sifre\n");
    printf("5. Izlaz\n");
}

int main() {
    ucitajGoste("Hotel.txt");

    int izbor;
    do {
        prikaziMeni();
        printf("Izaberite opciju: ");
        scanf("%d", &izbor);

        switch (izbor) {
            case 1:
                dodajGosta();
                break;
            case 2: {
                int obrok;
                printf("Unesite broj obroka (1, 2, ili 3): ");
                scanf("%d", &obrok);
                ispisiGostePoObroku(obrok);
                break;
            }
            case 3:
                ispisiUkupanBrojGostiju();
                break;
            case 4: {
                int sifra;
                printf("Unesite sifru gosta: ");
                scanf("%d", &sifra);
                promeniBrojObroka(sifra);
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