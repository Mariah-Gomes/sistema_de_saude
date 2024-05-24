#include <stdio.h>
#include "struct.h"
#include <stdlib.h>
#include <string.h>

// FUNÇÕES MENU

// OPÇÕES DO MENU PRINCIPAL
void menu() {
    printf("Menu:\n");
    printf("1. Cadastrar\n");
    printf("2. Atendimento\n");
    printf("3. Pesquisa\n");
    printf("4. Carregar/Salvar\n");
    printf("5. Sobre\n");
    printf("6. Sair\n");
}

// OPÇÕES PARA QUANDO O USUÁRIO ENTRA NA OPÇÃO DO MENU CADASTRAR
void menu_cadastrar() {
    printf("Operacoes:\n");
    printf("1. Cadastrar novo paciente\n");
    printf("2. Consultar paciente cadastrado\n");
    printf("3. Mostrar lista completa\n");
    printf("4. Atualizar dados de paciente\n");
    printf("5. Remover paciente\n");
    printf("6. Voltar para o menu\n");
}

// OPÇÕES PARA QUANDO O USUÁRIO ENTRA NA OPÇÃO DO MENU ATENDIMENTO
void menu_atendimento() {
    printf("Operacoes:\n");
    printf("1. Enfileirar paciente\n");
    printf("2. Desenfileirar paciente\n");
    printf("3. Mostrar fila\n");
    printf("4. Voltar para o menu\n");
}

// OPÇÕES PARA QUANDO O USUÁRIO ENTRA NA OPÇÃO DO MENU PESQUISA
void menu_pesquisar() {
    printf("Operacoes:\n");
    printf("1. Ordenar por ano\n");
    printf("2. Ordenar por mes\n");
    printf("3. Ordenar por dia\n");
    printf("4. Ordenar por idade\n");
    printf("5. Voltar para o menu\n");
}

// OPÇÕES PARA QUANDO O USUÁRIO ENTRA NA OPÇÃO DO MENU CARREGAR/SALVAR
void menu_carregar_salvar() {
    printf("Operacoes:\n");
    printf("1. Carregar arquivo\n");
    printf("2. Salvar arquivo\n");
    printf("3. Voltar para o menu\n");
}

