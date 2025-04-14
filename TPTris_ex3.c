
 #include <stdio.h>
 #include <stdlib.h>
 
 void fusionnerTableauxTries(const double T1[], int taille1, 
                            const double T2[], int taille2, 
                            double T3[]);
 
 void afficherTableau(const double tab[], int taille);
 
 int main() {
     double T1[] = {1.2, 3.4, 5.6, 7.8};  
     double T2[] = {2.3, 4.5, 6.7};      
     
     const int taille1 = sizeof(T1) / sizeof(T1[0]);
     const int taille2 = sizeof(T2) / sizeof(T2[0]);
     const int taille3 = taille1 + taille2;
     
     double T3[taille3];
 
     fusionnerTableauxTries(T1, taille1, T2, taille2, T3);
 
$     printf("\nRESULTATS DE LA FUSION\n");
     printf("Tableau 1 : ");
     afficherTableau(T1, taille1);
     
     printf("Tableau 2 : ");
     afficherTableau(T2, taille2);
     
     printf("Tableau fusionne : ");
     afficherTableau(T3, taille3);
 
     return 0;
 }
 
$ void fusionnerTableauxTries(const double T1[], int taille1, 
                            const double T2[], int taille2, 
                            double T3[]) {
     int i = 0; 
     int j = 0; 
     int k = 0; 
     while (i < taille1 && j < taille2) {
         if (T1[i] <= T2[j]) {
             T3[k] = T1[i];
             i++;
         } else {
             T3[k] = T2[j];
             j++;
         }
         k++;
     }
 
=     while (i < taille1) {
         T3[k] = T1[i];
         i++;
         k++;
     }
 
     while (j < taille2) {
         T3[k] = T2[j];
         j++;
         k++;
     }
 }
 
 void afficherTableau(const double tab[], int taille) {
     printf("[");
     for (int i = 0; i < taille; i++) {
         printf("%.2f", tab[i]);
         if (i < taille - 1) printf(", ");
     }
     printf("]\n");
 }
 
