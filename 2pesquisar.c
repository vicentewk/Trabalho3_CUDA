#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <omp.h>

#define TAM 30690
#define L 10
#define C 10
int carrega_genoma();
int mostra_genomas();
int compara_genoma(char genomaa[TAM], char genomab[TAM], int w, int z);
int compara_sequencia(char genomaa[TAM], char genomab[TAM], int w, int z);
void inicializa_vetor();
void inicializa_matriz();
void mostra_resultado();
int m1[C][L];
double wtime_start;
double wtime_end;
double wtime;
int igual, dif;
char genoma0[TAM];
char genoma1[TAM];
char genoma2[TAM];
char genoma3[TAM];
char genoma4[TAM];
char genoma5[TAM];
char genoma6[TAM];
char genoma7[TAM];
char genoma8[TAM];
char genoma9[TAM];
int count = 0;

int maior_sequencia = 0;
int ms_g1, ms_g2;
int t = 0;
void main(int argc, char *argv[])
{
    omp_set_num_threads(4);
   // printf("Digite o número de threads que deseja utilizar: ");
    //scanf("%d", &t);
  //omp_set_num_threads(t);
    wtime_start = omp_get_wtime();
    int i, j;

#pragma omp parallel
#pragma omp single
    printf("Foram criadas %d threads omp\n", omp_get_num_threads());
#pragma omp parallel
    printf("Thread %d criada \n", omp_get_thread_num());

#pragma omp single
    inicializa_vetor();
    inicializa_matriz;
    carrega_genoma();
    mostra_genomas();

    char *array_gen[10] = {genoma0, genoma1, genoma2, genoma3, genoma4, genoma5, genoma6, genoma7, genoma8, genoma9};

    #pragma omp parallel for collapse(1) private(i, j) schedule(dynamic, 1)
    for (i = 0; i < 9; i++)
        for (j = i + 1; j <= 9; j++)
        {
            //printf("\n");
            //printf("Comparação executada na thread  %d \n", omp_get_thread_num());
            compara_genoma(array_gen[i], array_gen[j], i, j);
            compara_sequencia(array_gen[i], array_gen[j], i, j);
        }

#pragma omp single
    mostra_resultado();
    //printf("\n");
    printf("A maior sequencia  entre os genomas tem: %d caracteres e está presente na comparação entre os genomas %d e %d.", maior_sequencia, ms_g1, ms_g2);

    wtime_end = omp_get_wtime();
    wtime = wtime_end - wtime_start;
    printf("\n \n O tempo total da execução foi: %f  \n \n", wtime);
}
//funcao carrega genomas
//===============================================================
int carrega_genoma()
{

    int i = 0;
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

//funcao compara
//===============================================================
int compara_genoma(char genomaa[TAM], char genomab[TAM], int w, int z)
{

    int i = 0,

        igual = 0;
    dif = 0;

    for (i = 0; i < TAM; i++)
    {
        if (genomaa[i] == '0' && genomab[i] == '0')
        {
            // break;
        }
        else
        {

            if (genomaa[i] == genomab[i])
            { //compara os dois nucleotideos

                igual++;
            }
            else
            {

                dif++;
            }
        }
    }
    count++;

    m1[z][w] = igual;
    //printf("\n \n");
    // printf(" Comparação e sequencia do genoma %d e do genoma %d ", w, z);
    // printf("\n Comparação número: %d ", count);
    //exibe o resultado
    // printf("\n\n | Iguais %-18d \n | Diferentes %-18d ", igual, dif);
    // printf("\n\n");
    //printf("_______________________________________________________________________________");
}

//mostra os genomas
//==============================
int mostra_genomas()
{
    int i = 0;

    for (i = 0; i < TAM; i++)
    {

        printf("\n | %5d  | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | ", i,
               genoma0[i], genoma1[i], genoma2[i], genoma3[i], genoma4[i], genoma5[i], genoma6[i],
               genoma7[i], genoma8[i], genoma9[i]);
    }
}

//funcao compara sequencia
//===============================================================
int compara_sequencia(char genomaa[TAM], char genomab[TAM], int w, int z)
{

    int i = 0,
        j = 0,
        igual = 0,
        qtde = 0;

    for (i = 0, j = 0; i < TAM; i++, j++)
    {
        if (genomaa[i] == '0' && genomab[j] == '0')
        {
            break;
        }
        else
        {
            if (genomaa[i] == genomab[j])
            {
                igual++;
            }
            else
            {

                if (igual > qtde)
                {

                    qtde = igual;
                    if (qtde > maior_sequencia)
                    {
                        maior_sequencia = qtde;
                        ms_g1 = w;
                        ms_g2 = z;
                    }

                    igual = 0;
                }
            }
        }
    }
    //printf("\n\n");
}

void inicializa_vetor()
{
    for (int i = 0; i <= TAM; i++)
    {
        genoma0[i] = '0';
        genoma1[i] = '0';
        genoma2[i] = '0';
        genoma3[i] = '0';
        genoma4[i] = '0';
        genoma5[i] = '0';
        genoma6[i] = '0';
        genoma7[i] = '0';
        genoma8[i] = '0';
        genoma9[i] = '0';
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
