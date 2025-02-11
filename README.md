# HealthSys

Trabalho de Estrutura de Dados desenvolvido na linguagem C pelos alunos Matheus de Oliveira Magnago e Myllena Toniato.

Este trabalho criado em linguagem C consiste na criação de um sistema de gerenciamento de dados do qual é dividido em seis opções, sendo de 1 a 5 a consulta, atualização, remoção, inserção ou impressão dos dados cadastrais do paciente no sistema, respectivamente. A última opção é a saída do sistema, dada pela letra Q (Quit), na qual possibilita salvar os dados modificados até aquele momento dentro do arquivo CSV.

A organização do repositório se deu através:
Do arquivo main.c que contém a função principal do programa, com o menu interativo;
Do arquivo paciente.h, da qual define todas as funções desenvolvidas no arquivo paciente.c
Do arquivo paciente.c, da qual discorre o código de execução de todas as funções do sistema;
Do arquivo bd_paciente.csv que contém o armazenamento dos dados dos pacientes do sistema.
Do arquivo Makefile para compilação do projeto;
Do arquivo README.md, apresentado por meio deste, e contendo informações sobre o trabalho e instruções para sua execução. 

Os TADs utilizados foram LinkedList e ListNode, sendo responsáveis por gerenciar uma estrutura de listas duplamente encadeadas e armazenar os dados dos pacientes, respectivamente. Ao utilizar esses TADs, o sistema conta com uma lista duplamente encadeada para o armazenamento de dados dos pacientes, com cada nó da lista contendo as informações de ID, CPF, nome, idade e data de cadastro, além dos ponteiros para o próximo elemento e o elemento anterior.

Ao escolher entre opções da página inicial, que variam de 1 a 5 e a opção de sair do sistema, o usuário é direcionado para outra página de acordo com a opção escolhida.

A função formataCPF foi elaborada pensando em possíveis erros do usuário, possibilitando a escrita em formatação padrão do CPF (XXX.XXX.XXX-XX) ou sem formatação, contendo só números.

Duas funções possuem o objetivo de buscar informações do cliente, sendo a primeira busca_nome, onde somente o nome do paciente é inserido, e a segunda busca_cpf, onde o CPF é inserido. A função para busca de nomes também conta com diferentes possibilidades, onde o usuário pode escrever somente o nome e ler uma lista de pacientes com aquele nome inserido, ou escrever o nome e sobrenome, para ter acesso mais restrito à pessoas específicas.

A função inserir_paciente, além de cumprir com o que promete, gera um ID para o novo paciente a partir do último ID presente na lista. 

A opção 1 abre a consulta do paciente, sendo dividida em três opções:
Consulta por nome, onde o usuário pode digitar o nome com sobrenome, para buscar por pacientes mais específicos ou sem sobrenome, mostrando todos os pacientes com nomes em comum.
Consulta por CPF, onde o usuário pode digitar tanto em formato de CPF (XXX.XXX.XXX-XX) quanto sem a formatação necessária, pois o programa converte o input no formato adequado e compara com o CPF dos pacientes da lista.
Retornar ao menu principal, onde o usuário volta à tela inicial.

A segunda opção também é organizada em três opções, iguais à da opção anterior, para que haja primeiro a consulta do paciente. Ao ter os dados dele impressos na tela, o próximo passo é digitar o ID do paciente a ser atualizado. Dessa forma, o sistema oferece a opção de atualização de todos os campos de dados disponíveis, entre CPF, nome, idade e data de cadastro. Os dados devem ser preenchidos de acordo com o campo correspondente e, caso não haja a necessidade de atualização de algum desses campos, o sistema disponibiliza o input de “-” para que eles sejam mantidos da forma atual. 

Na opção de remoção de pacientes, a página de consulta do paciente também é apresentada, seguida do campo de digitar o ID, tal qual executada na segunda opção, porém sendo finalizada na próxima página, onde o usuário deve digitar “Y” para confirmar a remoção do paciente ou “N” para negá-la. Essa opção conta com a possibilidade de digitação tanto das letras maiusculas quanto das minúsculas. 

O processo de inserção de pacientes apresenta as opções de inserção de cada um dos dados do paciente, apresentando por fim os dados do paciente organizados de acordo com o sistema.

A quinta opção possibilita a impressão de cada um dos dados de todos os pacientes inseridos na lista do sistema atual.

Por fim, a última opção imprime um aviso informando que as informações foram salvas com sucesso, garantindo que todas as modificações feitas durante o uso do usuário sejam salvas ao sair do sistema.

Como rodar o código?
	No windows, siga estes passos: 

Abra o prompt (cmd) e utilize o comando cd <caminho do arquivo> para entrar na pasta do projeto.

Utilize o comando gcc <nomearquivo.c> -o <nomedoexecutável>, para o sistema compilar o arquivo .c para a linguagem da máquina, e retornar o arquivo executável.
Agora, basta digitar o nome do executável que você escolheu anteriormente para rodar o programa.

  No linux, siga estes passos:
    make
    make run
