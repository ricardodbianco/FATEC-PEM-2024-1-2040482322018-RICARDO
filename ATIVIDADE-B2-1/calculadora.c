#include <stdio.h>

float adicao(float a, float b) {
    return a + b;
}

float subtracao(float a, float b) {
    return a - b;
}

float multiplicacao(float a, float b) {
    return a * b;
}

float divisao(float a, float b) {
    if (b == 0) {
        printf("Erro: Divisão por zero não é permitida.\n");
        return 0;
    } else {
        return a / b;
    }
}

int main() {
    char operacao;
    float num1, num2, resultado;

    do {
        printf("Escolha a operacao desejada (+, -, *, /) ou 'S' para sair: ");
        scanf(" %c", &operacao);

        if (operacao == 'S' || operacao == 's') {
            printf("Encerrando a calculadora.\n");
            break;
        }

        printf("Digite o primeiro operando: ");
        scanf("%f", &num1);
        printf("Digite o segundo operando: ");
        scanf("%f", &num2);

        switch (operacao) {
            case '+':
                resultado = adicao(num1, num2);
                break;
            case '-':
                resultado = subtracao(num1, num2);
                break;
            case '*':
                resultado = multiplicacao(num1, num2);
                break;
            case '/':
                resultado = divisao(num1, num2);
                break;
            default:
                printf("Operacao invalida.\n");
                continue; 
        }

        printf("Resultado: %.2f\n", resultado);

    } while (operacao != 'S' && operacao != 's');

    return 0;
}