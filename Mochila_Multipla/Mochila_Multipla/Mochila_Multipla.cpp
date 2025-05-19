// Mochila_Multipla.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "header.h"

#define MAX(X,Y)((X > Y) ? (X) : (Y))
#define MIN(X,Y)((X < Y) ? (X) : (Y))

int PESO_CAP = 100;
int PESO_DUP = 1000;

int main()
{
    ler_dados("pmm1.txt");
    //impressao_dados(" ");
    srand(time(NULL));
    //Solução Binária 
    SolucaoBIN sol_bin;
    criar_solucao(sol_bin);
    calculo_fo_solucaoBIN(sol_bin);
    impressao_solucaoBIN(sol_bin);

    Solucao sol;
    criar_solucao(sol);
    calculo_fo_solucao(sol);
    impressao_solucao(sol);
    return 0;
}

//Solucao vetor

void impressao_solucao(Solucao& s) {
    printf("FO: %d\n", s.fo);
    printf("Peso das mochilas: ");
    for (int i = 0; i < num_moc; i++)
        printf("%d ", s.vet_peso_moc[i]);
    printf("\nVetor de Solucao: \n");
    for (int i = 0; i < num_obj; i++)
        printf("%d ", s.vet_sol[i]);
}

void calculo_fo_solucao(Solucao& s) {
    s.fo = 0;
    memset(&s.vet_peso_moc, 0, sizeof(s.vet_peso_moc));
    for (int i = 0; i < num_obj; i++) {
        if (s.vet_sol[i] != -1) {
            s.fo += vet_val_obj[i];
            s.vet_peso_moc[s.vet_sol[i]] += vet_pes_obj[i];
        }
    }

    for (int i = 0; i < num_obj; i++)
        s.fo -= PESO_CAP * MAX(0, (s.vet_peso_moc[i] - vet_cap_moc[i]));
}

void criar_solucao(Solucao& s) {
    for (int i = 0; i < num_obj; i++)
        s.vet_sol[i] = rand() % (num_moc + 1) - 1;
}


//Solucao Matriz Binária 
void impressao_solucaoBIN(SolucaoBIN& s) {
    printf("Função objetiva: %d\n", s.fo);
    printf("Objetos duplicados: ");
    for (int i = 0; i < num_obj; i++)
        printf("%d ", s.vet_obj_dup[i]);
    printf("\nPeso das mochilas: ");
    for (int i = 0; i < num_moc; i++)
        printf("%d ", s.vet_peso_moc[i]);
    printf("\nMatriz de solucão:\n");
    for (int i = 0; i < num_moc; i++) {
        for (int j = 0; j < num_obj; j++) {
            printf("%d ", s.mat_sol[i][j]);
        }
        printf("\n");
    }
}

void calculo_fo_solucaoBIN(SolucaoBIN& s) {
    s.fo = 0;
    memset(&s.vet_obj_dup, 0, sizeof(s.vet_obj_dup));
    memset(&s.vet_peso_moc, 0, sizeof(s.vet_peso_moc));
    for (int i = 0; i < num_moc; i++)
    {
        for (int j = 0; j < num_obj; j++) {
            s.fo += vet_val_obj[j] * s.mat_sol[i][j];
            s.vet_peso_moc[i] += vet_pes_obj[j] * s.mat_sol[i][j];
            s.vet_obj_dup[j] += s.mat_sol[i][j];
        }
    }
    for (int i = 0; i < num_moc; i++)
    {
        s.fo -= PESO_CAP * MAX(0, (s.vet_peso_moc[i] - vet_cap_moc[i]));
    }
    for (int j = 0; j < num_obj; j++) {
        s.fo -= PESO_DUP * MAX(0, (s.vet_obj_dup[j] - 1));
    }
}

void criar_solucao(SolucaoBIN& s) {
    for(int i = 0; i < num_moc; i++)
        for (int j = 0; j < num_obj; j++) {
            s.mat_sol[i][j] = rand() % 2; 
        }
}

void ler_dados(const char* arq) {
    FILE* f = fopen(arq, "r");
    fscanf(f, "%d %d", &num_obj, &num_moc);
    for (int i = 0; i < num_obj; i++)
        fscanf(f, "%d", &vet_val_obj[i]);
    for (int i = 0; i < num_obj; i++)
        fscanf(f, "%d", &vet_pes_obj[i]);
    for (int i = 0; i < num_moc; i++)
        fscanf(f, "%d", &vet_cap_moc[i]);
    fclose(f);
}
void impressao_dados(const char* arq) {
    FILE* f;
    if (!strcmp(arq, " "))
        f = stdout;
    else
        f = fopen(arq, "w");
    fprintf(f, "%d %d", num_obj, num_moc);
    fprintf(f, "\n");
    for (int i = 0; i < num_obj; i++)
        fprintf(f, "%d ", vet_val_obj[i]);
    fprintf(f, "\n");
    for (int i = 0; i < num_obj; i++)
        fprintf(f, "%d ", vet_pes_obj[i]);
    fprintf(f, "\n");
    for (int i = 0; i < num_moc; i++)
        fprintf(f, "%d ", vet_cap_moc[i]);
        
    if (strcmp(arq, " "))
        fclose(f);
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
