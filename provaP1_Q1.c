#include <stdio.h>
#include <stdbool.h>

#define MAX_SECOES 5
#define MAX_GONDOLAS 15
#define MAX_PRODUTOS 20

char armazem[MAX_SECOES][MAX_GONDOLAS][MAX_PRODUTOS];

void inicializarArmazem() {
    int i, j, k;
    for (i = 0; i < MAX_SECOES; i++) {
        for (j = 0; j < MAX_GONDOLAS; j++) {
            for (k = 0; k < MAX_PRODUTOS; k++) {
                armazem[i][j][k] = 0;  
            }
        }
    }
}

void cadastrarProduto() {
    int secao, gondola, produto;

    printf("\nDigite a seção (1 a S%d): ", MAX_SECOES);
    scanf("%d", &secao);
    printf("Digite a gôndola (1 a G%d): ", MAX_GONDOLAS);
    scanf("%d", &gondola);
    printf("Digite o código do produto (1 a P%d): ", MAX_PRODUTOS);
    scanf("%d", &produto);

    armazem[secao-1][gondola-1][produto-1] = 1;

    printf("Produto S%d-G%d-P%d cadastrado\n", secao, gondola, produto);
    printf("----------------------------------------------\n");
}

void consultarLista() {
    int i, j, k;
    if (armazem[i][j][k] == 0){
        printf("Nao ha itens ainda\n");
        printf("----------------------------------------------\n");
    }else{
        for (i = 0; i < MAX_SECOES; i++) {
            for (j = 0; j < MAX_GONDOLAS; j++) {
                for (k = 0; k < MAX_PRODUTOS; k++) {
                    if (armazem[i][j][k] != 0) {  
                        printf("\nProduto S%d-G%d-P%d\n", i+1, j+1, k+1);
                        printf("----------------------------------------------\n");
                    }
                }
            }
        }
    }
}

void consultarProduto() {
    int secao, gondola, produto;
    bool encontrado = false;

    printf("Digite a seção (S1 a S%d): ", MAX_SECOES);
    scanf("%d", &secao);
    printf("Digite a gôndola (G1 a G%d): ", MAX_GONDOLAS);
    scanf("%d", &gondola);
    printf("Digite o código do produto (P1 a P%d): ", MAX_PRODUTOS);
    scanf("%d", &produto);

    if (armazem[secao-1][gondola-1][produto-1] != 0) {
        printf("Produto S%d-G%d-P%d encontrado\n", secao, gondola, produto);
        printf("----------------------------------------------\n");
        encontrado = true;
    }

    if (!encontrado) {
        printf("Produto S%d-G%d-P%d não encontrado\n", secao, gondola, produto);
        printf("----------------------------------------------\n");
    }
}

int main() {
    int escolha = 0;
    inicializarArmazem();

    while (true) {
        printf("1-Cadastrar Produto\n2-Consultar lista\n3-Consultar um produto\n4-Sair\nEscolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
                consultarLista();
                break;
            case 3:
                consultarProduto();
                break;
            case 4:
                printf("Até mais\n");
                return 0;
            default:
                printf("Erro, escolha uma opcao valida!\n");
                break;
        }
    }

    return 0;
}
