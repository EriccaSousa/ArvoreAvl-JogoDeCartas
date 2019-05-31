typedef struct arvore Arvore;

typedef struct no No;

Arvore* criar();

void inserir(Arvore *a, int valor);

int remover(Arvore *a, int valor);

int vazia(Arvore *a);

int cheia(Arvore *a);

void imprimir(Arvore *a, int ordem);

void liberar(Arvore *a);
