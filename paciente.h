#ifndef PACIENTE_H
#define PACIENTE_H

// Definindo a Lista Encadeada de pacientes.
typedef struct pacientes LinkedList;

// Definindo cada nó da lista encadeada, ou seja, cada paciente.
typedef struct paciente ListNode;

// Define a funcao para ler pacientes de um arquivo externo.
void carregar_pacientes(const char* nomeArquivo, LinkedList *pacientes);

// Definindo a função que cria uma lista encadeada vazia.
LinkedList *criar_ListaPacientes();

// Define a funcao que cria um no (paciente)
ListNode *criar_node(int idr, char* cpfr, char* nomer, int idader, char* dc);

// Define a função de buscar(consultar) paciente.
int consultar_paciente(LinkedList *pacientes);

// Define a função de encontrar paciente (percorre lista de pacientes).
void encontraPaciente(LinkedList *pacientes, int choice, char *input);

// Define a função de buscar o nome (verifica se o nome que o usuário digitou é igual ao nome de algum paciente da lista)
int busca_nome(char *input, char nc[]);

// Define a função de buscar o cpf (verifica se o cpf que o usuário digitou é igual ao nome de algum paciente da lista)
int busca_cpf(char *input, char nc[]);

// Define a função que verifica se o CPF está fora do formato, caso esteja, ele formata o CPF que o usuário digitou.
char* formataCPF(char *cpf);

// Função que imprime apenas um paciente da lista encadeada (nó).
void imprimir_paciente(ListNode *paciente);

// Função que imprime os novos dados do paciente sem que faça uma mudança no local original antes da confirmação do usuário.
void imprimir_previa_paciente(char *cpf, char *nome, char *idade, char *data_cadastro, ListNode *paciente);

// Função que percorre a lista de pacientes, passando 1 por 1 até o fim da mesma.
void percorrer_listaPacientes(LinkedList *pacientes, int choice, char *input);

// Define a função de atualizar paciente.
void atualizar_paciente(LinkedList *pacientes);

// Define a funcao de remover paciente.
void remover_paciente(LinkedList *pacientes);

// Define a funcao de adicionar paciente.
void inserir_paciente(LinkedList *pacientes);

// Defina funcao de imprimir na tela a lista de pacientes.
void imprimir_ListaPacientes(LinkedList *pacientes);

// Salva todas as modificacoes e novos pacientes adicionados.
void salvarInformacoesArquivo(LinkedList *pacientes);

// Libera espaço de todos os nós e da própria lista de pacientes.
void liberar_memoria(LinkedList *pacientes);

#endif