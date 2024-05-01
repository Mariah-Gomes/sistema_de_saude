#include <stdio.h>
#include "struct.h"

// funções menu:

void menu(){
    printf("Menu:\n");
    printf("1. Cadastrar\n");
    printf("2. Atendimento\n");
    printf("3. Pesquisa\n");
    printf("4. Carregar/Salvar\n");
    printf("5. Sobre\n");
    printf("6. Sair\n");
}

// void menu_cadastrar(){
//     //implementar...
// }

void menu_atendimento(){
  printf("1. Enfileirar paciente\n");
  printf("2. Desenfileirar paciente\n");
  printf("3. Mostrar fila\n");
  printf("4. Voltar para o menu\n");
}

void sobre(){
    printf("Desenvolvedores:\n");
    printf("Nome: Iago Rosa de Oliveira   R.A.: 24.123.056-4\n");
    printf("Nome: Mariah Santos Gomes   R.A.: 24.222.027-5\n");
    printf("Ciclo: Quarto Semestre\n");
    printf("Curso: Ciencias da Computacao\n");
    printf("Disciplina: Estrutura de Dados\n");
    printf("Data de entrega: 24/05/2024\n");
    printf("\n");
}

// funções programa:
Fila *criar_fila(){
  Fila *f = malloc(sizeof(Fila));
  f->head = NULL;
  f->tail = NULL;
  f->qtde = 0;
  return f;
}

EFila *criar_efila(Registro dados){
  EFila *ef = malloc(sizeof(EFila));
  ef->anterior = NULL;
  ef->proximo = NULL;
  ef->dados = dados;
  return ef;
}

void enfileirar(Fila *f, Registro dados){
  char rg_desejado[10];
  printf("Digite o numero do RG da pessoa que deseja inserir: \n");
  scanf("%d", rg_desejado);
  //busca_fila();
  EFila *nova = criar_efila(dados);
  //char rg[10] = nova->dados.rg;
  if(f->qtde == 0){
    f->head = nova;
  }
  else{
    f->tail->proximo = nova;
    nova->anterior = f->tail;
  }
  f->tail = nova;
  f->qtde++;
}

int desenfileirar(Fila *f){
  if(f->qtde == 0){
    return -1;
  }
  Registro dados = f->head->dados;
  EFila *endereco = f->head;
  EFila *proximo = endereco->proximo;
  if(f->qtde == 1){
    f->tail = NULL; 
  }
  else{
    proximo->anterior = NULL;
  }
  f->head = proximo;
  f->qtde--;
  free(endereco);
  return dados;
}

void mostrar(Fila *f){
    EFila *atual = f->head;
    while (atual != NULL){
        printf("%d ", atual->dados);
        atual = atual->proximo;
    }
}

void atendimento(){
  Fila *f = criar_fila();
  while(1){
    int opcao_atendimento;
    printf("Atendimento...\n");
    menu_atendimento();
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao_atendimento);
    printf("\n");
    if(opcao_atendimento == 1){
      for (int i = 0; i < 6; i++){
        enfileirar(f, i);
        printf("\n");
      }
    }
    else if(opcao_atendimento == 2){
      printf("Desenfileirar Paciente...\n");
      printf("\n");
    }
    else if(opcao_atendimento == 3){
      mostrar(f);
      printf("\n");
    }
    else if(opcao_atendimento == 4){
      break;
    }
    else{
      printf("Opcao Invalida\n");
      printf("\n");
    }
  }
}

