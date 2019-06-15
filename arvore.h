typedef struct arvore Arvore;

typedef struct no No;

Arvore* criarArvore();

void inserirArvore(Arvore *a, int valor);

int removerArvore(Arvore *a, int valor);

int vaziaArvore(Arvore *a);

int cheiaArvore(Arvore *a);

void imprimirArvore(Arvore *a, int ordem);

void liberarArvore(Arvore *a);

int busca_menor(Arvore *a);

int calcularAltura(No *no, Arvore *a);

int calcularBalanceamento(Arvore *a);

int maior(int x, int y);