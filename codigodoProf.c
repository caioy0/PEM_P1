#include <stdio.h>

void cadastrarProduto(int produtos[2][2][5], int *contador) {
    int secao, gondola, codigo;

    while (*contador < 20) {
        printf("Cadastro de produto:\n");

        printf("Digite qual a seção que ele se localiza (entre 0 e 1): ");
        scanf("%i", &secao);
        if (secao < 0 || secao > 1) {
            printf("Seção inválida! Deve ser entre 0 e 1.\n");
            continue;
        }

        printf("Digite qual a gôndola que ele se localiza (entre 0 e 1): ");
        scanf("%i", &gondola);
        if (gondola < 0 || gondola > 1) {
            printf("Gôndola inválida! Deve ser entre 0 e 1.\n");
            continue;
        }

        printf("Digite qual o código do produto (entre 0 e 4): ");
        scanf("%i", &codigo);
        if (codigo < 0 || codigo > 4) {
            printf("Código inválido! Deve ser entre 0 e 4.\n");
            continue;
        }

        if (produtos[secao][gondola][codigo] == 1) {
            printf("Produto já cadastrado nesta seção e gôndola com este código!\n");
            continue;
        }

        int totalProdutos = 0;
        for (int c = 0; c < 5; c++) {
            if (produtos[secao][gondola][c] == 1) {
                totalProdutos++;
            }
        }

        if (totalProdutos >= 5) {
            printf("Limite de produtos cadastrados nesta seção e gôndola atingido!\n");
            continue;
        }

        produtos[secao][gondola][codigo] = 1;
        (*contador)++;
        printf("Produto cadastrado com sucesso! Total de produtos cadastrados: %d\n", *contador);
        break;
    }
}

void consultarProdutos(int produtos[2][2][5]) {
    int produtoCadastrado = 0; 

    printf("Produtos cadastrados:\n");
    for (int s = 0; s < 2; s++) {
        for (int g = 0; g < 2; g++) {
            for (int c = 0; c < 5; c++) {
                if (produtos[s][g][c] == 1) {
                    printf("Seção: %d, Gôndola: %d, Código: %d\n", s, g, c);
                    produtoCadastrado = 1;
                }
            }
        }
    }

    if (!produtoCadastrado) {
        printf("Nenhum produto cadastrado!\n");
    }
}

void consultarProdutoEspecifico(int produtos[2][2][5]) {
    int codigo;

    printf("Digite o código do produto que deseja consultar (0 a 4): ");
    scanf("%i", &codigo);
    if (codigo < 0 || codigo > 4) {
        printf("Código inválido! Deve ser entre 0 e 4.\n");
        return;
    }

    printf("Consultando produto com código: %d\n", codigo);
    int encontrado = 0;

    for (int s = 0; s < 2; s++) {
        for (int g = 0; g < 2; g++) {
            if (produtos[s][g][codigo] == 1) {
                printf("Produto encontrado na Seção: %d, Gôndola: %d\n", s, g);
                encontrado = 1;
            }
        }
    }

    if (!encontrado) {
        printf("Produto não cadastrado em nenhuma seção e gôndola.\n");
    }
}

int main() {
    int escolha;
    int produtos[2][2][5] = {{{0}}}; // Inicializando o array tridimensional
    int contador = 0; // Contador de produtos cadastrados

    do {
        printf("Bem vindo ao Supermercado Verissimo!\n");
        printf("Selecione a opção desejada:\n");
        printf("Cadastrar um produto: 1\n");
        printf("Consultar lista de produtos: 2\n");
        printf("Consultar um produto específico: 3\n");
        printf("Para encerrar o programa: 4\n");
        scanf("%i", &escolha);
        
        switch(escolha) {
            case 1:
                cadastrarProduto(produtos, &contador);
                break;
            case 2:
                consultarProdutos(produtos);
                break;
            case 3:
                consultarProdutoEspecifico(produtos);
                break;
            case 4:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (escolha != 4);

    return 0;
}