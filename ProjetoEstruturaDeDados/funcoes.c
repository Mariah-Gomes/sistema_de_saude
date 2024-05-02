#include <stdio.h>
#include "struct.h"
#include <stdlib.h>
#include <string.h>

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
void menu_cadastrar(){
    printf("Operacoes:\n");
    printf("1. Cadastrar novo paciente\n");
    printf("2. Consultar paciente cadastrado\n");
    printf("3. Mostrar lista completa\n");
    printf("4. Atualizar dados de paciente\n");
    printf("5. Remover paciente\n");
    printf("6. Voltar para o menu\n");
}

void menu_atendimento(){
    printf("Operacoes:\n");
    printf("1. Enfileirar paciente\n");
    printf("2. Desenfileirar paciente\n");
    printf("3. Mostrar fila\n");
    printf("4. Voltar para o menu\n");
}

void menu_carregar_salvar(){
    printf("Operacoes:\n");
    printf("1. Carregar arquivo\n");
    printf("2. Salvar arquivo\n");
    printf("3. Voltar para o menu\n");
}

void sobre(){
    printf("Desenvolvedores:\n");
    printf("Nome: Iago Rosa de Oliveira   R.A.: 24.123.056-4\n");
    printf("Nome: Mariah Santos Gomes   R.A.: 24.222.027-5\n");
    printf("\n");
    printf("Ciclo: Quarto Semestre\n");
    printf("Curso: Ciencias da Computacao\n");
    printf("Disciplina: Estrutura de Dados\n");
    printf("Data de entrega: 24/05/2024\n");
    printf("\n");
}


// funções programa:

Lista *inicializa_lista(){
    Lista *lista = malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->qtde = 0;
    return lista;
}

int verificar_paciente(Lista *lista, char rg[10]){
    ELista *atual = lista->inicio;
    while (atual != NULL && strcmp(atual->dados.rg, rg) != 0){
        atual = atual->proximo;
    }
    if(atual == NULL){
        return -1;
    }
    return 1;
}

void inserir_paciente(Lista *lista, char nome[100], int idade, char rg[10], int dia, int mes, int ano){
    if(verificar_paciente(lista, rg) == 1){
        return;
    }
    ELista *novo_paciente = malloc(sizeof(ELista));

    strcpy(novo_paciente->dados.nome, nome);
    novo_paciente->dados.idade = idade;
    strcpy(novo_paciente->dados.rg, rg);
    novo_paciente->dados.entrada.dia = dia;
    novo_paciente->dados.entrada.mes = mes;
    novo_paciente->dados.entrada.ano = ano;

    novo_paciente->proximo = NULL;

    if(lista->inicio != NULL) {
        novo_paciente->proximo = lista->inicio;
    }
    lista->inicio = novo_paciente;
    lista->qtde++;
}

void cadastrar_novo_paciente(Lista *lista){
    char nome[100];
    int idade;
    char rg[10];
    int dia, mes, ano;
    printf("Digite o RG para cadastrar o paciente:\n");
    scanf("%s", rg);
    if(verificar_paciente(lista, rg) == 1){
        printf("\n");
        printf("Paciente ja existente!");
        printf("\n");
        return;
    }
    printf("Digite o nome:\n");
    scanf("%s", nome);
    printf("Digite a idade:\n");
    scanf("%d", &idade);
    printf("Digite o dia:\n");
    scanf("%d", &dia);
    printf("Digite o mes:\n");
    scanf("%d", &mes);
    printf("Digite o ano:\n");
    scanf("%d", &ano);

    inserir_paciente(lista, nome, idade, rg, dia, mes, ano);
}

void consultar_paciente_cadastrado(Lista *lista){
    char rg[10];
    printf("Digite o RG do paciente:\n");
    scanf("%s", rg);
    ELista *atual = lista->inicio;
    while (atual != NULL && strcmp(atual->dados.rg, rg) != 0){
        atual = atual->proximo;
    }
    if(atual == NULL){
        printf("\n");
        printf("Paciente nao existente!");
        printf("\n");
        return;
    }else{
        printf("\n");
        printf("Nome: %s\n", atual->dados.nome);
        printf("Idade: %d\n", atual->dados.idade);
        printf("RG: %s\n", atual->dados.rg);
        printf("Data: %d/%d/%d\n", atual->dados.entrada.dia, atual->dados.entrada.mes, atual->dados.entrada.ano);
        printf("\n");
    }
}

void mostrar_lista_completa(Lista *lista){
    ELista *atual = lista->inicio;
    if(atual == NULL){
        printf("Lista vazia!");
        printf("\n");
        return;
    }
    while (atual != NULL){
        printf("Nome: %s\n", atual->dados.nome);
        printf("Idade: %d\n", atual->dados.idade);
        printf("RG: %s\n", atual->dados.rg);
        printf("Data: %d/%d/%d\n", atual->dados.entrada.dia, atual->dados.entrada.mes, atual->dados.entrada.ano);
        printf("\n");
        atual = atual->proximo;
    }
}

