#define MAX_DATA 50

// Estructura tipo class
typedef struct { int type; char data[MAX_DATA];} object;

// Funciones de conversión
void int_to_obj(int src, object *dst);
void float_to_obj(float src, object *dst);
void str_to_obj(char *src, object *dst);
void obj_to_int(object src, int *dst);
void obj_to_float(object src, float *dst);
void obj_to_str(object src, char *dst);

// Nodo del diccionario
typedef struct st_dict_node {
    object key;
    object value;
    struct st_dict_node *next;
} dict_node;

// Estructura del diccionario
typedef struct {
    dict_node *first;
    int len;
} dict;

// Funciones del diccionario
dict *dict_new();
void dict_destroy(dict *dic);
int dict_add(dict *dic, object key, object value);
int dict_search(dict *dic, object key, object *dst);
int dict_remove(dict *dic, object key);
int dict_len(dict *dic);
dict_node *dict_first(dict *dic);
dict_node *dict_next(dict *dic, dict_node *current);

// Funciones para obtener la clave y el valor de un nodo
void dict_key(dict_node *pair, object *dst);
void dict_value(dict_node *pair, object *dst);

