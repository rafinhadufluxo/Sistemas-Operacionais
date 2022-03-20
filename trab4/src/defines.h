#define N_INTERACOES 10
#define MAX_THREADS 9
#define TAMANHO_VETOR 10

double vetor_velho[TAMANHO_VETOR];
double vetor_novo[TAMANHO_VETOR];

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
sem_t semaforo[MAX_THREADS];
pthread_t ThreadID[MAX_THREADS];

static pthread_barrier_t barreira1;
static pthread_barrier_t barreira2;