#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APSOLVENATA 50
#define MAX_DUZINA 50

typedef struct {
    int sifra;
    char ime[MAX_DUZINA];
    char prezime[MAX_DUZINA];
    char grad[MAX_DUZINA];
    int broj_ispita_polozenih;
    char smer[MAX_DUZINA];
    int broj_ukupnih_ispita;
    int godina;
    char status[MAX_DUZINA];
} Apsolvent;

Apsolvent apsolventi[MAX_APSOLVENATA];
int broj_apsolvenata = 0;

void ucitajApsolvente(const char *ime_datoteke) {
    FILE *file = fopen(ime_datoteke, "r");
    if (!file) {
        printf("Greska pri otvaranju datoteke %s\n", ime_datoteke);
        return;
    }
    while (fscanf(file, "%d %s %s %s %d %s %d %d %s",
                  &apsolventi[broj_apsolvenata].sifra,
                  apsolventi[broj_apsolvenata].ime,
                  apsolventi[broj_apsolvenata].prezime,
                  apsolventi[broj_apsolvenata].grad,
                  &apsolventi[broj_apsolvenata].broj_ispita_polozenih,
                  apsolventi[broj_apsolvenata].smer,
                  &apsolventi[broj_apsolvenata].broj_ukupnih_ispita,
                  &apsolventi[broj_apsolvenata].godina,
                  apsolventi[broj_apsolvenata].status) != EOF) {
        broj_apsolvenata++;
    }
    fclose(file);
}

void sacuvajApsolvente(const char *ime_datoteke) {
    FILE *file = fopen(ime_datoteke, "w");
    if (!file) {
        printf("Greska pri otvaranju datoteke %s\n", ime_datoteke);
        return;
    }
    for (int i = 0; i < broj_apsolvenata; i++) {
        fprintf(file, "%d %s %s %s %d %s %d %d %s\n",
                apsolventi[i].sifra, apsolventi[i].ime, apsolventi[i].prezime,
                apsolventi[i].grad, apsolventi[i].broj_ispita_polozenih,
                apsolventi[i].smer, apsolventi[i].broj_ukupnih_ispita,
                apsolventi[i].godina, apsolventi[i].status);
    }
    fclose(file);
}

int apsolventPostoji(int sifra) {
    for (int i = 0; i < broj_apsolvenata; i++) {
        if (apsolventi[i].sifra == sifra) {
            return 1;
        }
    }
    return 0;
}

void dodajApsolventa() {
    if (broj_apsolvenata >= MAX_APSOLVENATA) {
        printf("Nema mesta za nove apsolvente.\n");
        return;
    }
    Apsolvent novi_apsolvent;
    printf("Unesite sifru: ");
    scanf("%d", &novi_apsolvent.sifra);
    if (apsolventPostoji(novi_apsolvent.sifra)) {
        printf("Apsolvent sa tom sifrom vec postoji.\n");
        return;
    }
    printf("Unesite ime: ");
    scanf("%s", novi_apsolvent.ime);
    printf("Unesite prezime: ");
    scanf("%s", novi_apsolvent.prezime);
    printf("Unesite grad: ");
    scanf("%s", novi_apsolvent.grad);
    printf("Unesite broj ispita polozenih: ");
    scanf("%d", &novi_apsolvent.broj_ispita_polozenih);
    printf("Unesite smer: ");
    scanf("%s", novi_apsolvent.smer);
    printf("Unesite broj ukupnih ispita: ");
    scanf("%d", &novi_apsolvent.broj_ukupnih_ispita);
    printf("Unesite godinu: ");
    scanf("%d", &novi_apsolvent.godina);
    printf("Unesite status (redovan/vanredan): ");
    scanf("%s", novi_apsolvent.status);
    apsolventi[broj_apsolvenata++] = novi_apsolvent;
    sacuvajApsolvente("Apsolventi.txt");
}

