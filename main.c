#include <stdio.h>
#include <stdlib.h>
#include "dict.h"

int main()
{
    dict *dic;
    object key, value;

    dic = dict_new();

    int_to_obj(1, &key);
    str_to_obj("Pepe", &value);
    dict_add(dic, key, value);

    int_to_obj(2, &key);
    str_to_obj("Juan", &value);
    dict_add(dic, key, value);

    char str[50];
    int_to_obj(1, &key);
    dict_search(dic, key, &value);
    obj_to_str(value, str);
    printf("%s %s", str, "\n");


    int i;
    dict_node *node = dict_first(dic); // Obtener el primer nodo
    while (node != NULL)
    {
        dict_key(node, &key);     // Obtener la clave del nodo
        dict_value(node, &value); // Obtener el valor del nodo

        obj_to_int(key, &i);          // Convertir la clave a int
        obj_to_str(value, str);       // Convertir el valor a string
        printf("%d -> %s\n", i, str); // Imprimir clave y valor

        // Acceder al siguiente nodo
        node = dict_next(dic, node);
    }

    dict_destroy(dic);

    return 0;
}
