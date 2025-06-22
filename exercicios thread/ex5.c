// Fazer um programa em para contabilizar quantos elementos de um vetor
// de 1000 posições são números pares usando 4 threads. Cada thread irá
// verificar uma parte do vetor. Cada thread irá passar seu resultado à thread
// principal, que irá somá-lo ao resultado parcial gerado pela principal.

#include <stdio.h>
#include <pthread.h>

int contador = 0;
pthread_mutex_t lock;

typedef struct
{
    int *array;
    int inicio;
    int fim;
} ThreadArgs;

void popular_array(int array[1000])
{
    for (int i = 0; i < 1000; i++)
        array[i] = i + 1;
}

void *pares(void* args)
{
    ThreadArgs *dados = (ThreadArgs *)args;
    int *array = dados->array;
    int inicio = dados->inicio;
    int fim = dados->fim;

    for (int i = inicio; i < fim; i++)
    {
        if (array[i] % 2 == 0)
        {
            pthread_mutex_lock(&lock);
            contador++;
            pthread_mutex_unlock(&lock);
        }

        
    }
    return NULL;
}

int main()
{
    int array[1000];
    popular_array(array);
    pthread_t id[4];
    ThreadArgs args[4];
    pthread_mutex_init(&lock, NULL);
    for (int i = 0; i < 4; i++)
    {
        args[i].array = array;
        args[i].inicio = i * 250;
        args[i].fim = (i + 1) * 250;
        pthread_create(&id[i], NULL, pares, &args[i]);
    }
    for (int i = 0; i < 4; i++)
        pthread_join(id[i], NULL);
    printf("Número de pares no array: %d \n", contador);

    pthread_mutex_destroy(&lock);
    return 0;
}