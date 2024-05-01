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