#include <stdio.h>
#include <cuda.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "tempo.h"

#define TAM 30800
#define L 10
#define C 10

//aloca memória global- RAM e CPU
__managed__ int m1[C][L];
__managed__ char genoma0[TAM];
__managed__ char genoma1[TAM];
__managed__ char genoma2[TAM];
__managed__ char genoma3[TAM];
__managed__ char genoma4[TAM];
__managed__ char genoma5[TAM];
__managed__ char genoma6[TAM];
__managed__ char genoma7[TAM];
__managed__ char genoma8[TAM];
__managed__ char genoma9[TAM];
__managed__ int i = 0;

//funcao compara
//===============================================================
__global__ void compara_genoma(char genomaa[TAM], char genomab[TAM], int w, int z, int *qtd_iguais, int *qtd_dif)

{

    int idx = blockIdx.x * blockDim.x + threadIdx.x;

    if (genomaa[idx] == '0' && genomab[idx] == '0')
    {
        // break;
    }
    else
    {

        if (genomaa[idx] == genomab[idx])
        { //compara os dois nucleotideos

            atomicAdd(qtd_iguais, 1);
        }
        else
        {

            atomicAdd(qtd_dif, 1);
        }
    }

    m1[z][w] = *qtd_iguais;
}

void mostra_genomas()
{
    int i = 0;

    for (i = 0; i < TAM; i++)
    {

        printf("\n | %5d  | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | ", i,
               genoma0[i], genoma1[i], genoma2[i], genoma3[i], genoma4[i], genoma5[i], genoma6[i],
               genoma7[i], genoma8[i], genoma9[i]);
    }
}

void inicializa_vetor()
{
    for (int z = 0; z <= TAM; z++)
    {
        genoma0[z] = '0';
        genoma1[z] = '0';
        genoma2[z] = '0';
        genoma3[z] = '0';
        genoma4[z] = '0';
        genoma5[z] = '0';
        genoma6[z] = '0';
        genoma7[z] = '0';
        genoma8[z] = '0';
        genoma9[z] = '0';
    }
}

void inicializa_matriz()
{
    int z, v;
    printf("\n inicializando matrizes ...\n");
    for (z = 0; z < L; z++)
        for (v = 0; v < C; v++)
        {
            m1[z][v] = 0;
        }
}

void mostra_resultado()
{
    int z, v;
    printf("\n");
    printf("\n  RESULTADO COMPARAÇÃO DE GENOMAS\n\n");
    for (v = 0; v < C; v++)
    {
        printf("   %d   ", v);
    }
    printf("\n");
    for (z = 0; z < L; z++)
    {
        printf("%d", z);
        for (v = 0; v < C; v++)
        {

            printf("  %5.2d", m1[z][v]);
        }
        printf("\n");
    }
    printf("\n\n\n");
}

