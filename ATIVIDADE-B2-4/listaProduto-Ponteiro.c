#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  int id_prod;
  char nm_prod[50];
  char ds_prod[50];
  float vl_prod;
  int qt_prod;
} Produto;

Produto criarProduto(int id, char nome[], char descricao[], float valor, int qt) {
  Produto prod;
  prod.id_prod = id;
  strcpy(prod.nm_prod, nome);
  strcpy(prod.ds_prod, descricao);
  prod.vl_prod = valor;
  prod.qt_prod = qt;
  return prod;
}

void ordenarProduto(Produto *produtos, int maxProd) {
  int i, j;
  for (i = 0; i < maxProd - 1; i++) {
    for (j = 0; j < maxProd - i - 1; j++) {
      if (strcmp(produtos[j].nm_prod, produtos[j + 1].nm_prod) > 0) {
        Produto aux = produtos[j];
        produtos[j] = produtos[j + 1];
        produtos[j + 1] = aux;
      }
    }
  }
}

void inserirProduto(Produto *produtos, int maxProd) {
    int busca, quantidade, selecao;
    float total = 0.0;
    Produto *p;

    printf("* COMPRA SIMULADA *\n");
    printf("Quantos produtos deseja selecionar? \n");
    scanf("%d", &selecao);

    printf("\n* NOTA FISCAL SIMULADA *\n");
    for (int i = 0; i < selecao; i++) {
        printf("\n Digite o id do produto: ");
        scanf("%d", &busca);

        p = NULL;
        for (int j = 0; j < maxProd; j++) {
            if (produtos[j].id_prod == busca) {
                p = &produtos[j];
                break;
            }
        }

        if (p != NULL) {
            printf("\n PRODUTO ENCONTRADO: %s\n", p->nm_prod);
            printf("\n Digite a quantidade do produto: ");
            scanf("%d", &quantidade);

            if (quantidade <= p->qt_prod) {
                p->qt_prod -= quantidade;
                total += quantidade * p->vl_prod;
                printf(" %s\tR$%.2f x %d\n", p->nm_prod, p->vl_prod, quantidade);
            } else {
                printf("\n Quantidade solicitada não disponível em estoque.\n");
                selecao++;
            }
        } else {
            printf("\n Produto Inexistente.\n");
            selecao++;
        }
    }

    if (total > 0) {
        printf("\n VALOR TOTAL: %.2f\n", total);
    } else {
        printf("Nenhuma venda para mostrar na nota fiscal.\n");
    }
}

int LarguraNome(Produto produtos[], int maxProd) {
  int max = 0;
  for (int i = 0; i < maxProd; i++) {
    int min = strlen(produtos[i].nm_prod);
    if (min > max) {
      max = min;
    }
  }
  return max;
}

int LarguraDescricao(Produto produtos[], int maxProd) {
  int max = 0;
  for (int i = 0; i < maxProd; i++) {
    int min = strlen(produtos[i].ds_prod);
    if (min > max) {
      max = min;
    }
  }
  return max;
}

void imprimirLista(Produto *produtos, int maxProd) {
  int tamanhoNome = LarguraNome(produtos, maxProd);
  int tamanhoDesc = LarguraDescricao(produtos, maxProd);

  if (tamanhoDesc < 10) {
    tamanhoDesc = 10;
  }

  printf("\nID\t");
  printf("NOME");
  for (int i = 0; i < tamanhoNome - 4; i++) { 
    printf(" ");
  }
  printf("\tDESCRIÇÃO");
  for (int i = 0; i < tamanhoDesc - 10; i++) { 
    printf(" ");
  }
  printf("\tVALOR\tESTOQUE\n");

  for (int i = 0; i < maxProd; i++) {
    printf("%d\t%-*s\t%-*s\t%.2f\t%d\n", produtos[i].id_prod, tamanhoNome, produtos[i].nm_prod, tamanhoDesc, produtos[i].ds_prod, produtos[i].vl_prod, produtos[i].qt_prod);
  }
}


int main(void) {
  int opcao, maxProd = 0;
  Produto produtos[50] = {0}; 
  int id = 0; 

  printf("* LISTA DE PRODUTOS *\n");

  do {
    printf("\nOpções:\n");
    printf("1. Incluir Produto\n");
    printf("2. Simular Compra\n");
    printf("3. Lista de Produtos\n");
    printf("4. Sair\n");
    printf("Qual opção deseja? ");
    scanf("%d", &opcao);

    if (opcao == 1) {
      if (maxProd < 50) {
        char nome[50];
        char descricao[50];
        float valor;
        int qt;

        id++; 

        printf("Digite o nome do produto: ");
        scanf(" %[^\n]s", nome); 

        printf("Digite a descrição do produto: ");
        scanf(" %[^\n]s", descricao);

        printf("Digite seu valor unitario: ");
        scanf(" %f", &valor);

        printf("Digite sua quantidade no estoque: ");
        scanf(" %d", &qt);

        produtos[maxProd] = criarProduto(id, nome, descricao, valor, qt);
        maxProd++;

        printf("\nCadastro realizado com sucesso!\n");
      } else {
        printf("Lista cheia!\n");
      }
    } else if (opcao == 2) {
      inserirProduto(produtos, maxProd); 
    } else if (opcao == 3) {
      ordenarProduto(produtos, maxProd);
      imprimirLista(produtos, maxProd);
    }
  } while (opcao != 4);

  printf("\nLista Fechada\n");
  return 0;
}