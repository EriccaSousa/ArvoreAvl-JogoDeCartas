typedef struct lista Lista;

Lista* criarl();

void inserirl(Lista *l, int valor, int pos);

int removerl(Lista *l, int pos);

int vazial(Lista *l);

int cheial(Lista *l);

void imprimirl(Lista *l, int pos);

int qtd_elem(Lista *l);

void liberarl(Lista *l);
