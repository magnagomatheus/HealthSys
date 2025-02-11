#include <stdio.h>
#include <stdlib.h>
//#define _GNU_SOURCE
#include <string.h>
#include "paciente.h"

// Define a estrutura para a lista duplamente encadeada de pacientes.
struct pacientes {
    ListNode* first; // Ponteiro para o primeiro paciente da lista.
    ListNode* last; // Ponteiro para o ultimo elemento da lista.
};

// Define a estrutura do nó (paciente) da lista duplamente encadeada chamada pacientes.

struct paciente {
    int id; // ID do paciente
    char cpf[15]; // CPF do paciente
    char nome[50]; // NOME do paciente
    int idade; // IDADE do paciente
    char data_cadastro[11]; // Data Cadastro do pacientes
    ListNode* next; // Nó que aponta para o próximo paciente em relação a um determinado paciente da lista.
    ListNode* prev; // Nó que aponta para o paciente anterior em relação um determinado paciente da lista. 
};



// Construcao da funcao que cria uma lista duplamente encadeada vazia dos pacientes.
LinkedList *criar_ListaPacientes() {
    // Aloca memoria dinamicamente para a lista duplamente encadeada pacientes
    LinkedList *pacientes = (LinkedList *)malloc(sizeof(LinkedList));
    // Verifica se ocorreu tudo bem.
    if (pacientes == NULL) {
        printf("Falha ao alocar memoria para a lista encadeada!\n");
        return NULL;
    }
    
    // Como a lista está vazia, o nó que aponta para o primeiro e último paciente serão setados nulos.
    pacientes->first = NULL;
    pacientes->last = NULL;

    // Retorna a lista duplamente encadeada de pacientes vazia.
    return pacientes;

}


// Funcao que cria o no (paciente) para a lista duplamente encadeada de pacientes.
// Recebe como parâmetro as informações ou dados do paciente (nó).
ListNode *criar_node(int idr, char* cpfr, char* nomer, int idader, char* dc) {
    // Aloca dinâmicamente um nó (paciente) na memória.
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    // Verifica se ocorreu tudo bem.
    if (node == NULL) {
        printf("Falha ao alocar memoria para um paciente na lista!");
        return NULL;
    }
    
    // Atribuição aos dados recebidos por meio do parâmetro para os respectivos campos presentes em cada nó da estrutura.
    node->id = idr; // ID do nó recebe ID passado como parâmetro (valor externo).
    strcpy(node->cpf, cpfr); // CPF do nó recebe novo valor recebido pelo parâmetro cpfr.
    strcpy(node->nome, nomer); // NOME do nó (paciente) recebe valor (nome) recebido por meio do parâmetro.
    node->idade = idader; // Idade do paciente (nó) recebe valor (idade) recebido no parâmetro.
    strcpy(node->data_cadastro, dc); // Data Cadastro do nó recebe valor recebido por meio do parâmetro.
    node->next = NULL; // Como o nó (paciente) apenas foi criado, o ponteiro next recebe NULO, pois ainda não se sabe qual local (posição) este nó (paciente) será inserido na lista de pacientes.
    node->prev = NULL; // Como o nó (paciente) apenas foi criado, o ponteiro prev recebe NULO, pois ainda não se sabe qual local (posição) este nó (paciente) será inserido na lista de pacientes.

    // Retorna o ponteiro para o nó (paciente).
    return node;

}

// Construcao da função que carrega os pacientes de um arquivo externo e adiciona para a lista encadeada de pacientes.
void carregar_pacientes(const char* nomeArquivo, LinkedList *pacientes) {
    // Abertura do arquivo em modo de leitura.
    FILE *f = fopen(nomeArquivo, "r");
    // Verifica se ocorreu tudo bem.
    if (f == NULL) {
        printf("Erro ao abrir o arquivo!");
    }

    // Variáveis temporárias.
    char l[150];
    int id, idade;
    char nome[50], cpf[15], dc[11];

    // Loop enquanto fgets retornar o buffer (conteudo da linha do arquivo) irá continuar.
    while (fgets(l, sizeof(l), f)) {
        // sscanf recebe o buffer (linha), faz a separacao dos dados pelas virgulas e os atribui nas suas respectivas variaveis. Ainda confere se foi 'capturado' a quantidade certa de variaveis.
        if (sscanf(l, "%d,%15[^,],%49[^,],%d,%10s", &id, cpf, nome, &idade, dc) == 5) {
            // Chama a função cria nó da lista para criar o nó paciente e adicioná-lo na lista de pacientes.
            ListNode *paciente = criar_node(id, cpf, nome, idade, dc);
            // Verifica se a lista está vazia.
            if (pacientes->first == NULL) {
                // Se estiver vazia, o nó paciente que foi criado recentemente é referenciado como o primeiro e último elemento da lista e seus nós que apontam para o next e prev continuam NULOS.
                pacientes->first = paciente;
                pacientes->last = paciente;
            } else {
                // Caso a lista não esteja vazia...
                pacientes->last->next = paciente; // O último elemento da lista aponta para o novo nó paciente.
                paciente->prev = pacientes->last; // O nó do novo nó (paciente) que aponta para o elemento anterior do mesmo, agora aponta para o último paciente da lista.
                pacientes->last = paciente; // O último paciente da lista agora é o novo paciente (nó) que acabou de ser criado.
                // Com isso, o novo paciente é adicionado sempre na última posição da lista.
            }
        } else {
            printf("ERROR!!!!");
        }
    }
    // Fechamento do arquivo
    fclose(f);
}

