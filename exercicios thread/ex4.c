// Faça um programa para somar os elementos de um vetor usando threads.
// Crie 4 threads.
#include <stdio.h>
#include <pthread.h>

int valor = 0;
pthread_mutex_t lock;

void *somar(void *arg)
{
    int valor_1 = *(int *)arg;
    pthread_mutex_lock(&lock);
    printf("Adicionando valor: %d \n", valor_1);
    valor += valor_1;
    printf("Valor: %d \n", valor);
    pthread_mutex_unlock(&lock);

    return NULL;
}
int main()
{
    int array[4] = {10, 20, 30, 40};
    pthread_t id[4];

    pthread_mutex_init(&lock, NULL);
    for (int i = 0; i < 4; i++)
    {
        pthread_create(&id[i], NULL, somar, &array[i]);
    }

    for (int i = 0; i < 4; i++)
    {
        pthread_join(id[i], NULL);
    }
    printf("Soma do array: %d \n", valor);

    pthread_mutex_destroy(&lock);
    return 0;
}