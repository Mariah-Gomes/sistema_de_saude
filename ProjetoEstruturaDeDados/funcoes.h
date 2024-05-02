#include "struct.h"

// funções menu:

void menu();

void menu_cadastrar();

void menu_atendimento();

void sobre();


// funções programa:

Lista *inicializa_lista();

int verificar_paciente(Lista *lista, char rg[10]);

void inserir_paciente(Lista *lista, char nome[100], int idade, char rg[10], int dia, int mes, int ano);

void cadastrar_novo_paciente(Lista *lista);

void consultar_paciente_cadastrado(Lista *lista);

void mostrar_lista_completa(Lista *lista);

void atualizar_dados_paciente(Lista *lista);

void remover_paciente(Lista *lista);

void cadastrar(Lista *lista);

void atendimento(Lista *lista);

Fila *criar_fila();

EFila *criar_efila(Registro dados);

void enfileirar(Lista *lista, Fila *f);

void desenfileirar(Fila *f);

void mostrar(Fila *f);

void carregar_arquivo(Lista *lista);

void salvar_arquivo(Lista *lista);

void carregar_salvar(Lista *lista);