// FUNÇÃO PARA QUANDO O USUÁRIO SELECIONA A OPÇÃO SOBRE
void sobre() {
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

// FUNÇÕES PROGRAMA
// FUNÇÃO PARA CRIAR UMA LISTA
Lista *inicializa_lista() {
    Lista *lista = malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->qtde = 0;
    return lista;
}

// FUNÇÃO PARA VERIFICAR SE O PACIENTE EXISTE
int verificar_paciente(Lista *lista, char rg[10]) {
    ELista *atual = lista->inicio;
    while (atual != NULL && strcmp(atual->dados.rg, rg) != 0) {
        atual = atual->proximo;
    }
    if (atual == NULL) {
        return -1;
    }
    return 1;
}

// FUNÇÃO PARA INSERIR PACIENTES NA LISTA
void inserir_paciente(Lista *lista, char nome[100], int idade, char rg[10], int dia, int mes, int ano) {
    if (verificar_paciente(lista, rg) == 1) {
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

    if (lista->inicio != NULL) {
        novo_paciente->proximo = lista->inicio;
    }
    lista->inicio = novo_paciente;
    lista->qtde++;
}

// FUNÇÃO PARA CADASTRAR UM NOVO PACIENTE
void cadastrar_novo_paciente(Lista *lista) {
    char nome[100];
    int idade;
    char rg[10];
    int dia, mes, ano;
    printf("Digite o RG para cadastrar o paciente:\n");
    scanf("%s", rg);
    if (verificar_paciente(lista, rg) == 1) {
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

// FUNÇÃO PARA CONSULTAR SE TEM UM PACIENTE ESPECIFÍCO
void consultar_paciente_cadastrado(Lista *lista) {
    char rg[10];
    printf("Digite o RG do paciente:\n");
    scanf("%s", rg);
    ELista *atual = lista->inicio;
    while (atual != NULL && strcmp(atual->dados.rg, rg) != 0) {
        atual = atual->proximo;
    }
    if (atual == NULL) {
        printf("\n");
        printf("Paciente nao existente!");
        printf("\n");
        return;
    } else {
        printf("\n");
        printf("Nome: %s\n", atual->dados.nome);
        printf("Idade: %d\n", atual->dados.idade);
        printf("RG: %s\n", atual->dados.rg);
        printf("Data: %d/%d/%d\n", atual->dados.entrada.dia, atual->dados.entrada.mes, atual->dados.entrada.ano);
        printf("\n");
    }
}

// FUNÇÃO PARA MOSTRAR A LISTA COMPLETA DE PACIENTES
void mostrar_lista_completa(Lista *lista) {
    ELista *atual = lista->inicio;
    if (atual == NULL) {
        printf("Lista vazia!");
        printf("\n");
        return;
    }
    while (atual != NULL) {
        printf("Nome: %s\n", atual->dados.nome);
        printf("Idade: %d\n", atual->dados.idade);
        printf("RG: %s\n", atual->dados.rg);
        printf("Data: %d/%d/%d\n", atual->dados.entrada.dia, atual->dados.entrada.mes, atual->dados.entrada.ano);
        printf("\n");
        atual = atual->proximo;
    }
}

// FUNÇÃO PARA ATUALIZAR DADOS DE PACIENTE
void atualizar_dados_paciente(Lista *lista) {
    char rg[10];
    printf("Digite o RG do paciente:\n");
    scanf("%s", rg);
    ELista *atual = lista->inicio;
    while (atual != NULL && strcmp(atual->dados.rg, rg) != 0) {
        atual = atual->proximo;
    }
    if (atual == NULL) {
        printf("\n");
        printf("Paciente nao existente!");
        printf("\n");
        return;
    } else {
        printf("Digite o nome atualizado:\n");
        scanf("%s", atual->dados.nome);
        printf("Digite a idade atualizada:\n");
        scanf("%d", &atual->dados.idade);
    }
}

// FUNÇÃO PARA REMOVER UM PACIENTE
void remover_paciente(Lista *lista) {
    char rg[10];
    printf("Digite o RG do paciente:\n");
    scanf("%s", rg);
    ELista *atual = lista->inicio;
    ELista *anterior = NULL;
    while (atual != NULL && strcmp(atual->dados.rg, rg) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }
    if (atual == NULL) {
        printf("\n");
        printf("Paciente nao existente!");
        printf("\n");
        return;
    }
    if (anterior == NULL) {
        lista->inicio = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }
    free(atual);
    lista->qtde--;
    printf("\n");
    printf("Paciente removido!");
    printf("\n");
}

//FUNÇÃO DE ENTRAR NO MENU DE CADASTRAR 
void cadastrar(Lista *lista) {
    int opcao;

    menu_cadastrar();

    printf("Selecione uma opcao: ");
    scanf("%d", &opcao);
    printf("\n");

    if (opcao == 1) {
        cadastrar_novo_paciente(lista);
    } else if (opcao == 2) {
        consultar_paciente_cadastrado(lista);
    } else if (opcao == 3) {
        mostrar_lista_completa(lista);
    } else if (opcao == 4) {
        atualizar_dados_paciente(lista);
    } else if (opcao == 5) {
        remover_paciente(lista);
    } else if (opcao == 6) {
        return;
    } else {
        printf("Erro, opcao invalida!\n");
        return;
    }
}

// FUNÇÃO DE CRIAR FILA
Fila *criar_fila() {
    Fila *f = malloc(sizeof(Fila));
    f->head = NULL;
    f->tail = NULL;
    f->qtde = 0;
    return f;
}

// FUNÇÃO DE CRIAR CÉLULA DA FILA
EFila *criar_efila(Registro dados) {
    EFila *ef = malloc(sizeof(EFila));
    ef->anterior = NULL;
    ef->proximo = NULL;
    ef->dados = dados;
    return ef;
}

// FUNÇÃO DE ENFILEIRAR OS PACIENTES DA FILA
void enfileirar(Lista *lista, Fila *f) {
    ELista *atual = lista->inicio;
    char rg_desejado[10];
    printf("Digite o numero do RG do paciente: \n");
    scanf("%s", rg_desejado);
    while (atual != NULL && strcmp(atual->dados.rg, rg_desejado) != 0) {
        atual = atual->proximo;
    }
    if (atual == NULL) {
        printf("\n");
        printf("Paciente nao existente!");
        printf("\n");
        return;
    } else {
        EFila *nova = criar_efila(atual->dados);
        if (f->qtde == 0) {
            f->head = nova;
        }
        else {
            f->tail->proximo = nova;
            nova->anterior = f->tail;
        }
        printf("\n");
        printf("Paciente Entrou na Fila");
        printf("\n");
        f->tail = nova;
        f->qtde++;
    }
}

// FUNÇÃO PARA DESENFILEIRAR PACIENTES DA FILA
int desenfileirar(Fila *f) {
    if (f->qtde == 0) {
        return -1;
    }
    Registro dados = f->head->dados;
    EFila *endereco = f->head;
    EFila *guardar = f->head;
    EFila *proximo = endereco->proximo;
    if (f->qtde == 1) {
        f->tail = NULL;
    } else {
        proximo->anterior = NULL;
    }
    f->head = proximo;
    f->qtde--;
    free(endereco);
    printf("\n");
    printf("Paciente Saiu da Fila");
    printf("\n");
    return guardar;
}

// FUNÇÃO PARA MOSTRAR A FILA
void mostrar(Fila *f) {
    EFila *atual = f->head;
    while (atual != NULL) {
        printf("Nome: %s\n", atual->dados.nome);
        printf("Idade: %d\n", atual->dados.idade);
        printf("RG: %s\n", atual->dados.rg);
        printf("Data: %d/%d/%d\n", atual->dados.entrada.dia, atual->dados.entrada.mes, atual->dados.entrada.ano);
        printf("\n");
        atual = atual->proximo;
    }
}

// FUNÇÃO DE ENTRAR NO MENU DE ATENDIMENTO
void atendimento(Lista *lista) {
    Fila *f = criar_fila();
    while (1) {
        int opcao_atendimento;
        printf("Atendimento...\n");
        menu_atendimento();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao_atendimento);
        printf("\n");
        if (opcao_atendimento == 1) {
            enfileirar(lista, f);
            printf("\n");
        } else if (opcao_atendimento == 2) {
            desenfileirar(f);
            printf("\n");
        } else if (opcao_atendimento == 3) {
            mostrar(f);
            printf("\n");
        } else if (opcao_atendimento == 4) {
            break;
        } else {
            printf("Opcao Invalida\n");
            printf("\n");
        }
    }
}

// FUNÇÃO PARA FAZER A ROTAÇÃO PARA A ESQUERDA NO BALANCEAMENTO DA ÁRVORE BINÁRIA
void RotacaoEsquerda(ABB *arvore, EABB *x) {
    EABB *pai = x->pai;
    EABB *y = x->dir;
    EABB *b = y->esq;
    if (pai != NULL) {
        if (pai->esq == x) {
            pai->esq = y;
        } else {
            pai->dir = y;
        }
    } else {
        arvore->raiz = y;
    }
    y->pai = pai;
    x->pai = y;
    y->esq = x;
    x->dir = b;
    if (b != NULL) {
        b->pai = x;
    }
}

// FUNÇÃO PARA FAZER A ROTAÇÃO PARA A DIREITA NO BALANCEAMENTO DA ÁRVORE BINÁRIA
void RotacaoDireita(ABB *arvore, EABB *y) {
    EABB *pai = y->pai;
    EABB *x = y->esq;
    EABB *b = x->dir;
    if (pai != NULL) {
        if (pai->esq == y) {
            pai->esq = x;
        } else {
            pai->dir = x;
        }
    } else {
        arvore->raiz = x;
    }
    x->pai = pai;
    y->pai = x;
    x->dir = y;
    y->esq = b;
    if (b != NULL) {
        b->pai = y;
    }
}

int MAX(int x, int y) {
    if (x >= y)
        return x;
    else
        return y;
}

int altura(EABB *x) {
    if (x == NULL) {
        return -1;
    }
    return MAX(altura(x->esq), altura(x->dir)) + 1;
}

int fatorBalanceamento(EABB *x) { return altura(x->dir) - altura(x->esq); }

// FUNÇÃO QUE REALIZA O BALANCEAMENTO DA ÁRVORE
void balanceie(ABB *arvore, EABB *x) {
    if (fatorBalanceamento(x) >= 2 && fatorBalanceamento(x->dir) >= 0) {
        RotacaoEsquerda(arvore, x);
    } else if (fatorBalanceamento(x) >= 2 && fatorBalanceamento(x->dir) < 0) {
        RotacaoDireita(arvore, x->dir);
        RotacaoEsquerda(arvore, x);
    } else if (fatorBalanceamento(x) <= -2 && fatorBalanceamento(x->esq) <= 0) {
        RotacaoDireita(arvore, x);
    } else if (fatorBalanceamento(x) <= -2 && fatorBalanceamento(x->esq) > 0) {
        RotacaoEsquerda(arvore, x->esq);
        RotacaoDireita(arvore, x);
    }
}

// FUNÇÃO DE INSERIR OS VALORES NA ÁRVORE
int insere(ABB *arvore, Registro dados, int valor) {
    EABB *novo = malloc(sizeof(EABB));
    novo->dados = dados;
    novo->dir = NULL;
    novo->esq = NULL;
    novo->pai = NULL;
    novo->valor = valor;

    EABB *anterior = NULL;
    EABB *atual = arvore->raiz;

    while (atual != NULL) {
        anterior = atual;
        if (valor <= atual->valor) {
            atual = atual->esq;
        } else {
            atual = atual->dir;
        }
    }

    novo->pai = anterior;
    if (anterior != NULL) {
        if (valor <= anterior->valor) {
            anterior->esq = novo;
        } else {
            anterior->dir = novo;
        }
    } else {
        arvore->raiz = novo;
    }
    arvore->qtde++;

    EABB *temp = novo->pai;
    while (temp != NULL) {
        balanceie(arvore, temp);
        temp = temp->pai;
    }
    return 1;
}

// FUNÇÃO PARA IMPRIMIR A ÁRVORE NA ORDEM
void imprimeInOrdem(EABB *raiz) {
    if (raiz != NULL) {
        imprimeInOrdem(raiz->esq);
        printf("Nome: %s\n", raiz->dados.nome);
        printf("Idade: %d\n", raiz->dados.idade);
        printf("RG: %s\n", raiz->dados.rg);
        printf("Data: %d/%d/%d\n", raiz->dados.entrada.dia, raiz->dados.entrada.mes, raiz->dados.entrada.ano);
        printf("\n");
        imprimeInOrdem(raiz->dir);
    }
}

// FUNÇÃO PARA ORDERNAR A ÁRVORE POR ANO
void ordenar_por_ano(Lista *lista, ABB *arvore) {
    ELista *atual = lista->inicio;
    while (atual != NULL) {
        insere(arvore, atual->dados, atual->dados.entrada.ano);
        atual = atual->proximo;
    }
    imprimeInOrdem(arvore->raiz);
}

// FUNÇÃO PARA ORDERNAR A ÁRVORE POR MÊS
void ordenar_por_mes(Lista *lista, ABB *arvore) {
    ELista *atual = lista->inicio;
    while (atual != NULL) {
        insere(arvore, atual->dados, atual->dados.entrada.mes);
        atual = atual->proximo;
    }
    imprimeInOrdem(arvore->raiz);
}

// FUNÇÃO PARA ORDERNAR A ÁRVORE POR DIA
void ordenar_por_dia(Lista *lista, ABB *arvore) {
    ELista *atual = lista->inicio;
    while (atual != NULL) {
        insere(arvore, atual->dados, atual->dados.entrada.dia);
        atual = atual->proximo;
    }
    imprimeInOrdem(arvore->raiz);
}

// FUNÇÃO PARA ORDERNAR A ÁRVORE POR IDADE
void ordenar_por_idade(Lista *lista, ABB *arvore) {
    ELista *atual = lista->inicio;
    while (atual != NULL) {
        insere(arvore, atual->dados, atual->dados.idade);
        atual = atual->proximo;
    }
    imprimeInOrdem(arvore->raiz);
}

// FUNÇÃO DE ENTRAR NO MENU DE PESQUISA
void pesquisar(Lista *lista) {
    ABB *arvore = malloc(sizeof(ABB));
    arvore->raiz = NULL;
    arvore->qtde = 0;

    int opcao;

    menu_pesquisar();

    printf("Selecione uma opcao: ");
    scanf("%d", &opcao);
    printf("\n");

    if (opcao == 1) {
        ordenar_por_ano(lista, arvore);
    } else if (opcao == 2) {
        ordenar_por_mes(lista, arvore);
    } else if (opcao == 3) {
        ordenar_por_dia(lista, arvore);
    } else if (opcao == 4) {
        ordenar_por_idade(lista, arvore);
    } else if (opcao == 5) {
        return;
    } else {
        printf("Erro, opcao invalida!\n");
        return;
    }
}

// FUNÇÃO PARA CARREGAR UM ARQUIVO
void carregar_arquivo(Lista *lista) {
    FILE *arquivo;

    arquivo = fopen("pacientes.txt", "r");

    if (arquivo == NULL) {
        printf("Erro! arquivo == NULL\n");
        return;
    }

    char nome[100];
    int idade;
    char rg[10];
    int dia, mes, ano;

    while (fscanf(arquivo, "%s %d %s %d %d %d", nome, &idade, rg, &dia, &mes, &ano) != EOF) {
        inserir_paciente(lista, nome, idade, rg, dia, mes, ano);
    }

    fclose(arquivo);

    printf("Arquivo carregado!\n");
}

// FUNÇÃO PARA SALVAR UM ARQUIVO
void salvar_arquivo(Lista *lista) {
    FILE *arquivo;

    arquivo = fopen("pacientes.txt", "w");

    if (arquivo == NULL) {
        printf("Erro! arquivo == NULL\n");
        return;
    }

    ELista *atual = lista->inicio;
    Lista *lista_provisoria = inicializa_lista();

    while (atual != NULL) {
        inserir_paciente(lista_provisoria, atual->dados.nome, atual->dados.idade, atual->dados.rg,
                         atual->dados.entrada.dia, atual->dados.entrada.mes, atual->dados.entrada.ano);
        atual = atual->proximo;
    }

    ELista *atual_provisorio = lista_provisoria->inicio;

    while (atual_provisorio != NULL) {
        fprintf(arquivo, "%s %d %s %d %d %d\n", atual_provisorio->dados.nome,
                atual_provisorio->dados.idade, atual_provisorio->dados.rg, atual_provisorio->dados.entrada.dia,
                atual_provisorio->dados.entrada.mes, atual_provisorio->dados.entrada.ano);
        atual_provisorio = atual_provisorio->proximo;
    }

    fclose(arquivo);

    printf("Arquivo salvo!\n");
}

// FUNÇÃO DE ENTRAR NO MENU DE CARREGAR OU SALVAR
void carregar_salvar(Lista *lista) {
    int opcao;

    menu_carregar_salvar();

    printf("Selecione uma opcao: ");
    scanf("%d", &opcao);
    printf("\n");

    if (opcao == 1) {
        carregar_arquivo(lista);
    } else if (opcao == 2) {
        salvar_arquivo(lista);
    } else if (opcao == 3) {
        return;
    } else {
        printf("Erro, opcao invalida!\n");
        return;
    }
}
