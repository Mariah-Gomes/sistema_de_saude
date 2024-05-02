// structs para pacientes:

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


// structs para funções:

// Celula...
typedef struct ELista{
    Registro dados;
    struct ELista *proximo;
}ELista;

typedef struct {
    ELista *inicio;
    int qtde;
}Lista;

// STRUCTS PARA A FILA DINÂMICA (ATENDIMENTO)
// Celula...
typedef struct EFila{
    struct EFila *anterior;
    struct EFila *proximo;
    Registro dados;
}EFila;

typedef struct{
    EFila *head;
    EFila *tail;
    int qtde;
}Fila;