#include <stdio.h>
#include <string.h>

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
    const int N = 80;
    Medicament tab[N];

    for (int i = 0; i < N; i++) {
        printf("\n--- Médicament %d ---\n", i + 1);
        printf("Nom : ");
        scanf(" %[^\n]", tab[i].nom);

        printf("Code : ");
        scanf(" %s", tab[i].code);

        printf("Date de fabrication (jj/mm/aaaa) : ");
        scanf(" %s", tab[i].fabri);

        printf("Date de péremption (jj/mm/aaaa) : ");
        scanf(" %s", tab[i].peremption);

        printf("Prix unitaire ($) : ");
        scanf("%f", &tab[i].prix);

        printf("Nombre d'unités vendues : ");
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

    printf("\nMédicaments triés par date de péremption\n");
    for (int i = 0; i < N; i++) {
        printf("Nom : %s | Code : %s | Péremption : %s\n", tab[i].nom, tab[i].code, tab[i].peremption);
    }

    return 0;
}