void ispisiApsolventePoStatusu(const char *status) {
    Apsolvent sortirani_apsolventi[MAX_APSOLVENATA];
    int broj_sortiranih = 0;

    for (int i = 0; i < broj_apsolvenata; i++) {
        if (strcmp(apsolventi[i].status, status) == 0) {
            sortirani_apsolventi[broj_sortiranih++] = apsolventi[i];
        }
    }

    for (int i = 0; i < broj_sortiranih - 1; i++) {
        for (int j = i + 1; j < broj_sortiranih; j++) {
            if (sortirani_apsolventi[i].godina < sortirani_apsolventi[j].godina) {
                Apsolvent temp = sortirani_apsolventi[i];
                sortirani_apsolventi[i] = sortirani_apsolventi[j];
                sortirani_apsolventi[j] = temp;
            }
        }
    }

    char ime_izlazne_datoteke[MAX_DUZINA * 3];
    snprintf(ime_izlazne_datoteke, sizeof(ime_izlazne_datoteke), "STATUS_%s_STATISTIKA.txt", status);

    FILE *file = fopen(ime_izlazne_datoteke, "w");
    if (!file) {
        printf("Greska pri otvaranju datoteke %s\n", ime_izlazne_datoteke);
        return;
    }

    for (int i = 0; i < broj_sortiranih; i++) {
        fprintf(file, "%d %s %s %s %d %s %d %d %s\n",
                sortirani_apsolventi[i].sifra, sortirani_apsolventi[i].ime, sortirani_apsolventi[i].prezime,
                sortirani_apsolventi[i].grad, sortirani_apsolventi[i].broj_ispita_polozenih,
                sortirani_apsolventi[i].smer, sortirani_apsolventi[i].broj_ukupnih_ispita,
                sortirani_apsolventi[i].godina, sortirani_apsolventi[i].status);
    }

    fclose(file);
    printf("Podaci su sacuvani u datoteku %s\n", ime_izlazne_datoteke);
}

void ispisiBrojNepolozenihIspita() {
    for (int i = 0; i < broj_apsolvenata; i++) {
        int nepolozeni_ispiti = apsolventi[i].broj_ukupnih_ispita - apsolventi[i].broj_ispita_polozenih;
        printf("Apsolvent %s %s ima %d nepolozenih ispita\n",
               apsolventi[i].ime, apsolventi[i].prezime, nepolozeni_ispiti);
    }
}

void promeniBrojPolozenihIspita(int sifra) {
    for (int i = 0; i < broj_apsolvenata; i++) {
        if (apsolventi[i].sifra == sifra) {
            printf("Unesite novi broj polozenih ispita za %s %s: ", apsolventi[i].ime, apsolventi[i].prezime);
            scanf("%d", &apsolventi[i].broj_ispita_polozenih);
            sacuvajApsolvente("Apsolventi.txt");
            return;
        }
    }
    printf("Apsolvent sa sifrom %d ne postoji.\n", sifra);
}

void prikaziMeni() {
    printf("\nMeni:\n");
    printf("1. Dodavanje novog apsolventa\n");
    printf("2. Ispis svih apsolvenata na osnovu zadatog polja status\n");
    printf("3. Ispisati broj nepolozenih ispita za sve apsolvente\n");
    printf("4. Promena broja polozenih ispita za izabranog apsolventa na osnovu sifre\n");
    printf("5. Izlaz\n");
}

int main() {
    ucitajApsolvente("Apsolventi.txt");

    int izbor;
    do {
        prikaziMeni();
        printf("Izaberite opciju: ");
        scanf("%d", &izbor);

        switch (izbor) {
            case 1:
                dodajApsolventa();
                break;
            case 2: {
                char status[MAX_DUZINA];
                printf("Unesite status (redovan/vanredan): ");
                scanf("%s", status);
                ispisiApsolventePoStatusu(status);
                break;
            }
            case 3:
                ispisiBrojNepolozenihIspita();
                break;
            case 4: {
                int sifra;
                printf("Unesite sifru apsolventa: ");
                scanf("%d", &sifra);
                promeniBrojPolozenihIspita(sifra);
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

