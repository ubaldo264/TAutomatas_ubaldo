#include <stdio.h>
#include <math.h>
#include <ctype.h>  
#include <stdlib.h> 

#define MAX 10

void mostrarConjunto(char conjunto[], int tam) {
    printf("{ ");
    int i;
    for (i = 0; i < tam; i++) {
        printf("%c ", conjunto[i]);
    }
    printf("}\n");
}

void mostrarConjuntoConcatenado(char conjunto[][2], int tam) {
    printf("{ ");
    int i;
    for (i = 0; i < tam; i++) {
        printf("%c%c ", conjunto[i][0], conjunto[i][1]);
    }
    printf("}\n");
}

int estaEnConjunto(char conjunto[], int tam, char elemento) {
    int i;
    for (i = 0; i < tam; i++) {
        if (conjunto[i] == elemento) {
            return 1;
        }
    }
    return 0;
}

int unionConjuntos(char A[], int tamA, char B[], int tamB, char resultado[]) {
    int tamResultado = tamA;
    int i;
    for (i = 0; i < tamA; i++) {
        resultado[i] = A[i];
    }
    
    for (i = 0; i < tamB; i++) {
        if (!estaEnConjunto(A, tamA, B[i])) {
            resultado[tamResultado++] = B[i];
        }
    }
    return tamResultado;
}

int interseccionConjuntos(char A[], int tamA, char B[], int tamB, char resultado[]) {
    int tamResultado = 0;
    int i;
    for (i = 0; i < tamA; i++) {
        if (estaEnConjunto(B, tamB, A[i])) {
            resultado[tamResultado++] = A[i];
        }
    }
    return tamResultado;
}

int diferenciaConjuntos(char A[], int tamA, char B[], int tamB, char resultado[]) {
    int tamResultado = 0;
    int i;
    for (i = 0; i < tamA; i++) {
        if (!estaEnConjunto(B, tamB, A[i])) {
            resultado[tamResultado++] = A[i];
        }
    }
    return tamResultado;
}

int complementoConjunto(char A[], int tamA, char U[], int tamU, char resultado[]) {
    int tamResultado = 0;
    int i;
    for (i = 0; i < tamU; i++) {
        if (!estaEnConjunto(A, tamA, U[i])) {
            resultado[tamResultado++] = U[i];
        }
    }
    return tamResultado;
}

void potenciaConjunto(char conjunto[], int tam) {
    int totalSubconjuntos = pow(2, tam);
    printf("Potencia del conjunto: { ");
    int i, j;
    for (i = 0; i < totalSubconjuntos; i++) {
        printf("{");
        for (j = 0; j < tam; j++) {
            if (i & (1 << j)) {
                printf("%c ", conjunto[j]);
            }
        }
        printf("} ");
    }
    printf("}\n");
}

int concatenacionConjuntos(char A[], int tamA, char B[], int tamB, char resultado[][2]) {
    int tamResultado = 0;
    int i, j;
    for (i = 0; i < tamA; i++) {
        for (j = 0; j < tamB; j++) {
            resultado[tamResultado][0] = A[i];
            resultado[tamResultado][1] = B[j];
            tamResultado++;
        }
    }
    return tamResultado;
}

void mostrarMenu() {
    printf("\n===== Operaciones de Conjuntos =====\n");
    printf("1. Union\n");
    printf("2. Interseccion\n");
    printf("3. Diferencia (A - B)\n");
    printf("4. Complemento de A en el Conjunto Universal\n");
    printf("5. Concatenacion\n");
    printf("6. Potencia de un Conjunto\n");
    printf("7. Salir\n");
    printf("Seleccione una opcion: ");
}

int main() {
    char U[MAX] = {'1', '2', '3', 'A', 'B', 'C'};  
    int tamU = 6;

    char A[MAX], B[MAX];
    int tamA, tamB;

    printf("Ingrese el tamanio del Conjunto A: ");
    scanf("%d", &tamA);
    printf("Ingrese los elementos de A separados por espacio: ");
    int i;
    for (i = 0; i < tamA; i++) {
        scanf(" %c", &A[i]);
    }

    printf("Ingrese el tamanio del Conjunto B: ");
    scanf("%d", &tamB);
    printf("Ingrese los elementos de B separados por espacio: ");
    for (i = 0; i < tamB; i++) {
        scanf(" %c", &B[i]);
    }

    char resultado[2 * MAX][2];
    int tamResultado;
    int opcion;

    do {
        mostrarMenu();
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                tamResultado = unionConjuntos(A, tamA, B, tamB, (char*)resultado);
                printf("Union: ");
                mostrarConjunto((char*)resultado, tamResultado);
                break;
            case 2:
                tamResultado = interseccionConjuntos(A, tamA, B, tamB, (char*)resultado);
                printf("Interseccion: ");
                mostrarConjunto((char*)resultado, tamResultado);
                break;
            case 3:
                tamResultado = diferenciaConjuntos(A, tamA, B, tamB, (char*)resultado);
                printf("Diferencia A - B: ");
                mostrarConjunto((char*)resultado, tamResultado);
                break;
            case 4:
                tamResultado = complementoConjunto(A, tamA, U, tamU, (char*)resultado);
                printf("Complemento de A en el Conjunto Universal: ");
                mostrarConjunto((char*)resultado, tamResultado);
                break;
            case 5:
                tamResultado = concatenacionConjuntos(A, tamA, B, tamB, resultado);
                printf("Concatenacion: ");
                mostrarConjuntoConcatenado(resultado, tamResultado);
                break;
            case 6:
                printf("Potencia del Conjunto A: ");
                potenciaConjunto(A, tamA);
                break;
            case 7:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida, intente de nuevo.\n");
                break;
        }
    } while (opcion != 7);

    return 0;
}
