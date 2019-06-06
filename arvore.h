typedef struct arvore Arvore;

typedef struct no No;

Arvore* criara();

void inserira(Arvore *a, int valor);

int removera(Arvore *a, int valor);

int vaziaa(Arvore *a);

int cheiaa(Arvore *a);

void imprimira(Arvore *a, int ordem);

void liberara(Arvore *a);
