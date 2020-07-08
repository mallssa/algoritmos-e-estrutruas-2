#ifndef H_COM112_HASH
#define H_COM112_HASH

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2;
};
typedef struct hash Hash;

Hash* criaHash(int TABLE_SIZE);
void liberaHash(Hash* ha);
int insereHash_SemColisao(Hash* ha,struct aluno al);
int buscaHash_SemColisao(Hash* ha,int matricula,struct aluno* al);
int chaveDivisao(int chave, int TABLE_SIZE);

#endif
