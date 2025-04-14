#include <stdio.h>
#include <string.h>

typedef struct {
    char Nom[50];
    char Prenom[50];
    char Matricule[20];
    float Moyenne;
} Etudiant;

void echanger(Etudiant* a, Etudiant* b) {
    Etudiant temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Etudiant tab[], int bas, int haut) {
    float pivot = tab[haut].Moyenne;
    int i = (bas - 1);

    for (int j = bas; j <= haut - 1; j++) {
        if (tab[j].Moyenne > pivot) { 
            i++;
            echanger(&tab[i], &tab[j]);
        }
    }
    echanger(&tab[i + 1], &tab[haut]);
    return (i + 1);
}

void triQuicksort(Etudiant tab[], int bas, int haut) {
    if (bas < haut) {
        int pi = partition(tab, bas, haut);

        triQuicksort(tab, bas, pi - 1);
        triQuicksort(tab, pi + 1, haut);
    }
}

void trierParMerite(Etudiant etudiants[], int taille) {
    triQuicksort(etudiants, 0, taille - 1);
}

int main() {
    Etudiant etudiants[100];
    int nombreEtudiants = 100;


    trierParMerite(etudiants, nombreEtudiants);

    printf("Liste des etudiants tris par merite:\n");
    for (int i = 0; i < nombreEtudiants; i++) {
        printf("%2d. %s %s - Matricule: %s - Moyenne: %.2f\n",
            i + 1, etudiants[i].Prenom, etudiants[i].Nom,
            etudiants[i].Matricule, etudiants[i].Moyenne);
    }

    return 0;
}