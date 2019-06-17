typedef struct arvore Arvore;

typedef struct no No;

Arvore* criarArvore();

void inserirArvore(Arvore *a, int valor);

int removerArvore(Arvore *a, int valor);

int vaziaArvore(Arvore *a);

int cheiaArvore(Arvore *a);

void imprimirArvore(No *no, int ordem);

void liberarArvore(Arvore *a);

int busca_menor(Arvore *a);

int altura(No *no);

int calcularBalanceamento(No *no);

int maior(int x, int y);

No* rotacaoLL(No *no);

No* rotacaoRR(No *no);

No* rotacaoLR(No *no);

No* rotacaoRL(No *no);
No* insereAVL(No *no, int valor);