void carrega_genoma()
{

    char c;

    //genoma 1
    FILE *file1;

    //abre arquivo para leitura
    file1 = fopen("genomas/AY278741.txt", "r");

    //carrega o conteudo do arquivo no vetor genoma1
    i = 0;
    while ((c = getc(file1)) != EOF)
    { //le um nucleotideo do primeiro genoma enquanto não chegor ao final do arquivo

        genoma0[i] = c;
        i++;
    }

    //fecha arquivo
    fclose(file1);

    //-----------------------------
    //genoma 2
    FILE *file2;

    //abre arquivo para leitura
    file2 = fopen("genomas/KY417146.txt", "r");

    //carrega o conteudo do arquivo no vetor genoma1
    i = 0;

    while ((c = getc(file2)) != EOF)
    {

        genoma1[i] = c;
        i++;
    }

    //fecha arquivo
    fclose(file2);

    //-----------------------------
    //genoma 3
    FILE *file3;

    //abre arquivo para leitura
    file3 = fopen("genomas/MK211376.txt", "r");

    //carrega o conteudo do arquivo no vetor genoma1
    i = 0;

    while ((c = getc(file3)) != EOF)
    {

        genoma2[i] = c;
        i++;
    }

    //fecha arquivo
    fclose(file3);

    //-----------------------------
    //genoma 4
    FILE *file4;

    //abre arquivo para leitura
    file4 = fopen("genomas/MN908947.txt", "r");

    //carrega o conteudo do arquivo no vetor genoma1
    i = 0;
    while ((c = getc(file4)) != EOF)
    {

        genoma3[i] = c;
        i++;
    }

    //fecha arquivo
    fclose(file4);

    //-----------------------------
    //genoma 5
    FILE *file5;

    //abre arquivo para leitura
    file5 = fopen("genomas/MN996532.txt", "r");

    //carrega o conteudo do arquivo no vetor genoma1
    i = 0;
    while ((c = getc(file5)) != EOF)
    {

        genoma4[i] = c;
        i++;
    }

    //fecha arquivo
    fclose(file5);

    //-----------------------------
    //genoma 6
    FILE *file6;

    //abre arquivo para leitura
    file6 = fopen("genomas/USA-AZ1-2020.txt", "r");

    //carrega o conteudo do arquivo no vetor genoma1
    i = 0;
    while ((c = getc(file6)) != EOF)
    {

        genoma5[i] = c;
        i++;
    }

    //fecha arquivo
    fclose(file6);

    //-----------------------------
    //genoma 7
    FILE *file7;

    //abre arquivo para leitura
    file7 = fopen("genomas/USA-CA1-2020.txt", "r");

    //carrega o conteudo do arquivo no vetor genoma1
    i = 0;
    while ((c = getc(file7)) != EOF)
    {

        genoma6[i] = c;
        i++;
    }

    //fecha arquivo
    fclose(file7);

    //-----------------------------
    //genoma 8
    FILE *file8;

    //abre arquivo para leitura
    file8 = fopen("genomas/USA-IL1-2020.txt", "r");

    //carrega o conteudo do arquivo no vetor genoma1
    i = 0;
    while ((c = getc(file8)) != EOF)
    {

        genoma7[i] = c;
        i++;
    }

    //fecha arquivo
    fclose(file8);

    //-----------------------------
    //genoma 9
    FILE *file9;

    //abre arquivo para leitura
    file9 = fopen("genomas/USA-TX1-2020.txt", "r");

    //carrega o conteudo do arquivo no vetor genoma1
    i = 0;
    while ((c = getc(file9)) != EOF)
    {

        genoma8[i] = c;
        i++;
    }

    //fecha arquivo
    fclose(file9);

    //-----------------------------
    //genoma 9
    FILE *file10;

    //abre arquivo para leitura
    file10 = fopen("genomas/WHUHAN-WH04-2020.txt", "r");

    //carrega o conteudo do arquivo no vetor genoma1
    i = 0;
    while ((c = getc(file9)) != EOF)
    {

        genoma9[i] = c;
        i++;
    }

    //fecha arquivo
    fclose(file10);
}

int main(int argc, char *argv[0])
{

    tempo1();
    //cria var do tipo ponteiro
    int *num_iguais;
    int *num_dif;

    //aloca memória na ram e cpu
    cudaMallocManaged(&num_iguais, 4);
    cudaMallocManaged(&num_dif, 4);

    //inicializa os ponteiros
    *num_iguais = 0;
    *num_dif = 0;

    //inicializa os vetores e a matriz de resultado
    inicializa_vetor();
    inicializa_matriz();

    //carrega os genomas
    carrega_genoma();

    //mostra os genomas
    //mostra_genomas();

    //array de array dos genomas
    char *array_gen[10] = {genoma0, genoma1, genoma2, genoma3, genoma4, genoma5, genoma6, genoma7, genoma8, genoma9};

    //executa a função de comparação
    for (int k = 0; k < 9; k++)
    {
        for (int j = k + 1; j <= 9; j++)
        {
            //printf("\n");
            //printf("Comparação executada na thread  %d \n", omp_get_thread_num());
            compara_genoma<<<700, 44>>>(array_gen[k], array_gen[j], k, j, num_iguais, num_dif);
            cudaDeviceSynchronize();
            *num_iguais = 0;
            *num_dif=0;
        }
    }

    mostra_resultado();

    tempo2();
    printf("\n O tempo total de execução foi de");
    tempoFinal("mili segundos", argv[0], MSGLOG);
}