// Função de escolha do modo da consulta.
int escolha_consulta() {
    int choice = 0;
    printf("Escolha o modo de consulta: \n");
    printf("1 - Por Nome\n");
    printf("2 - Por CPF\n");
    printf("3 - Retornar ao menu principal\n");
    scanf("%d", &choice);
    getchar(); // Limpar o buffer
    return choice;
}

// Função que faz a consulta do paciente, ou seja, percorre a lista, compara o valor de entrada de acordo com o modo desejado e retorna os respectivos pacientes da busca.
int consultar_paciente(LinkedList *pacientes) {
    // variável que armazena a escolha do usuário sobre o modo da consulta de paciente.
    int choice = escolha_consulta();
    // Condicional sobre o modo de consulta.
    if (choice == 1) {
        printf("Digite o nome do paciente: \n");
    } else if (choice == 2) {
        printf("Digite o CPF (XXX.XXX.XXX-XX) do paciente: \n");
    } else {
        printf("Retornando para o menu principal!!!\n");
        return 1;
    }
    // Variável que irá armazenar o que o usuário digitou, podendo ser nome ou cpf.
    char input[50];
    // scanf para atribuir o que o usuário digitou a variável input.
    scanf(" %49[^\n]", input);
    // Chama a função de encontrar o paciente, passando o modo de consulta que o usuário escolheu e o seu input.
    encontraPaciente(pacientes, choice, input);

    // Retorna zero se deu tudo certo.
    return 0;

}

// Função que percorre a lista de pacientes a procura de um paciente pelo nome ou cpf, imprimindo todas as informações do paciente caso o encontre;
void encontraPaciente(LinkedList *pacientes, int choice, char *input) {
    // Nó temporário auxiliar recebe o primeiro paciente da lista
    ListNode *p = pacientes->first;

    // Loop enquanto o p não for nulo (fim da lista)
    while (p != NULL) {
        // Verificação sobre a escolha, para chamar a função de buscar pelo modo da escolha.
        if (choice == 1) {
            // Chama a função de buscar nome na lista e verifica se retornou 0 (sucesso)
            if (busca_nome(input, p->nome) == 0) {
                // Caso o nome do input e do paciente presente na lista forem iguais, imprime todas as informações do paciente. 
                imprimir_paciente(p);
            }
        } else {
            // Chama a função de buscar cpf na lista que compara o cpf do input com o de cada paciente presenta na lista.
            if (busca_cpf(input, p->cpf) == 0) {
                // Caso os cpf sajm iguais, imprime todos os dados do paciente.
                imprimir_paciente(p);
            }
        }
        // Passa para o próximo paciente (nó).
        p = p->next;
    }

}


// Funcao que verifica se o nome do paciente digitou esta na lista.
int busca_nome(char *input, char nc[]) {
     
    // n1 e n2 --> Nome e Sobrenome dos pacientes que estao na lista encadeada de pacientes
    char n1[25];
    char n2[25];
    // inputN1 e inputN2 --> Nome e Sobrenome DO INPUT (O QUE O USUARIO DIGITOU)
    char inputN1[25] = "";
    char inputN2[25] = "";
    // Separa o nome do paciente presente na lista de pacientes em duas partes.
    sscanf(nc, "%s %s", n1, n2);

    // Recebe o nome digitado pelo usuário separando em duas partes.
    sscanf(input, "%s %s", inputN1, inputN2);

    // Verificação se o usuário digitou apenas o primeiro nome.
    if (strlen(inputN2) == 0) {
        // Verificação se o primeiro nome digitado pelo usuário é igual ao nome do paciente da lista
        if (strcmp(inputN1, n1) == 0) {
            // Retorna 0 caso sejam iguais.
            return 0;
        }
    } else {
        // Compara se o primeiro e o segundo nome são iguais, tendo em vista que o usuário digitou ambos os nomes.
        if (strcmp(inputN1, n1) == 0 && strcmp(inputN2, n2) == 0) {
            // Retorna 0 caso sejam iguais.
            return 0;
        }
    }
    // Retorna -1 caso não encontre o usuário pelo nome.
    return -1;
}

