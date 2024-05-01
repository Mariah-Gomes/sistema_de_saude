#include "struct.h"

// funções menu:

void menu();

void menu_cadastrar();

void sobre();


// funções programa:

int verificar_paciente(Lista *lista, char rg[10]);

Lista *inicializa_lista();

void cadastrar_novo_paciente(Lista *lista);

void consultar_paciente_cadastrado(Lista *lista);

void mostrar_lista_completa(Lista *lista);

void atualizar_dados_paciente(Lista *lista);

void remover_paciente(Lista *lista);

void cadastrar(Lista *lista);