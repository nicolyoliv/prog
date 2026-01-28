#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

struct Vector {
    DataType *data;
    int size;
    int capacity;
};

#define INITIAL_CAPACITY 4

Vector *VectorConstruct() {
    Vector *v = malloc(sizeof(Vector));
    if (!v) {
        perror("Erro ao alocar Vector");
        exit(1);
    }

    v->size = 0;
    v->capacity = INITIAL_CAPACITY;
    v->data = malloc(v->capacity * sizeof(DataType));

    if (!v->data) {
        perror("Erro ao alocar dados do Vector");
        exit(1);
    }

    return v;
}

void VectorPushBack(Vector *v, DataType val) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = realloc(v->data, v->capacity * sizeof(DataType));
        if (!v->data) {
            perror("Erro ao realocar Vector");
            exit(1);
        }
    }

    v->data[v->size] = val;
    v->size++;
}

void VectorRemove(Vector *v, int i) {
    if (i < 0 || i >= v->size) return;

    for (int j = i; j < v->size - 1; j++) {
        v->data[j] = v->data[j + 1];
    }

    v->size--;
}

DataType VectorGet(Vector *v, int i) {
    if (i < 0 || i >= v->size) {
        return NULL;
    }

    return v->data[i];
}

int VectorSize(Vector *v) {
    return v->size;
}

void VectorSwap(Vector *v, int i, int j) {
    if (i < 0 || j < 0 || i >= v->size || j >= v->size) return;

    DataType tmp = v->data[i];
    v->data[i] = v->data[j];
    v->data[j] = tmp;
}

void VectorDestroy(Vector *v, void (*destroy)(DataType)) {
    if (!v) return;

    if (destroy) {
        for (int i = 0; i < v->size; i++) {
            destroy(v->data[i]);
        }
    }

    free(v->data);
    free(v);
}