// Função que verifica se o cpf digitado pelo paciente é de algum paciente da lista.
int busca_cpf(char *input, char nc[]) {
    
    // Variável que armazena o CPF já formatado digitado anteriormente pelo usuário.
    char *cpfFormatado = formataCPF(input);

    // Verificação se o CPF digitado pelo usuário é igual ao CPF do paciente presente na lista.
    if (strcmp(cpfFormatado, nc) != 0) {
        // Caso não sejam iguais, libera a memória alocada para armazenar o CPF formatado e retorna 1.
        free(cpfFormatado);
        return 1;
    }
    // Caso sejam iguais, libera a memória do cpf formatado e retorna 0.
    free(cpfFormatado);
    return 0;
 
}

// Função que verifica e formata o CPF, retornando o CPF já formatado.
char* formataCPF(char *cpf) {
    // Índice para saber quando adicionar os pontos e traços do cpf.
    int iCPFormatado = 0;
    // Primeiro verifica se o CPF digitado pelo usuário está fora do formato padrão.
    if (strlen(cpf) == 11) {
        // Caso esteja fora do formato, aloca dinamicamente um ponteiro para um vetor de tipo char com tamanho 15.
        char *cpfFormatado = (char *)malloc(15 * sizeof(char));
        // Loop para percorrer o cpf fora do formato e adicionar as determinadas pontuações no cpf do usuário.
        for (int i = 0; i <= 11; i++) {
                // Se o índice i for múltiplo de 3, diferente de 0 (para não adicionar um ponto no início) e menor do que 9 então adicione o ponto.
                if (i % 3 == 0 && i < 9 && i != 0) {
                cpfFormatado[iCPFormatado] = '.';
                iCPFormatado += 1;
            }
            // Se o índice for igual a nove, adicione o traço - .
            if (i == 9) {
                cpfFormatado[iCPFormatado] = '-';
                iCPFormatado += 1;
            }
            // Caso não seja nenhum das verificações acima, adicionar o próprio número do CPF digitado pelo usuário.
            cpfFormatado[iCPFormatado] = cpf[i];
            iCPFormatado += 1;
        }
        // Adiciona um FIM na variável do CPF formatado.
        cpfFormatado[strlen(cpfFormatado)] = '\0';
        // Retorna o ponteiro para o vetor.
        return cpfFormatado;
    }
    // Caso não esteja fora do formato, retorna o próprio cpf digitado pelo usuário.
    return cpf;
}


// Função que imprime as informações de apenas um paciente.
void imprimir_paciente(ListNode *paciente) {

    printf("\n");
    printf("ID CPF             NOME           IDADE   DATA CADASTRO\n");
    if (paciente == NULL) {
        printf("ERRROOOOOOOO!!\n");
        return;
    }   
    
    printf("%d  %14s  %s  %d      %s\n", paciente->id, paciente->cpf, paciente->nome, paciente->idade, paciente->data_cadastro);
    printf("\n");
}


// Função que imprime as informações de todos os pacientes presentes na lista.
void imprimir_ListaPacientes(LinkedList *pacientes) {

    // Cria um nó temporário que recebe o valor do primeiro paciente da lista pacientes.
    ListNode *p = pacientes->first;

    printf("Lista de Pacientes: \n");
    //Verificação se a lista está vazia.
    if (p == NULL) {
        printf("A lista está vazia!!\n");
    }   
    // Loop enquanto p for diferente de NULL (até o fim da lista)
    while (p != NULL) {
        printf("ID: %d, CPF: %14s, NOME: %s, IDADE: %d, DATA CADASTRO: %s\n", p->id, p->cpf, p->nome, p->idade, p->data_cadastro);
        p = p->next;
    }

}


