#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IME 25
#define DIM 2000
#define DAT 30
#define BROJ 1

typedef struct
{
    int sifra;
    char ime[IME];
    char prezime[IME];
    char grad[IME];
    int starost;
    char lekar[IME];
    char dijagnoza[DAT];
} Pacijent;

void Meni()
{
    printf("\n1 - Dodavanje novog pacijenta\n");
    printf("2 - Ispis svih pacijenata na osnovu lekara\n");
    printf("3 - Ispis broja pacijenata sa zadatom dijagnozom\n");
    printf("4 - Promena lekara za izabranog pacijenta\n");
    printf("0 - Izlaz iz programa\n\n");
}


void DodajPacijenta(Pacijent *pacijenti, int *brojPacijenata)
{
    FILE *ulaz=fopen("Pacijenti.txt", "a");
    if (ulaz==NULL)
    {
        printf("Greska pri otvaranju datoteke!\n");
        return;
    }

    Pacijent noviPacijent;

    printf("Unesite sifru pacijenta: ");
    scanf("%d", &noviPacijent.sifra);

    for (int i=0; i<*brojPacijenata; i++)
    {
        if (pacijenti[i].sifra == noviPacijent.sifra)
        {
            printf("Pacijent sa tom sifrom vec postoji!\n");
            fclose(ulaz);
            return;
        }
    }

    printf("Unesite ime: ");
    scanf("%s", noviPacijent.ime);
    printf("Unesite prezime: ");
    scanf("%s", noviPacijent.prezime);
    printf("Unesite grad: ");
    scanf("%s", noviPacijent.grad);
    printf("Unesite starost: ");
    scanf("%d", &noviPacijent.starost);
    printf("Unesite ime lekara: ");
    scanf("%s", noviPacijent.lekar);
    printf("Unesite dijagnozu: ");
    scanf("%s", noviPacijent.dijagnoza);

    fprintf(ulaz, "%d %s %s %s %d %s %s\n", noviPacijent.sifra, noviPacijent.ime, noviPacijent.prezime, noviPacijent.grad, noviPacijent.starost, noviPacijent.lekar, noviPacijent.dijagnoza);
    fclose(ulaz);

    pacijenti[*brojPacijenata] = noviPacijent;
    (*brojPacijenata)++;
}


void IspisPacijenataPoLekaru(Pacijent *pacijenti, int brojPacijenata)
{
    char lekar[IME];
    printf("Unesite ime lekara: ");
    scanf("%s", lekar);

    char nazivDatoteke[DAT];
    sprintf(nazivDatoteke, "LEKAR_%s_STATISTIKA.txt", lekar);
    printf("Podaci uspesno upisani.\n");

    FILE *izlaz = fopen(nazivDatoteke, "w");
    if (izlaz == NULL)
    {
        printf("Greska pri otvaranju izlazne datoteke!\n");
        return;
    }


    for (int i=0; i<brojPacijenata-1; i++)
    {
        for (int j=0; j<brojPacijenata-i-1; j++)
        {
            if (strcmp(pacijenti[j].lekar, lekar)==0 && strcmp(pacijenti[j+1].lekar, lekar)==0 && pacijenti[j].starost < pacijenti[j + 1].starost)
            {
                Pacijent temp = pacijenti[j];
                pacijenti[j] = pacijenti[j+1];
                pacijenti[j+1]=temp;
            }
        }
    }

    for (int i=0; i<brojPacijenata; i++)
    {
        if (strcmp(pacijenti[i].lekar, lekar)==0)
        {
            fprintf(izlaz, "Sifra: %d, Ime: %s, Prezime: %s, Grad: %s, Starost: %d, Lekar: %s, Dijagnoza: %s\n", pacijenti[i].sifra, pacijenti[i].ime, pacijenti[i].prezime, pacijenti[i].grad, pacijenti[i].starost, pacijenti[i].lekar, pacijenti[i].dijagnoza);
        }
    }

    fclose(izlaz);
}


void BrojPacijenataSaDijagnozom(Pacijent *pacijenti, int brojPacijenata)
{
    char dijagnoza[DAT];
    printf("Unesite dijagnozu: ");
    scanf("%s", dijagnoza);

    int broj=0;
    for (int i=0; i<brojPacijenata; i++)
    {
        if (strcmp(pacijenti[i].dijagnoza, dijagnoza)==0)
        {
            broj++;
        }
    }

    printf("Broj pacijenata sa dijagnozom '%s' je %d\n", dijagnoza, broj);
}

void PromenaLekara(Pacijent *pacijenti, int brojPacijenata)
{
    int sifra;
    printf("Unesite sifru pacijenta: ");
    scanf("%d", &sifra);

    for (int i=0; i<brojPacijenata; i++)
    {
        if (pacijenti[i].sifra==sifra)
        {
            printf("Unesite novo ime lekara: ");
            scanf("%s", pacijenti[i].lekar);
            break;
        }
    }

    FILE *izlaz = fopen("Pacijenti.txt", "r");
    if (izlaz == NULL)
    {
        printf("Greska pri otvaranju izvorne datoteke!\n");
        return;
    }

    for (int i=0; i<brojPacijenata; i++)
    {
        fprintf(izlaz, "%d %s %s %s %d %s %s\n", pacijenti[i].sifra, pacijenti[i].ime, pacijenti[i].prezime, pacijenti[i].grad, pacijenti[i].starost, pacijenti[i].lekar, pacijenti[i].dijagnoza);
    }

    fclose(izlaz);

    printf("Promena lekara je uspesno sacuvana.\n");
}


int main() {
    Pacijent pacijenti[DIM];
    int brojPacijenata=0;
    int opcija;

    do {
        Meni();
        printf("Izaberite opciju: ");
        scanf("%d", &opcija);

        switch (opcija) {
            case 1:
                DodajPacijenta(pacijenti, &brojPacijenata);
                break;
            case 2:
                IspisPacijenataPoLekaru(pacijenti, brojPacijenata);
                break;
            case 3:
                BrojPacijenataSaDijagnozom(pacijenti, brojPacijenata);
                break;
            case 4:
                PromenaLekara(pacijenti, brojPacijenata);
                break;
            case 0:
                printf("Izlaz iz programa.\n");
                break;
            default:
                printf("Nepostojeca opcija. Molimo unesite ponovo.\n");
        }
    } while (opcija!=0);

    return 0;
}

