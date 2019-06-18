typedef struct arvore Arvore;

typedef struct no No;

Arvore* criarArvore();

Arvore* inserirA(Arvore *a, int valor);

Arvore* removerA(Arvore *a, int valor);

No* inserirArvore(No *no, int valor);

No* criarNo(int valor);

No* removerArvore(No *no, int valor);

int vaziaArvore(No *no);

int cheiaArvore(No *no);

void imprimirArvore(Arvore *a, int ordem);

void liberarArvore(No *no);

int busca_menor(Arvore *a);

int altura(No *no);

int calcularBalanceamento(No *no);

int maior(int x, int y);

No* rotacaoLL(No *no);

No* rotacaoRR(No *no);

No* rotacaoLR(No *no);

No* rotacaoRL(No *no);


int noRaiz(No *n);
