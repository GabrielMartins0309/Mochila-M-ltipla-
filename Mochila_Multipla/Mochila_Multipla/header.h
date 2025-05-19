#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#define MAX_MOC 50
#define MAX_OBJ 500

//Soluções 

typedef struct tSolucaoBIN {
	int fo;
	int vet_peso_moc[MAX_MOC];
	int vet_obj_dup[MAX_OBJ];
	int mat_sol[MAX_MOC][MAX_OBJ];
}SolucaoBIN;

//Variáveis 
int num_moc;
int num_obj;
int vet_val_obj[MAX_OBJ];
int vet_pes_obj[MAX_OBJ];
int vet_cap_moc[MAX_MOC];

// funções
void ler_dados(const char* arq);
void escrever_dados(const char* arq);
void criar_solucao(SolucaoBIN& s);
void calculo_fo_solucaoBIN(SolucaoBIN& s);
void escrever_solucaoBIN(SolucaoBIN& s);



#endif // !HEADER_H_INCLUDED

