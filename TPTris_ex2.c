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

void triInsertionAlphabetique(Etudiant T[], int taille) {
    for (int i = 1; i < taille; i++) {
        Etudiant x = T[i]; 
        int j = i;

        while (j > 0 && strcmp(T[j - 1].Nom, x.Nom) > 0) {
            T[j] = T[j - 1];
            j--;
        }
        T[j] = x;
    }
}

int main() {
    Etudiant etudiants[100] = {
        {"Arthur", "PAILLE", "A123", 15.5},
        {"Matthieu", "PAILLE", "A124", 16.0},
        {"Sabine", "FORD", "M123", 14.0},
        {"Antonin", "DUPONT", "M124", 17.5}
    };
    int nombreEtudiants = 4;

    trierParMerite(etudiants, nombreEtudiants);
    printf("Tri par merite\n");
    for (int i = 0; i < nombreEtudiants; i++) {
        printf("%s %s - Moyenne: %.2f\n", etudiants[i].Nom, etudiants[i].Prenom, etudiants[i].Moyenne);
    }

    triInsertionAlphabetique(etudiants, nombreEtudiants);
    printf("\n Tri alphabetique\n");
    for (int i = 0; i < nombreEtudiants; i++) {
        printf("%s %s\n", etudiants[i].Nom, etudiants[i].Prenom);
    }

    return 0;
}