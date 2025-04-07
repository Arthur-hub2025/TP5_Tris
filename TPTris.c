#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nom[50];
    char code[20];
    char fabri[11];
    char peremption[11];
    float prix;
    int vente;
    int stock;
} Medicament;

int main() {
    const int N = 3;
    Medicament tab[N];

    for (int i = 0; i < N; i++) {
        printf("\n Medicament %d \n", i + 1);
        printf("Nom : ");
        scanf(" %s", tab[i].nom);

        printf("Code : ");
        scanf(" %s", tab[i].code);

        printf("Date de fabrication (jj/mm/aaaa) : ");
        scanf(" %s", tab[i].fabri);

        printf("Date de peremption (jj/mm/aaaa) : ");
        scanf(" %s", tab[i].peremption);

        printf("Prix unitaire ($) : ");
        scanf("%f", &tab[i].prix);

        printf("Nombre d'unites vendues : ");
        scanf("%d", &tab[i].vente);

        printf("Nombre restant en stock : ");
        scanf("%d", &tab[i].stock);
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (strcmp(tab[j].peremption, tab[j + 1].peremption) > 0) {
                Medicament temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }

    printf("\nMedicaments tries par date de peremption :\n");
    for (int i = 0; i < N; i++) {
        printf("Nom : %s | Code : %s | Peremption : %s\n", tab[i].nom, tab[i].code, tab[i].peremption);
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (strcmp(tab[j].nom, tab[j + 1].nom) > 0) {
                Medicament temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }

    char recherche_nom[] = "paracetamol";
    int debut = 0, fin = N - 1, trouve = 0, mil;

    while (!trouve && debut <= fin) {
        mil = (debut + fin) / 2;
        int cmp = strcmp(tab[mil].nom, recherche_nom);

        if (cmp == 0) {
            trouve = 1;
        }
        else if (cmp < 0) {
            debut = mil + 1;
        }
        else {
            fin = mil - 1;
        }
    }

    if (trouve) {
        printf("\n Medicament 'paracetamol' trouve a l'indice %d :\n", mil);
        printf("Nom : %s | Code : %s | Peremption : %s | Prix : %.2f$\n",
            tab[mil].nom, tab[mil].code, tab[mil].peremption, tab[mil].prix);
    }
    else {
        printf("\n Le medicament 'paracetamol' n'est pas present dans le tableau.\n");
    }

    int indice_max = 0;
    for (int i = 1; i < N; i++) {
        if (tab[i].prix > tab[indice_max].prix) {
            indice_max = i;
        }
    }

    printf("\n Medicament le plus cher :\n");
    printf("Nom : %s | Code : %s | Prix : %.2f$ | Peremption : %s | Stock : %d\n",
        tab[indice_max].nom, tab[indice_max].code, tab[indice_max].prix, tab[indice_max].peremption, tab[indice_max].stock);

    int total_vendus = 0;
    int total_disponibles = 0;

    for (int i = 0; i < N; i++) {
        total_vendus += tab[i].vente;
        total_disponibles += tab[i].vente + tab[i].stock;
    }

    float taux = 0;
    if (total_disponibles > 0) {
        taux = ((float)total_vendus / total_disponibles) * 100;
    }

    printf("\n Taux de medicaments vendus : %.2f %%\n", taux);

    return 0;
}