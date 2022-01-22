#define N 5
#define PENSAR 0
#define FOME 1
#define COMER 2
#define ESQUERDA (nfilosofo+4)%N //agarrar garfo da esquerda
#define DIREITA (nfilosofo+1)%N  //agarrar garfo da direita

void agarraGarfo(int);
void deixaGarfo(int);
void testar(int);

sem_t mutex;
sem_t S[N]; //inicializacao 
int estado[N];
int nfilosofo[N]={0,1,2,3,4};
