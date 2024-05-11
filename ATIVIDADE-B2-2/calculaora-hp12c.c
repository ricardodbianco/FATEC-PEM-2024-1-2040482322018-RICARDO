#include <stdio.h>  //Importar Biblioteca
#include <stdlib.h>   //Importar Biblioteca
#include <string.h> //Incluir Biblioteca de String 
#define MAX_SIZE 100 //Definição de um tamanho máximo
//A declaração das variáveis são inseridas em inglês, devido uma padronização  sintática e semántica e por ser a linguagem universal no hall profissional
// Definição da estrutura e tipo de pilha
typedef struct {
    float items[MAX_SIZE];      //Inclusão de números quebrados de itens com o máximo de estrutura
    int top; 
} Stack;
// Iniciando a função da pilha, sempre no processo de retirada será considerado o último item na colocação -1, a partir do topo( "o último a entrar é o primeiro a sair")
void initialize(Stack *s) {
    s->top = -1;
}
// Processo para checar se a pilha está vazia
int isEmpty(Stack *s) {
    return s->top == -1;
}
// Processo para checar se a pilha está cheia
int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}
// Descrição da função para colocar um elemento, colocando como condição se a pilha estiver cheia, deve aparecer "erro a pilha está cheia", caso contrário efetua-se a operação
void push(Stack *s, float value) {
    if (isFull(s)) {
        printf("Erro: a pilha está cheia \n");
    } else {
        s->top++;
        s->items[s->top] = value;
    }
}
// Para verificar se a pilha está vazia(caso esteja irá aparecer "erro, pilha vazia"), caso contrário irá  inserir o valor e realizar a operação necessária
float pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Erro: a pilha está vazia \n");
        return 0;
    } else {
        float value = s->items[s->top];
        s->top--;
        return value;
    }
}
// Irá inicializar a programação, pedindo ao usuário para inserir os operadores e os operandos com no máximo 100 itens na "string"
int main() {
    Stack s;
    initialize(&s);
    char operacao[100];
    float num;
    char *token;
    printf("Insira a operação RPN (máximo 9 caracteres): ");
    fgets(operacao, sizeof(operacao), stdin);
    // Remove o espaço/linha entre os caracteres 
    operacao[strcspn(operacao, "\n")] = 0;
    // Faz a verificação e certificação da operação
    token = strtok(operacao, " ");
    while (token != NULL) {
        // Verificação de qual caractere deve-se colocar na pilha
        if (sscanf(token, "%f", &num) == 1) {
            push(&s, num);
        } else {
            // Verificar se caractere é um operador, caso seja, realizará a operação necessária 
            float num2 = pop(&s);
            if (isEmpty(&s)) {
                printf("Erro: expressão incompleta\n");
                return 1;
            }
            float num1 = pop(&s);
            switch (token[0]) {
                case '+':
                    push(&s, num1 + num2);
                    break;
                case '-':
                    push(&s, num1 - num2);
                    break;
                case '*':
                    push(&s, num1 * num2);
                    break;
                case '/':
                    if (num2 != 0)
                        push(&s, num1 / num2);
                    else {
                        printf("Erro: divisão pelo zero\n");
                        return 1;
                    }
                    break;
                default:
                    printf("operação inválida : %c\n", token[0]);
                    return 1;
            }
        }
        // Mover para o próximo item 
        token = strtok(NULL, " ");
    }
    if (s.top != 0) {
        printf("Erro: expressão incompleta \n");
        return 1;
    }
    // O resultado será considerado o valor no topo da pilha
    printf("Resultado: %.2f\n", pop(&s));
    return 0;
}