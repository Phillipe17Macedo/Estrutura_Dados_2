# Atividade Ordenacao

QUESTÃO 1
Utilizar os 4 algoritmos de ordenação aprendidos para:

1. Exibir um menu com 5 opções, para que o usuário digite de 1 a 4 para os algoritmos (Bubble, Selection, Insertion e Merge), ou a opção 5  para sair.
2. Ler o arquivo “nomes2.txt” em anexo. Nenhum nome possui mais que 100 caracteres.
3. Imprimir os nomes do arquivo ordenados de acordo com o algoritmo selecionado

Dicas:
 Biblioteca “string.h”;
 Usar os ponteiros FILE *arquivo para ler o mesmo;
 Usar as funções fopen para abrir o arquivo em leitura (r+), feof para determinar o fim do arquivo, fgets para ler a linha e fclose para fechar o arquivo

QUESTÃO 2
Ler o arquivo disponibilizado com os resultados do campeonato mineiro de 2022 - módulo 1, até a 7a rodada.
Calcular e ordenar o placar do campeonato, usando as seguintes regras:
1) O maior número de pontos - vitória vale 3 pontos e empate vale 1 ponto
2) mais vitórias
3) melhor saldo de gols (diferença entre gols pró e gols contra)
4) mais gols pró

Imprimir a tabela do campeonato ordenada, contendo o nome do time, pontos, num. de vitórias, empates e derrotas, saldo de gols, gols pró, gols contra.

Perguntar ao usuário qual método de ordenação usar (Bubble, Selection, Insertion ou Merge) e usar esse para ordenação dos valores.
