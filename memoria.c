#include "memoria.h"
#include <stdio.h>
#include <string.h>

Bloque *inicio = NULL;

void asignar_memoria(int id, size_t tamano) {
    Bloque *nuevo = (Bloque *)malloc(sizeof(Bloque));
    nuevo->id = id;
    nuevo->tamano = tamano;
    nuevo->direccion = malloc(tamano);
    nuevo->siguiente = inicio;
    inicio = nuevo;
    printf("Memoria de %zu bytes asignada al bloque %d.\n", tamano, id);
}

void mostrar_bloques() {
    Bloque *actual = inicio;
    while (actual != NULL) {
        printf("Bloque ID: %d | Tamanio: %zu bytes | Direccion: %p\n",
               actual->id, actual->tamano, actual->direccion);
        actual = actual->siguiente;
    }
}

void escribir_bloque(int id, void *datos, size_t tamano) {
    Bloque *actual = inicio;
    while (actual != NULL) {
        if (actual->id == id) {
            memcpy(actual->direccion, datos, tamano);
            printf("Datos escritos en el bloque %d.\n", id);
            return;
        }
        actual = actual->siguiente;
    }
    printf("Bloque %d no encontrado.\n", id);
}

void leer_bloque(int id) {
    Bloque *actual = inicio;
    while (actual != NULL) {
        if (actual->id == id) {
            printf("Datos en el bloque %d: %s\n", id, (char *)actual->direccion);
            return;
        }
        actual = actual->siguiente;
    }
    printf("Bloque %d no encontrado.\n", id);
}

void liberar_memoria(int id) {
    Bloque **actual = &inicio;
    while (*actual != NULL) {
        if ((*actual)->id == id) {
            Bloque *temp = *actual;
            *actual = (*actual)->siguiente;
            free(temp->direccion);
            free(temp);
            printf("Memoria del bloque %d liberada.\n", id);
            return;
        }
        actual = &(*actual)->siguiente;
    }
    printf("Bloque %d no encontrado.\n", id);
}

void liberar_todos_bloques() {
    while (inicio != NULL) {
        liberar_memoria(inicio->id);
    }
}