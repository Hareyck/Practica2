#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dict.h"

// Funciones de conversión
void int_to_obj(int src, object *dst) {
    dst->type = 0;
    sprintf(dst->data, "%d", src);
}

void float_to_obj(float src, object *dst) {
    dst->type = 1;
    sprintf(dst->data, "%f", src);
}

void str_to_obj(char *src, object *dst) {
    dst->type = 2;
    strcpy(dst->data, src);
}

void obj_to_int(object src, int *dst) {
    if (src.type == 0) *dst = atoi(src.data);
}

void obj_to_float(object src, float *dst) {
    if (src.type == 1) *dst = atof(src.data);
}

void obj_to_str(object src, char *dst) {
    if (src.type == 2) strcpy(dst, src.data);
}


// Crear un nuevo diccionario
dict *dict_new() {
    dict *dic = (dict *)malloc(sizeof(dict));
    dic->first = NULL;
    dic->len = 0;
    return dic;
}

// Destruir el diccionario y liberar memoria
void dict_destroy(dict *dic) {
    dict_node *current = dic->first;
    dict_node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    free(dic);
}

// Añadir un par clave-valor al diccionario
int dict_add(dict *dic, object key, object value) {
    dict_node *new_node = (dict_node *)malloc(sizeof(dict_node));
    if (!new_node) return -1;

    new_node->key = key;
    new_node->value = value;
    new_node->next = dic->first;
    dic->first = new_node;
    dic->len++;

    return 0;
}

// Buscar un valor por su clave
int dict_search(dict *dic, object key, object *dst) {
    dict_node *current = dic->first;

    while (current != NULL) {
        if (strcmp(current->key.data, key.data) == 0) {
            *dst = current->value;
            return 0;
        }
        current = current->next;
    }

    return -1;
}

// Eliminar un par clave-valor
int dict_remove(dict *dic, object key) {
    dict_node *current = dic->first;
    dict_node *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->key.data, key.data) == 0) {
            if (previous == NULL) {
                dic->first = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            dic->len--;
            return 0;
        }
        previous = current;
        current = current->next;
    }

    return -1;
}

// Obtener la longitud del diccionario
int dict_len(dict *dic) {
    return dic->len;
}

// Obtener el primer nodo
dict_node *dict_first(dict *dic) {
    return dic->first;
}

// Obtener el siguiente nodo
dict_node *dict_next(dict *dic, dict_node *current) {
    return current->next;
}

// Extrae la clave de un nodo del diccionario
void dict_key(dict_node *pair, object *dst) {
    *dst = pair->key;  // Copia la clave al objeto dst
}

// Extrae el valor de un nodo del diccionario
void dict_value(dict_node *pair, object *dst) {
    *dst = pair->value;  // Copia el valor al objeto dst
}

