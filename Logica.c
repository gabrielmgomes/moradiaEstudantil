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

void CriaFilaDeAlunos(FILADEALUNOS* FilaDeAlunos){
    *FilaDeAlunos = NULL;
}
void CriaFilaDeApartamentos(FILADEAPARTAMENTOS* FilaDeApartamentos){
    *FilaDeApartamentos = NULL;
}
void EnfileiraAluno(FILADEALUNOS* FilaDeAlunos, int matricula, int exigencia, int semestres){
    if(*FilaDeAlunos == NULL)
        {
            *FilaDeAlunos = (ALUNO*) malloc(sizeof(ALUNO));
            //Erro de alocação de memória
            if(*FilaDeAlunos == NULL)
                return;

            (*FilaDeAlunos)->matricula = matricula;
            (*FilaDeAlunos)->exigencia = exigencia;
            (*FilaDeAlunos)->semestres = semestres;

            (**FilaDeAlunos).proximoAluno = NULL;
        }
        else
            EnfileiraAluno(& (**FilaDeAlunos).proximoAluno, matricula, exigencia, semestres);
}
//Aluno sai da fila, pois aceitou a oferta do apartamento
void AceitaApartamento(FILADEALUNOS* FilaDeAlunos){
    ALUNO* temp = *FilaDeAlunos;

    //Não existem alunos na fila
    if(*FilaDeAlunos == NULL)
        return;

    *FilaDeAlunos = (*FilaDeAlunos)->proximoAluno;
    free(temp);
}
//Recusa apartamento e reduz a exigencia para a próxima oferta
void RecusaApartamento(FILADEALUNOS* FilaDeAlunos){
    #define DECRESCIMO 5;

    (**FilaDeAlunos).exigencia = (**FilaDeAlunos).exigencia - DECRESCIMO;
}

void DevolveApartamento(FILADEALUNOS* FilaDeAlunos);

void ListarAlunos(FILADEALUNOS FilaDeAlunos){
    if (FilaDeAlunos == NULL)
        return;
    printf("%d %d %d\n",FilaDeAlunos->matricula, FilaDeAlunos->exigencia, FilaDeAlunos->semestres);
    ListarAlunos(FilaDeAlunos->proximoAluno);
}

void EnfileiraApartamento(FILADEAPARTAMENTOS* FilaDeApartamentos, int numero, int qualidade){
    if(*FilaDeApartamentos == NULL)
        {
            *FilaDeApartamentos = (APARTAMENTO*) malloc(sizeof(APARTAMENTO));
            //Erro de alocação de memória
            if(*FilaDeApartamentos == NULL)
                return;

            (*FilaDeApartamentos)->numero = numero;
            (*FilaDeApartamentos)->qualidade = qualidade;

            (**FilaDeApartamentos).proximoApartamento = NULL;
        }
        else
            EnfileiraApartamento(& (**FilaDeApartamentos).proximoApartamento, numero, qualidade);
}

void ListarApartamentos(FILADEAPARTAMENTOS FilaDeApartamentos){
    if (FilaDeApartamentos == NULL)
        return;
    printf("%d %d\n",FilaDeApartamentos->numero, FilaDeApartamentos->qualidade);
    ListarApartamentos(FilaDeApartamentos->proximoApartamento);
}

void SaiApartamento(FILADEAPARTAMENTOS* FilaDeApartamentos){
    APARTAMENTO* temp = *FilaDeApartamentos;

    //Não existem alunos na fila
    if(*FilaDeApartamentos == NULL)
        return;

    *FilaDeApartamentos = (*FilaDeApartamentos)->proximoApartamento;
    free(temp);
}
