#include <stdio.h>

#define MAX_LENGTH 3 // Longitud máxima de las combinaciones

void kleene(int set[], int n, int max_length, int pos, int current[]);
void positivo(int set[], int n, int max_length, int pos, int current[]);

int main() {
    int set[] = {1, 2, 3};
    int n = sizeof(set) / sizeof(set[0]);

    printf("Combinaciones Cerradura de Kleene:\n");
    int currentK[MAX_LENGTH];
    kleene(set, n, MAX_LENGTH, 0, currentK);

    printf("\nCombinaciones Cerradura Positiva:\n");
    int currentP[MAX_LENGTH];
    positivo(set, n, MAX_LENGTH, 0, currentP);

    return 0;
}

// Genera la cerradura de Kleene (incluye la cadena vacía)
void kleene(int set[], int n, int max_length, int pos, int current[]) {
    if (pos > 0) {
        // Imprimir la combinación actual
        
        int i;
        for ( i = 0; i < pos; i++) {
            printf("%d ", current[i]);
        }
        printf("\n");
    }
    if (pos == max_length) return;

    // Genera todas las combinaciones recursivamente
    int i;
    for (i = 0; i < n; i++) {
        current[pos] = set[i];
        kleene(set, n, max_length, pos + 1, current);
    }
}

// Genera la cerradura positiva (excluye la cadena vacía)
void positivo(int set[], int n, int max_length, int pos, int current[]) {
    if (pos > 0) {
        // Imprimir la combinación actual
        int i;
        for (i = 0; i < pos; i++) {
            printf("%d ", current[i]);
        }
        printf("\n");
    }
    if (pos == max_length) return;
int i ;
    // Genera todas las combinaciones recursivamente
    for ( i = 0; i < n; i++) {
        current[pos] = set[i];
        positivo(set, n, max_length, pos + 1, current);
    }
}
