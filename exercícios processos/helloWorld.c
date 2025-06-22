#include <stdio.h>
#include <unistd.h>

int main(){

    int num = fork();
    if(num != 0){
        printf("Hello World\n");
    }
    
    printf("Hello World\n");

    while(1);
}
