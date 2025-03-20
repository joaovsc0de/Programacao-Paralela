//Questão 4 – Implemente um programa que:
//a) Gere a árvore de processos abaixo ao ser executado.
//b) Cada processo deve imprimir o seu ID de forma separada.
#include <stdio.h>
#include <unistd.h>

int main(){
    int  id_f1, id_f2, id_f3;
    int P_pid, pid_f1, pid_f2, pid_f3;

    P_pid = getpid();
    printf("ID do Process PAI: %d\n", P_pid);
    id_f1 = fork();

    if(id_f1 == 0){
    pid_f1 = getpid();
    printf("ID de F1: %d\n", pid_f1);
    id_f2 = fork();
    }
    pid_f2 = getpid();   
    if(pid_f2 != pid_f1 && pid_f2 != P_pid){
    printf("ID de F2: %d\n", getpid());
    id_f3 = fork();
    }

    pid_f3 = getpid();
    if(pid_f3 != pid_f1 && pid_f3 != pid_f2 && pid_f3 != P_pid ){
        printf("ID de F3: %d\n", getpid());
    }

    while(1);
}