void atualizar_paciente(LinkedList *pacientes) {

    ListNode *p = pacientes->first;
    int idInput, idadeNew;
    char sIdade[3];
    char inputCPF[15];
    char inputNome[50];
    char inputDC[11];

    // Verifica se há pacientes cadastrados antes de prosseguir
    if (consultar_paciente(pacientes) == 1) {
        return;
    }

    printf("Digite o ID do registro a ser atualizado: \n");
    scanf(" %d", &idInput);

    // Percorre a lista até encontrar o paciente com o ID correspondente
    while (p->id != idInput) {
        p = p->next;
    }

    // Solicita novos valores para os campos
    printf("Digite o novo valor para os campos CPF, Nome, Idade e Data Cadastro (para manter o valor atual de um campo, digite '-'): \n");
    printf("CPF: \n");
    scanf(" %[^\n]", inputCPF);

    printf("Nome: \n");
    scanf(" %[^\n]", inputNome);

    printf("Idade: \n");
    scanf(" %s", sIdade);

    printf("Data Cadastro: \n");
    scanf(" %[^\n]", inputDC);

    // Confirmação da atualização
    printf("Confirma os novos valores para o registro abaixo? (S/N)\n");
    printf("\n");
    // Chama a função que imprime a prévia da edição dos dados do usuário, antes de modificar algo na própria estrutura.
    imprimir_previa_paciente(inputCPF, inputNome, sIdade, inputDC, p);
    char c;
    scanf(" %c", &c);
    printf("\n");
    // Caso confirme a atualização, verifica os campos com - para mante-los e modifica os campos com um input diferente de - .
    if (c == 'S' || c == 's') {
        if (strcmp(inputCPF, "-") != 0) {
            strcpy(p->cpf, formataCPF(inputCPF));
        } if (strcmp(inputNome, "-") != 0) {
            strcpy(p->nome, inputNome);
        } if (strcmp(sIdade, "-") != 0) {
            sscanf(sIdade, "%d", &idadeNew);
            p->idade = idadeNew;
        } if (strcmp(inputDC, "-") != 0) {
            strcpy(p->data_cadastro, inputDC);
        }
        // Mostra a atualização
        printf("Registro atualizado com sucesso.\n");
        imprimir_paciente(p);
    } else {
        // Mostra os dados não alterados e que a atualização foi cancelada.
        printf("Atualizacao cancelada!!!\n");
        imprimir_paciente(p);
    }


    // FALTA SALVAR NO ARQUIVO A EDICAO!!! N SEI SE FACO AQUI OU NO MAIN QDO FECHAR...

}

// Funcao que imprime as possíveis novas informações de um paciente.
void imprimir_previa_paciente(char *cpf, char *nome, char *idade, char *data_cadastro, ListNode *p) {

    // Verificação de quais dados serão atualizados.
    int idadeNew;
    if (strcmp(cpf, "-") == 0) {
        cpf = p->cpf;
    } if (strcmp(nome, "-") == 0) {
        nome = p->nome;
    } if (strcmp(idade, "-") == 0) {
        idadeNew = p->idade;
    } else {
        sscanf(idade, "%d", &idadeNew);
    } if (strcmp(data_cadastro, "-") == 0) {
        data_cadastro = p->data_cadastro;
    }
    
    printf("\n");
    printf("ID CPF             NOME           IDADE   DATA CADASTRO\n");
    if (p == NULL) {
        printf("ERRROOOOOOOO!!\n");
        return;
    }   
    
    // imprime os possíveis novos dados.
    printf("%d  %14s  %s  %d      %s\n", p->id, cpf, nome, idadeNew, data_cadastro);

}