void atualizar_dados_paciente(Lista *lista){
    char rg[10];
    printf("Digite o RG do paciente:\n");
    scanf("%s", rg);
    ELista *atual = lista->inicio;
    while (atual != NULL && strcmp(atual->dados.rg, rg) != 0){
        atual = atual->proximo;
    }
    if(atual == NULL){
        printf("\n");
        printf("Paciente nao existente!");
        printf("\n");
        return;
    }else{
        printf("Digite o nome atualizado:\n");
        scanf("%s", atual->dados.nome);
        printf("Digite a idade atualizada:\n");
        scanf("%d", &atual->dados.idade);
    }
}

void remover_paciente(Lista *lista){
    char rg[10];
    printf("Digite o RG do paciente:\n");
    scanf("%s", rg);
    ELista *atual = lista->inicio;
    ELista  *anterior = NULL;
    while(atual != NULL && strcmp(atual->dados.rg, rg) != 0){
        anterior = atual;
        atual = atual->proximo;
    }
    if(atual == NULL){
        printf("\n");
        printf("Paciente nao existente!");
        printf("\n");
        return;
    }
    if(anterior == NULL){
        lista->inicio = atual->proximo;
    }else{
        anterior->proximo = atual->proximo;
    }
    free(atual);
    lista->qtde--;
    printf("\n");
    printf("Paciente removido!");
    printf("\n");
}

void cadastrar(Lista *lista){
    int opcao;

    menu_cadastrar();

    printf("Selecione uma opcao: ");
    scanf("%d", &opcao);
    printf("\n");

    if(opcao == 1){
        cadastrar_novo_paciente(lista);
    }else if(opcao == 2){
        consultar_paciente_cadastrado(lista);
    }else if(opcao == 3){
        mostrar_lista_completa(lista);
    }else if(opcao == 4){
        atualizar_dados_paciente(lista);
    }else if(opcao == 5){
        remover_paciente(lista);
    }else if(opcao == 6){
        return;
    }else{
        printf("Erro, opcao invalida!\n");
        return;
    }
}

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

void enfileirar(Lista *lista, Fila *f){
    ELista *atual = lista->inicio;
    char rg_desejado[10];
    printf("Digite o numero do RG do paciente: \n");
    scanf("%s", rg_desejado);
    while (atual != NULL && strcmp(atual->dados.rg, rg_desejado) != 0){
        atual = atual->proximo;
    }
    if(atual == NULL){
        printf("\n");
        printf("Paciente nao existente!");
        printf("\n");
        return;
    }
    else{
        EFila *nova = criar_efila(atual->dados);
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
}

int desenfileirar(Fila *f){
    if(f->qtde == 0){
        return -1;
    }
    Registro dados = f->head->dados;
    EFila *endereco = f->head;
    EFila *guardar = f->head;
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
    return guardar;
}

void mostrar(Fila *f){
    EFila *atual = f->head;
    while (atual != NULL){
        printf("Nome: %s\n", atual->dados.nome);
        printf("Idade: %d\n", atual->dados.idade);
        printf("RG: %s\n", atual->dados.rg);
        printf("Data: %d/%d/%d\n", atual->dados.entrada.dia, atual->dados.entrada.mes, atual->dados.entrada.ano);
        printf("\n");
        atual = atual->proximo;
    }
}

void atendimento(Lista *lista){
    Fila *f = criar_fila();
    while(1){
        int opcao_atendimento;
        printf("Atendimento...\n");
        menu_atendimento();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao_atendimento);
        printf("\n");
        if(opcao_atendimento == 1){
            enfileirar(lista, f);
            printf("\n");
        }
        else if(opcao_atendimento == 2){
            desenfileirar(f);
            printf("Paciente saiu da fila\n");
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

void carregar_arquivo(Lista *lista){
    FILE *arquivo;

    arquivo = fopen("pacientes.txt", "r");

    if(arquivo == NULL){
        printf("Erro! arquivo == NULL\n");
        return;
    }

    char nome[100];
    int idade;
    char rg[10];
    int dia, mes, ano;

    while (fscanf(arquivo, "%s %d %s %d %d %d", nome, &idade, rg, &dia, &mes, &ano) != EOF){
        inserir_paciente(lista, nome, idade, rg, dia, mes, ano);
    }

    fclose(arquivo);

    printf("Arquivo carregado!\n");
}

void salvar_arquivo(Lista *lista){
    FILE *arquivo;

    arquivo = fopen("pacientes.txt", "w");

    if(arquivo == NULL){
        printf("Erro! arquivo == NULL\n");
        return;
    }

    ELista *atual = lista->inicio;

    while (atual != NULL){
        fprintf(arquivo, "%s %d %s %d %d %d\n", atual->dados.nome, atual->dados.idade, atual->dados.rg,
                atual->dados.entrada.dia, atual->dados.entrada.mes, atual->dados.entrada.ano);
        atual = atual->proximo;
    }

    fclose(arquivo);

    printf("Arquivo salvo!\n");
}

void carregar_salvar(Lista *lista){
    int opcao;

    menu_carregar_salvar();

    printf("Selecione uma opcao: ");
    scanf("%d", &opcao);
    printf("\n");

    if(opcao == 1){
        carregar_arquivo(lista);
    }else if(opcao == 2){
        salvar_arquivo(lista);
    }else if(opcao == 3){
        return;
    }else{
        printf("Erro, opcao invalida!\n");
        return;
    }
}