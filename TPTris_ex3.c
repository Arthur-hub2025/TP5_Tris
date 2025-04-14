#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fusionnerTableauxTries(const double T1[], int taille1,
                           const double T2[], int taille2,
                           double T3[]) {
    int i = 0;
    int j = 0; 
    int k = 0; 

    while (i < taille1 && j < taille2) {
        if (T1[i] <= T2[j]) {
            T3[k++] = T1[i++];
        } else {
            T3[k++] = T2[j++];
        }
    }

    while (i < taille1) {
        T3[k++] = T1[i++];
    }

    while (j < taille2) {
        T3[k++] = T2[j++];
    }
}

void afficherTableau(const double tab[], int taille) {
    for (int i = 0; i < taille; i++) {
        printf("%.2f ", tab[i]);
    }
    printf("\n");
}

int main() {
    double T1[] = {1.1, 3.3, 5.5, 7.7};
    double T2[] = {2.2, 4.4, 6.6, 8.8, 10.0};

    int taille1 = sizeof(T1) / sizeof(T1[0]);
    int taille2 = sizeof(T2) / sizeof(T2[0]);
    int taille3 = taille1 + taille2;

    double T3[taille3];

    fusionnerTableauxTries(T1, taille1, T2, taille2, T3);

    printf("Tableau T1 : ");
    afficherTableau(T1, taille1);

    printf("Tableau T2 : ");
    afficherTableau(T2, taille2);

    printf("Tableau fusionne T3 : ");
    afficherTableau(T3, taille3);

    return 0;
}