#include <stdio.h>
#include <stdlib.h>
#include "memoria.h"

int main() {
    int opcion;
    int id = 0;

    do {
        printf("\n=========================\n");
        printf("  Simulador de Memoria\n");
        printf("=========================\n");
        printf("1. Asignar memoria\n");
        printf("2. Visualizar bloques asignados\n");
        printf("3. Escribir datos en un bloque\n");
        printf("4. Leer datos de un bloque\n");
        printf("5. Liberar memoria\n");
        printf("6. Salir\n");
        printf("=========================\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                size_t tamano;
                printf("Introduce el tamanio del bloque (bytes): ");
                scanf("%zu", &tamano);
                asignar_memoria(++id, tamano);
                break;
            }
            case 2:
                mostrar_bloques();
                break;
            case 3: {
                int bloque_id;
                char datos[100];
                printf("Introduce el ID del bloque: ");
                scanf("%d", &bloque_id);
                printf("Introduce los datos (máx. 100 caracteres): ");
                scanf("%s", datos);
                escribir_bloque(bloque_id, datos, sizeof(datos));
                break;
            }
            case 4: {
                int bloque_id;
                printf("Introduce el ID del bloque: ");
                scanf("%d", &bloque_id);
                leer_bloque(bloque_id);
                break;
            }
            case 5: {
                int bloque_id;
                printf("Introduce el ID del bloque a liberar: ");
                scanf("%d", &bloque_id);
                liberar_memoria(bloque_id);
                break;
            }
            case 6:
                liberar_todos_bloques();
                printf("Memoria liberada. Saliendo del simulador.\n");
                break;
            default:
                printf("Opción invalida. Intenta de nuevo.\n");
        }
    } while (opcion != 6);

    return 0;
}
