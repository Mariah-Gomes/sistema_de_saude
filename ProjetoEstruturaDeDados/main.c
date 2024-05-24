// Nome: Iago Rosa de Oliveira -> RA: 24.123.056-4
// Nome: Mariah Santos Gomes -> RA: 24.222.027-5

#include <stdio.h>
#include "funcoes.h"

int main() {
    // Inícia a lista
    Lista *lista = inicializa_lista();

    int opcao;

    // Menu principal, onde aparece todas as opções do Menu
    while(1){
        menu();
        printf("Selecione uma opcao: ");
        scanf("%d", &opcao);
        printf("\n");
        if(opcao == 1){
            cadastrar(lista);
        }else if(opcao == 2){
            atendimento(lista);
        }else if(opcao == 3){
            pesquisar(lista);
        }else if(opcao == 4){
            carregar_salvar(lista);
        }else if(opcao == 5){
            sobre();
        }else if(opcao == 6){
            printf("Sair...\n");
            break;
        }else{
            printf("Erro, escolha novamente!\n");
        }
        printf("\n");
    }

    return 0;
}
