#include <stdio.h>
#include <stdlib.h>
#include "Entrada&Saida.h"

int main()
{
    //Declara��o de vari�veis
    FILADEALUNOS FilaDeAlunos;
    FILADEAPARTAMENTOS FilaDeApartamentos;

    //Cria��o das filas
    CriaFilaDeAlunos(&FilaDeAlunos);
    CriaFilaDeApartamentos(&FilaDeApartamentos);

    puts("Iniciar: ");

    ListarAlunos(FilaDeAlunos);
    EnfileiraAluno(&FilaDeAlunos, 110072791, 100, 10);
    EnfileiraAluno(&FilaDeAlunos, 140040544, 100, 11);
    ListarAlunos(FilaDeAlunos);

    ListarApartamentos(FilaDeApartamentos);
    EnfileiraApartamento(&FilaDeApartamentos,1,75);
    EnfileiraApartamento(&FilaDeApartamentos,2,80);
    ListarApartamentos(FilaDeApartamentos);

    return 0;
}
