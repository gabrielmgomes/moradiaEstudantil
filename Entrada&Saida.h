#include <stdlib.h>
#include <stdio.h>

//Definição do TAD Aluno
typedef struct Aluno{
    int matricula, exigencia, semestres;
    struct Aluno* proximoAluno;
}ALUNO;

//Definição do TAD apartamento
typedef struct Apartamento{
    int numero, qualidade;
    struct Apartamento* proximoApartamento;
}APARTAMENTO;

typedef ALUNO* FILADEALUNOS;

typedef APARTAMENTO* FILADEAPARTAMENTOS;

void CriaFilaDeAlunos(FILADEALUNOS* FilaDeAlunos);

void CriaFilaDeApartamentos(FILADEAPARTAMENTOS* FilaDeApartamentos);

void EnfileiraAluno(FILADEALUNOS* FilaDeAlunos, int matricula, int exigencia, int semestres);

void AceitaApartamento(FILADEALUNOS* FilaDeAlunos);

void RecusaApartamento(FILADEALUNOS* FilaDeAlunos);

void DevolveApartamento(FILADEALUNOS* FilaDeAlunos);

void ListarAlunos(FILADEALUNOS FilaDeAlunos);

void EnfileiraApartamento(FILADEAPARTAMENTOS* FilaDeApartamentos, int numero, int qualidade);

void ListarApartamentos(FILADEAPARTAMENTOS FilaDeApartamentos);

void SaiApartamento(FILADEAPARTAMENTOS* FilaDeApartamentos);
