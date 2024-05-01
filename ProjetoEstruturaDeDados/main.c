// Nome: Iago Rosa de Oliveira -> RA: 24.123.056-4
// Nome: Mariah Santos Gomes -> RA: 24.222.027-5

#include <stdio.h>
#include "funcoes.h"

int main() {
    Lista *lista = inicializa_lista();

    int opcao;

    while(1){
        menu();
        printf("Selecione uma opcao: ");
        scanf("%d", &opcao);
        printf("\n");
        if(opcao == 1){
            cadastrar(lista);
        }else if(opcao == 2){
            printf("Atendimento...\n");
        }else if(opcao == 3){
            printf("Pesquisa...\n");
        }else if(opcao == 4){
            printf("Carregar/Salvar...\n");
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
