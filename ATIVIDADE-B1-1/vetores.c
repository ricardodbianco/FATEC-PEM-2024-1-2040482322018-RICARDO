#include <stdio.h>
#include <stdlib.h>

float notaTeste(int tamanho, float *testeAtual);

int main() {
  float   notaRaciocinioLogico = 0;
  float   notaConceitosDeGerenciamentoDeProjetos = 0;
  float   notaLinguaInglesa = 0;
  float   notaConceitosDeMetodologiaAgil = 0;
  float   notaLinguagemJavascript = 0;
  float   notaFinal = 0;

  int provaAtual = 1;
  int provasTotais = 5;
  int questoes = 0;

  while (provaAtual <= provasTotais) {

    while (questoes <= 2) {
      printf("Nº de questões da prova:\n");
      scanf("%i", &questoes);

      if (questoes <= 2)
        printf("A quantidade de questões deve ser maior que 2.\n");
    }
    float notasProvaAtual[questoes];

    float *notaAtual;

    printf("Notas:\n");

    switch (provaAtual) {
      case 1:
        notaAtual = &notaRaciocinioLogico;
        break;
      case 2:
        notaAtual = &notaConceitosDeGerenciamentoDeProjetos;
        break;
      case 3:
        notaAtual = &notaLinguaInglesa;
        break;
      case 4:
        notaAtual = &notaConceitosDeMetodologiaAgil;
        break;
      case 5:
        notaAtual = &notaLinguagemJavascript;
        break;
      default:
        printf("Prova inexistente.\n");
        break;
    }

    *notaAtual = notaTeste(questoes, notasProvaAtual);

    printf("==========================\n");
    questoes = 0;
    provaAtual++;
  }

  notaFinal = notaRaciocinioLogico + notaConceitosDeGerenciamentoDeProjetos 
              + notaLinguaInglesa + notaConceitosDeMetodologiaAgil + notaLinguagemJavascript;

  printf("Nota Raciocínio lógico = %.1f\n", notaRaciocinioLogico);
  printf("Nota Conceitos de gerenciamento de projetos = %.1f\n", notaConceitosDeGerenciamentoDeProjetos);
  printf("Nota Lingua inglesa = %.1f\n", notaLinguaInglesa);
  printf("Nota Conceitos de metodologia ágil = %.1f\n", notaConceitosDeMetodologiaAgil);
  printf("Nota Linguagem javascript = %.1f\n", notaLinguagemJavascript);
  printf("Nota Final do candidato = %.1f\n", notaFinal);

  return 0;
}

float notaTeste(int tamanho, float *testeAtual) {
  float   nota = 0;
  float   maiorNota = 0;
  float   menorNota = 10.0;
  float   notaTesteTotal = 0;

  for (int i = 0; i < tamanho; i++) {
    scanf("%f", &nota);

    while (nota > 10 || nota < 0) {
      printf("Somente notas entre 0,0 e 10,0 são válidas.\n");
      scanf("%f", &nota);
    }

    testeAtual[i] = nota;
    notaTesteTotal += testeAtual[i];

    if (maiorNota < testeAtual[i]) 
        maiorNota = testeAtual[i];

    if (menorNota > testeAtual[i]) 
        menorNota = testeAtual[i];
  }
  notaTesteTotal = notaTesteTotal - (maiorNota + menorNota);

  if (notaTesteTotal <= 0) 
      notaTesteTotal = 0;

  return notaTesteTotal;
}