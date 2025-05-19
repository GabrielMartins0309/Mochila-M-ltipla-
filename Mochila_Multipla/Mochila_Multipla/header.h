#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#define MAX_MOC 50
#define MAX_OBJ 500

//Soluções 


typedef struct tSolucaoBIN { //Solução Binária 
	int fo;
	int vet_peso_moc[MAX_MOC];
	int vet_obj_dup[MAX_OBJ];
	int mat_sol[MAX_MOC][MAX_OBJ];
}SolucaoBIN;

typedef struct tSolucao {
	int fo;
	int vet_peso_moc[MAX_MOC];
	int vet_sol[MAX_OBJ];
}Solucao;

//Variáveis 
int num_moc;
int num_obj;
int vet_val_obj[MAX_OBJ];
int vet_pes_obj[MAX_OBJ];
int vet_cap_moc[MAX_MOC];

// funções
void ler_dados(const char* arq);
void impressao_dados(const char* arq);
void criar_solucao(SolucaoBIN& s);
void calculo_fo_solucaoBIN(SolucaoBIN& s);
void impressao_solucaoBIN(SolucaoBIN& s);
void criar_solucao(Solucao& s);
void calculo_fo_solucao(Solucao& s);
void impressao_solucao(Solucao& s);

#endif // !HEADER_H_INCLUDED

