#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "paciente.h"

void menu() {
    char choice;
    // Criar a lista duplamente encadeada de pacientes.
    LinkedList *pacientes = criar_ListaPacientes();
    // Carrega as informações presente no arquivo para a lista criada anteriormente.
    carregar_pacientes("bd_paciente.csv", pacientes);

    // Opções para o usuário digitar.
    printf("\nHealthSys\n\n");
    printf("1 - Consultar paciente\n");
    printf("2 - Atualizar paciente\n");
    printf("3 - Remover paciente\n");
    printf("4 - Inserir paciente\n");
    printf("5 - Imprimir lista de pacientes\n");
    printf("Q - Sair\n");
    scanf(" %c", &choice);

    // Loop para continuar enquanto o usuário não digitar Q or q (quit).
    while(choice != 'Q') {

        // Estrutura condicional para verificar a escolha do usuário.
        if(choice == '1') {
            // Chama a função de consultar paciente caso o usuário digite 1.
            consultar_paciente(pacientes);
        } else if (choice == '2') {
            // Chama a função de atualizar paciente caso o usuário digite 2.
            atualizar_paciente(pacientes);
        } else if (choice == '3') {
            // Chama a função de remover paciente caso o usuário digite 3.
            remover_paciente(pacientes);
        } else if(choice == '4') {
            // Chama a função de inserir pacientes caso o usuário digite 4.
            inserir_paciente(pacientes);
        } else if (choice == '5') {
            // Chama a função de imprimir pacientes caso o usuário digite 5.
            imprimir_ListaPacientes(pacientes);
        } else {
            // Mensagem caso o usuário digite algo diferente do previsto.
            printf("\nPlease, select a valid option!!!\n");
        }
        // Loop que se repete enquanto o usuário não der quit.
        printf("\nHealthSys\n\n");
        printf("1 - Consultar paciente\n");
        printf("2 - Atualizar paciente\n");
        printf("3 - Remover paciente\n");
        printf("4 - Inserir paciente\n");
        printf("5 - Imprimir lista de pacientes\n");
        printf("Q - Sair\n");
        scanf(" %c", &choice);
    }
    // Chama a função de salvar informações no arquivo, pois neste ponto o usuário digitou Q para sair.
    salvarInformacoesArquivo(pacientes);

    // Dando free na lista de pacientes após o usuário digitar Q para sair.
    /*ListNode *p = pacientes->first;
    while (p != NULL) {
        ListNode *temp = p;
        p = p->next;
        free(temp);
    }*/
    free(pacientes);
}