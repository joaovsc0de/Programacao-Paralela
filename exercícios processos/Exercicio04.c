/*Questão 4 – Implemente um programa que:
a) Gere a árvore de processos abaixo ao ser executado.
b) Cada processo deve imprimir o seu ID de forma separada.

  Pai
 / \ \
F1 F2 F3*/

#include <stdio.h>
#include <unistd.h>

int main(){ // P1
    int f2, f3;
    int f1 = fork(); // F1

    if(f1 != 0){ // P1
        f2 = fork(); // F2

        if(f2 != 0){ // P1
            f3 = fork(); // F3
        }
    }

    if(f1 == 0){ // Tarefas do F1
        printf("F1 = %d\n", getpid());
    } else if (f2 == 0){ // Tarefas do F2
        printf("F2 = %d\n", getpid());
    } else if (f3 == 0){ // Tarefas do F3
        printf("F3 = %d\n", getpid());
    } else { // Tarefas do P1
        printf("P1 = %d\n", getpid());
    }

    while(1);
}