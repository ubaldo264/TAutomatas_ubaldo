#include <stdio.h>

int main() {
    int opcion;
    int encendido = 0; 

    while (1) {
        printf("\n1. Encender\n");
        printf("2. Apagar\n");
        printf("3. Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                if (!encendido) {
                    encendido = 1;
                    printf("El dispositivo está ENCENDIDO.\n");
                } else {
                    printf("El dispositivo ya está encendido.\n");
                }
                break;

            case 2:
                if (encendido) {
                    encendido = 0;
                    printf("El dispositivo está APAGADO.\n");
                } else {
                    printf("El dispositivo ya está apagado.\n");
                }
                break;

            case 3:
                printf("Saliendo del programa...\n");
                return 0;

            default:
                printf("Opcion no válida.\n");
        }


        if (encendido) {
            printf("Realizando tarea en el ciclo...\n");
        }
    }

    return 0;
}
