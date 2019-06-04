#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#define ESQUERDA 1
#define DIREITA 2

struct no{
    int valor;
    No *esq;
    No *dir;
};
