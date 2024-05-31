//PROGRAMA ADICIONA ALUNO E SUA NOTA FINAL, LISTA TODOS OS ALUNOS CADASTRADOS EM ORDEM ALFABÉTICA E MOSTA A SITUAÇÃO DO ALUNO(APROVADO OU REPROVADO)

//FUNÇÃO BUBBLESORT UTILIZADO PARA ORGANIZAR ALUNOS EM ORDEM ALFABÉTICA 

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 50


struct Aluno{
double notaFinal;
char nome[MAX];};

void bubbleSort(struct Aluno novoAluno[], int numeroAluno){



    for (int i = 0; i < numeroAluno-1 ; i++) {
      for(int j = 0; j < numeroAluno-1-i ; j++){
        if(strcmp(novoAluno[j].nome, novoAluno[j+1].nome) > 0){
        struct Aluno temp = novoAluno[j];
          novoAluno[j] = novoAluno[j+1];
          novoAluno[j+1] = temp;

        }
      }
    }




  //  for (int i = 0; i < numeroAluno; i++) {
//  }


}
// void listarAlunos(struct Aluno novoAluno[], int numeroAluno) {
//     printf("\nLista de Alunos:\n");
//     printf("----------------------------\n");
//     printf("Nome do Aluno\tNota\tSituação\n");
//     printf("----------------------------\n");

//   for (int i = 0; i < numeroAluno; i++) {
//       printf("%s\t\t%.2lf\t%s\n", novoAluno[i].nome, novoAluno[i].notaFinal,
//              (novoAluno[i].notaFinal >= 6.0) ? "Aprovado" : "Reprovado");
//   }
// }

int main(void) 
{
  struct Aluno novoAluno[MAX];
  int numeroAluno = 0;
  int opcao;

    do
    {
      printf("\n 1 - Novo Aluno \n 2 - Lista de Aluno \n 3 - Sair \n");
      scanf("%d", &opcao);
      switch(opcao)
      {
        case 1:
      //INCLUIR ALUNO
        if(numeroAluno>= 50 ){
        printf("Limite de alunos.");  
        }

        printf("Digite o nome do aluno: \n");
        scanf("%s", novoAluno[numeroAluno].nome);
          //LETRAS MAIUSCULAS
          for (int i = 0; novoAluno[numeroAluno].nome[i]; i++) {
            novoAluno[numeroAluno].nome[i] = toupper(novoAluno[numeroAluno].nome[i]);}
        printf("Digite a nota final do aluno: \n");

        scanf("%lf", &novoAluno[numeroAluno].notaFinal);
          numeroAluno++;
        break;

        case 2:
        bubbleSort(novoAluno, numeroAluno);
        printf("\nLista de Alunos:\n");
          printf("--------------------------------------------------\n");
          printf("Nome do Aluno\t\tNota\tSituação\n");
          printf("--------------------------------------------------\n");

        for (int i = 0; i < numeroAluno; i++) {
            printf("%-18s\t%.2lf\t%s\n", novoAluno[i].nome, novoAluno[i].notaFinal,
                   (novoAluno[i].notaFinal >= 6.0) ? "Aprovado" : "Reprovado");
        }
        break;

        case 3:

        printf("Encerrando Programa.\n");
        break;

        default:
        printf("Opção inválida\n");

      //LISTAR ALUNO - BubbleSort   
    }
    }while (opcao != 3);




    return 0;
}