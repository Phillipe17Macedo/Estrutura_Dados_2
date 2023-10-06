#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_NOMES 1000
#define MAX_TAM_NOME 100


int strcasecmp(const char *s1, const char *s2) {
    while (*s1 && *s2) {
        int diff = tolower((unsigned char)*s1) - tolower((unsigned char)*s2);
        if (diff != 0) return diff;
        s1++;
        s2++;
    }
    return tolower((unsigned char)*s1) - tolower((unsigned char)*s2);
}


bool buscaBinariaInicioPalavra(char nomes[][MAX_TAM_NOME], int n, char *consulta) {
    int esquerda = 0, direita = n - 1;
    bool encontrado = false;

    while (esquerda <= direita) {
        int meio = (esquerda + direita) / 2;


        int cmp = strcasecmp(consulta, nomes[meio]);

        if (cmp == 0) {
            encontrado = true;
            break;
        } else if (cmp < 0) {
            direita = meio - 1;
        } else {
            esquerda = meio + 1;
        }
    }

    if (encontrado) {

        printf("%s\n", nomes[esquerda]);
        esquerda++; 
        while (esquerda <= direita) {
            if (strncasecmp(consulta, nomes[esquerda], strlen(consulta)) == 0) {
                printf("%s\n", nomes[esquerda]);
                esquerda++;
            } else {
                break;
            }
        }
        return true;
    } else {
        return false;
    }
}

int main() {
    char nomes[MAX_NOMES][MAX_TAM_NOME];
    int n = 0;


    FILE *arquivo = fopen("nomes.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    while (n < MAX_NOMES && fscanf(arquivo, "%99s", nomes[n]) == 1) {
        n++;
    }

    qsort(nomes, n, sizeof(nomes[0]), (int (*)(const void *, const void *))strcasecmp);


    char consulta[MAX_TAM_NOME];
    printf("Digite a consulta (ignorando maiúsculas e minúsculas): ");
    scanf("%99s", consulta);

    if (!buscaBinariaInicioPalavra(nomes, n, consulta)) {
        printf("Nenhum nome encontrado.\n");
    }

    fclose(arquivo);

    return 0;
}
