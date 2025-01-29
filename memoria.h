#ifndef MEMORIA_H
#define MEMORIA_H

#include <stdlib.h>

typedef struct Bloque {
    int id;
    void *direccion;
    size_t tamano;
    struct Bloque *siguiente;
} Bloque;

void asignar_memoria(int id, size_t tamano);
void mostrar_bloques();
void escribir_bloque(int id, void *datos, size_t tamano);
void leer_bloque(int id);
void liberar_memoria(int id);
void liberar_todos_bloques();

#endif //MEMORIA_H