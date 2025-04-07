#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char nom[50];
    char code[50];
    char fabri[50];
    char peremption[11];
    float prix;
    int vente;
    int stock;
} Medicament;

void swap(Medicament* a, Medicament* b) {
    Medicament temp = *a;
    *a = *b;
    *b = temp;
}

int comparer_dates(const char* date1, const char* date2) {
    return strcmp(date1, date2);
}

void tri_bulles(Medicament tab[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (comparer_dates(tab[j].peremption, tab[j + 1].peremption) > 0) {
                swap(&tab[j], &tab[j + 1]);
            }
        }
    }
}

int main() {
    const int N = 2;

    Medicament Tab[N];

    for (int i = 0; i < N; i++) {
        printf("Enregistrement mediament %d:\n", i + 1);
        printf("Nom: ");
        scanf("%49s", Tab[i].nom);
        printf("Code: ");
        scanf("%49s", Tab[i].code);
        printf("Fabriquant: ");
        scanf("%49s", Tab[i].fabri);
        printf("Date de peremption (AAAA-MM-JJ): ");
        scanf("%10s", Tab[i].peremption);
        printf("Prix: ");
        scanf("%f", &Tab[i].prix);
        printf("Vente: ");
        scanf("%d", &Tab[i].vente);
        printf("Stock: ");
        scanf("%d", &Tab[i].stock);
        getchar();
    }

    tri_bulles(Tab, N);

    printf("\nMedicaments tris par date de peremption:\n");
    for (int i = 0; i < N; i++) {
        printf("Nom: %s, Code: %s, Date de peremption: %s\n", Tab[i].nom, Tab[i].code, Tab[i].peremption);
    }

    return 0;
}