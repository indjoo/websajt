#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TIMOVA 100
#define MAX_DUZINA 30

typedef struct {
    char naziv[MAX_DUZINA];
    char grad[MAX_DUZINA];
    int gol_razlika;
    unsigned int broj_bodova;
    unsigned int broj_pobeda;
    unsigned int broj_neresenih;
    unsigned int broj_poraza;
} Tim;

Tim timovi[MAX_TIMOVA];
int broj_timova = 0;

void ucitajTimove(const char *ime_datoteke) {
    FILE *file = fopen(ime_datoteke, "r");
    if (!file) {
        printf("Greska pri otvaranju datoteke %s\n", ime_datoteke);
        return;
    }
    while (fscanf(file, "%s %s %d %u %u %u %u", timovi[broj_timova].naziv,
                  timovi[broj_timova].grad, &timovi[broj_timova].gol_razlika,
                  &timovi[broj_timova].broj_bodova, &timovi[broj_timova].broj_pobeda,
                  &timovi[broj_timova].broj_neresenih, &timovi[broj_timova].broj_poraza) != EOF) {
        broj_timova++;
    }
    fclose(file);
}

void sacuvajTimove(const char *ime_datoteke) {
    FILE *file = fopen(ime_datoteke, "w");
    if (!file) {
        printf("Greska pri otvaranju datoteke %s\n", ime_datoteke);
        return;
    }
    for (int i = 0; i < broj_timova; i++) {
        fprintf(file, "%s %s %d %u %u %u %u\n", timovi[i].naziv, timovi[i].grad,
                timovi[i].gol_razlika, timovi[i].broj_bodova, timovi[i].broj_pobeda,
                timovi[i].broj_neresenih, timovi[i].broj_poraza);
    }
    fclose(file);
}

int timPostoji(const char *naziv) {
    for (int i = 0; i < broj_timova; i++) {
        if (strcmp(timovi[i].naziv, naziv) == 0) {
            return 1;
        }
    }
    return 0;
}

void dodajTim() {
    if (broj_timova >= MAX_TIMOVA) {
        printf("Nema mesta za nove timove.\n");
        return;
    }
    Tim novi_tim;
    printf("Unesite naziv tima: ");
    scanf("%s", novi_tim.naziv);
    if (timPostoji(novi_tim.naziv)) {
        printf("Tim sa tim nazivom vec postoji.\n");
        return;
    }
    printf("Unesite grad: ");
    scanf("%s", novi_tim.grad);
    printf("Unesite gol razliku: ");
    scanf("%d", &novi_tim.gol_razlika);
    printf("Unesite broj bodova: ");
    scanf("%u", &novi_tim.broj_bodova);
    printf("Unesite broj pobeda: ");
    scanf("%u", &novi_tim.broj_pobeda);
    printf("Unesite broj neresenih utakmica: ");
    scanf("%u", &novi_tim.broj_neresenih);
    printf("Unesite broj poraza: ");
    scanf("%u", &novi_tim.broj_poraza);
    timovi[broj_timova++] = novi_tim;
    sacuvajTimove("Tim.txt");
}

void ispisiTimoveIzGrada(const char *grad) {
    Tim sortirani_timovi[MAX_TIMOVA];
    int broj_sortiranih = 0;

    for (int i = 0; i < broj_timova; i++) {
        if (strcmp(timovi[i].grad, grad) == 0) {
            sortirani_timovi[broj_sortiranih++] = timovi[i];
        }
    }

    for (int i = 0; i < broj_sortiranih - 1; i++) {
        for (int j = i + 1; j < broj_sortiranih; j++) {
            if (sortirani_timovi[i].broj_bodova < sortirani_timovi[j].broj_bodova) {
                Tim temp = sortirani_timovi[i];
                sortirani_timovi[i] = sortirani_timovi[j];
                sortirani_timovi[j] = temp;
            }
        }
    }

    char ime_izlazne_datoteke[MAX_DUZINA * 3];
    snprintf(ime_izlazne_datoteke, sizeof(ime_izlazne_datoteke), "GRAD_%s_STATISTIKA.txt", grad);

    FILE *file = fopen(ime_izlazne_datoteke, "w");
    if (!file) {
        printf("Greska pri otvaranju datoteke %s\n", ime_izlazne_datoteke);
        return;
    }

    for (int i = 0; i < broj_sortiranih; i++) {
        fprintf(file, "%s %s %d %u %u %u %u\n", sortirani_timovi[i].naziv, sortirani_timovi[i].grad,
                sortirani_timovi[i].gol_razlika, sortirani_timovi[i].broj_bodova,
                sortirani_timovi[i].broj_pobeda, sortirani_timovi[i].broj_neresenih,
                sortirani_timovi[i].broj_poraza);
    }

    fclose(file);
    printf("Podaci su sacuvani u datoteku %s\n", ime_izlazne_datoteke);
}

void ispisiTimoveSaVecimBrojemBodova(unsigned int broj_bodova) {
    int brojac = 0;
    for (int i = 0; i < broj_timova; i++) {
        if (timovi[i].broj_bodova > broj_bodova) {
            brojac++;
        }
    }
    printf("Broj timova sa vise od %u bodova: %d\n", broj_bodova, brojac);
}

void promeniBrojPobeda(const char *naziv) {
    for (int i = 0; i < broj_timova; i++) {
        if (strcmp(timovi[i].naziv, naziv) == 0) {
            printf("Unesite novi broj pobeda za tim %s: ", naziv);
            scanf("%u", &timovi[i].broj_pobeda);
            sacuvajTimove("Tim.txt");
            return;
        }
    }
    printf("Tim sa nazivom %s nije pronadjen.\n", naziv);
}

void prikaziMeni() {
    printf("\nMeni:\n");
    printf("1. Dodavanje novog tima\n");
    printf("2. Ispis svih timova na osnovu zadatog grada\n");
    printf("3. Ispisati broj timova koji imaju broj bodova veci od unetog broja\n");
    printf("4. Promena broja pobeda za izabran tim\n");
    printf("5. Izlaz\n");
}

int main() {
    ucitajTimove("Tim.txt");

    int izbor;
    do {
        prikaziMeni();
        printf("Izaberite opciju: ");
        scanf("%d", &izbor);

        switch (izbor) {
            case 1:
                dodajTim();
                break;
            case 2: {
                char grad[MAX_DUZINA];
                printf("Unesite grad: ");
                scanf("%s", grad);
                ispisiTimoveIzGrada(grad);
                break;
            }
            case 3: {
                unsigned int broj_bodova;
                printf("Unesite broj bodova: ");
                scanf("%u", &broj_bodova);
                ispisiTimoveSaVecimBrojemBodova(broj_bodova);
                break;
            }
            case 4: {
                char naziv[MAX_DUZINA];
                printf("Unesite naziv tima: ");
                scanf("%s", naziv);
                promeniBrojPobeda(naziv);
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