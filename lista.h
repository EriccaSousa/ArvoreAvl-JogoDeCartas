typedef struct lista Lista;

Lista* criarLista();

void inserirLista(Lista *l, int valor, int pos);

int removerLista(Lista *l, int pos);

int vaziaLista(Lista *l);

int cheiaLista(Lista *l);

void imprimirLista(Lista *l, int pos);

int qtd_elemLista(Lista *l);

void liberarLista(Lista *l);
