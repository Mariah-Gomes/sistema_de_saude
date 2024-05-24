// STRUCTS PARA PACIENTES

typedef struct {
    int dia;
    int mes;
    int ano;
}Data;

typedef struct {
    char nome[100];
    int idade;
    char rg[10];
    Data entrada;
}Registro;


// STRUCTS PARA AS FUNÇÕES

// STRUCTS PARA A LISTA DINÂMICA (CADASTRO) 
// CÉLULA
typedef struct ELista{
    Registro dados;
    struct ELista *proximo;
}ELista;

// ESTRUTURA
typedef struct {
    ELista *inicio;
    int qtde;
}Lista;

// STRUCTS PARA A FILA DINÂMICA (ATENDIMENTO)
// CÉLULA
typedef struct EFila{
    struct EFila *anterior;
    struct EFila *proximo;
    Registro dados;
}EFila;

// ESTRUTURA
typedef struct{
    EFila *head;
    EFila *tail;
    int qtde;
}Fila;

// STRUCTS PARA A ÁRVORE BINÁRIA (PESQUISA)
// CÉLULA
typedef struct EABB{
    Registro dados;
    struct EABB *esq;
    struct EABB *dir;
    struct EABB *pai;
    int valor;
}EABB;

// ESTRUTURA
typedef struct {
    EABB *raiz;
    int qtde;
}ABB;
