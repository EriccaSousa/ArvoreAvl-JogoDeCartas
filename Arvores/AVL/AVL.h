typedef struct node tree;

tree* criar(int raiz);

tree* criarVazia();

tree* sae(tree* t);

tree* sad(tree* t);

tree* pai(tree* t);

int isNULL(tree* t);

tree* minimum(tree* t);

tree* maximum(tree* t);

tree* successor(tree* t);

tree* predecessor(tree* t);

void inserir(tree* t, int valor);

int searchKey(tree* t, int valor);

tree* search(tree* t, int valor);

void freeNode(tree* t);

void itRoot(tree* sup);

void notChildren(tree* sup);

void oneChildren(tree* sup);

void twoChildren(tree* sup);

void Remove(tree* t, int key);

void deleteTree(tree* t);

void emOrdem(tree* t);

void posOrdem(tree* t);

void preOrdem(tree* t);

void printTree(tree* t);

int altura (tree* t);

int fb(tree* t);	//Fator de Balanceamento

tree* RSE(tree* t);

tree* RSD(tree* t);	//Rotação simples a direita

tree* RDE(tree* t);	//Rotação duplamente a esquerda

tree* RDD(tree* t);	//Rotação duplamente a direita

tree* fatorDeRotacao(tree* t);

tree* Insert(tree* t, int key);

tree* AVLRemove(tree* t, int key);
