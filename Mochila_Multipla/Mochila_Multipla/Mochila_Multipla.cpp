// Mochila_Multipla.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "header.h"

int main()
{
    ler_dados("pmm1.txt");
    escrever_dados(" ");
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
void escrever_dados(const char* arq) {
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