// Função que remove um paciente da lista duplamente encadeada de pacientes.
void remover_paciente(LinkedList *pacientes) {

    // Criação de um nó temporário que começa com os valores do primeiro paciente da lista.
    ListNode *p = pacientes->first;
    int idInput;
    char c;

    // Verifica se há pacientes cadastrados antes de prosseguir
    if (consultar_paciente(pacientes) == 1) {
        return;
    }

    // Recebe o ID do paciente a ser alterado.
    printf("Digite o ID do paciente a ser excluido:\n");
    scanf(" %d", &idInput);

    // Percorre a lista até encontrar o paciente com o ID correspondente.
    while(p->id != idInput) {
        p = p->next;
    }

    // Confirmação antes de excluir
    printf("Tem certeza de que deseja excluir o registro abaixo? (S/N)\n");
    imprimir_paciente(p);
    scanf(" %c", &c);

    // Caso confirme a exclusão,
    if (c == 's' || c == 'S') {
        // Verifica se o Paciente não é o último da lista
        if (p->next != NULL && p->prev != NULL) {
            // O paciente anterior a p (paciente atual) aponta para o paciente à frente de p (paciente atual)
            p->prev->next = p->next;
             // O paciente à frente a p aponta agora não mais para p e sim para o elemento anterior a p.
            p->next->prev = p->prev;
        } else if (p->next == NULL) {
            // Caso o paciente seja o último da lista, o elemento anterior agora aponta para NULL, se tornando o último elemento da lista.
            pacientes->last = p->prev;
            p->prev->next = NULL;
            // Caso seja o primeiro, o primeiro elemento se torna p->next.
        } else if (p->prev == NULL) {
            pacientes->first = p->next;
            p->next->prev = NULL;
        }
        // Nó  do paciente atual next e prev aponta para NULL
        p->next = NULL;
        p->prev = NULL;
        // Libera memória do nó.
        free(p);
        printf("Registro removido com sucesso.\n");
    } else {
        printf("Exclusao cancelada!!!\n");
    }

    // Imprime a função de imprimir a informaçao de todos os pacientes.
    imprimir_ListaPacientes(pacientes);
}


void inserir_paciente(LinkedList *pacientes) {

    // Variáveis temporárias
    int idadeNew;
    char sIdade[3];
    char inputCPF[15];
    char inputNome[50];
    char inputDC[11];
    char c;

    // Input das informações do novo usuário.
    printf("Para adicionar um novo paciente ao sistema, digite as informacoes a seguir:\n");
    printf("CPF:\n");
    scanf(" %[^\n]", inputCPF);
    
    printf("Nome:\n");
    scanf(" %[^\n]", inputNome);

    printf("Idade:\n");
    scanf(" %s", sIdade);
    sscanf(sIdade, "%d", &idadeNew);

    printf("Data Cadastro:\n");
    scanf(" %[^\n]", inputDC);

    // Criação de um novo nó que fará parte da lista.
    ListNode *p = criar_node((pacientes->last->id) + 1, formataCPF(inputCPF), inputNome, idadeNew, inputDC);

    // Confirmação da inserção
    printf("Confirma a insercao do registro abaixo? (S/N)\n");
    printf("\n");
    imprimir_paciente(p);

    scanf(" %c", &c);

    // Se confirmado, 
    if (c == 's' || c == 'S') {
        // Último paciente da lista aponta para o novo paciente criado.
        pacientes->last->next = p;
        // O ponteiro para o antecessor do P aponta para o último elemento da lista.
        p->prev = pacientes->last;
        // P next aponta para NULL, pois ele é o último elemento da lista agora.
        p->next = NULL;
        // Ponteiro último aponta para o novo paciente (p) que acabou de ser adicionado na lista.
        pacientes->last = p;

        printf("O registro foi inserido com sucesso!\n");
    } else {
        // Libera memória alocada pelo nó e cancela o salvamento.
        free(p);
        printf("Insercao cancelada!!!!\n");
    }
    imprimir_ListaPacientes(pacientes); 
}


// Função que salva as informações da estrutura pacientes (lista pacientes) no arquivo bd_paciente.csv.
void salvarInformacoesArquivo(LinkedList *pacientes) {

    // Cria um ponteiro do tipo FILE, abrindo o mesmo no modo de escrita, para atualizar com os novos dados.
    FILE *f = fopen("bd_paciente.csv", "w");

    // Verifica se conseguiu abrir o arquivo.
    if (f == NULL) {
        printf("Erro ao abrir o arquivo!\n");
    }


    // Variável string temporária para formatação de todos os dados.
    char output_string[100];
    // Criação de um nó temporário que começa com os valores do primeiro elemento da lista.
    ListNode *p = pacientes->first;
    // loop enquanto não acabar (fim da lista) para a escrita das informações de todos os pacientes para o arquivo, sendo 1 paciente por linha.
    while (p != NULL) {
        // Junta os dados do paciente já formatados para dentro da output_string
        sprintf(output_string, "%d,%s,%s,%d,%s\n", p->id, p->cpf, p->nome, p->idade, p->data_cadastro);
        // Escreve essa nova linha com os dados do paciente no arquivo.
        fprintf(f, "%s" ,output_string);
        // Passa para o próximo paciente.
        p = p->next;
    }
    // Indica que deu certo!
    printf("Informacoes foram salvas com sucesso!!!!\n");
}