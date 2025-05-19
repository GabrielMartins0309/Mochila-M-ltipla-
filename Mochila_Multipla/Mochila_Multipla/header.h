#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#define MAX_MOC 50
#define MAX_OBJ 500

//Variáveis 
int num_moc;
int num_obj;
int vet_val_obj[MAX_OBJ];
int vet_pes_obj[MAX_OBJ];
int vet_cap_moc[MAX_MOC];

// funções
void ler_dados(const char* arq);
void escrever_dados(const char* arq);



#endif // !HEADER_H_INCLUDED

