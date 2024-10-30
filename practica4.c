#include <stdio.h>

#define MAX 3 

void mostrarConjunto(char conjunto[], int tam) {
    printf("{ ");
    int i;
    for ( i = 0; i < tam; i++) {
        printf("%c ", conjunto[i]);
    }
    printf("}\n");
}


int estaEnConjunto(char conjunto[], int tam, char elemento) {
	int i;
    for ( i = 0; i < tam; i++) {
        if (conjunto[i] == elemento) {
            return 1;
        }
    }
    return 0;
}


int unionConjuntos(char A[], int tamA, char B[], int tamB, char resultado[]) {
    int tamResultado = tamA;
    int i;
    for ( i = 0; i < tamA; i++) {
        resultado[i] = A[i];
    }
    
    for ( i = 0; i < tamB; i++) {
        if (!estaEnConjunto(A, tamA, B[i])) {
            resultado[tamResultado++] = B[i];
        }
    }
    return tamResultado;
}


int interseccionConjuntos(char A[], int tamA, char B[], int tamB, char resultado[]) {
    int tamResultado = 0;
    int i;
    for ( i = 0; i < tamA; i++) {
        if (estaEnConjunto(B, tamB, A[i])) {
            resultado[tamResultado++] = A[i];
        }
    }
    return tamResultado;
}


int diferenciaConjuntos(char A[], int tamA, char B[], int tamB, char resultado[]) {
    int tamResultado = 0;
    int i;
    for ( i = 0; i < tamA; i++) {
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

int main() {
    // Conjunto Universal U1 = {A, B, C}, U2 = {a, b, c}
    char U1[] = {'A', 'B', 'C'};
    char U2[] = {'a', 'b', 'c'};

    // Conjuntos A y B
    char A[] = {'A', 'B', 'a'}; 
    char B[] = {'B', 'C', 'b'}; 

  
    int tamA = 3;
    int tamB = 3;
    int tamU1 = 3;
    int tamU2 = 3;

   
    char resultado[2 * MAX];
    int tamResultado;

    
    tamResultado = unionConjuntos(A, tamA, B, tamB, resultado);
    printf("Union: ");
    mostrarConjunto(resultado, tamResultado);

 
    tamResultado = interseccionConjuntos(A, tamA, B, tamB, resultado);
    printf("Interseccion: ");
    mostrarConjunto(resultado, tamResultado);

    
    tamResultado = diferenciaConjuntos(A, tamA, B, tamB, resultado);
    printf("Diferencia A - B: ");
    mostrarConjunto(resultado, tamResultado);

    
    tamResultado = complementoConjunto(A, tamA, U1, tamU1, resultado);
    printf("Complemento de A en U1: ");
    mostrarConjunto(resultado, tamResultado);

    
    tamResultado = complementoConjunto(A, tamA, U2, tamU2, resultado);
    printf("Complemento de A en U2: ");
    mostrarConjunto(resultado, tamResultado);

    return 0;
}
