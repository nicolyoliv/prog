#include <stdio.h>

int global = 0;

void incrementa(){
    int local = 0;
    static int global_static = 0;
    printf("global: %d -- local: %d -- gobal_static: %d\n", global, local, global_static);
    global++;
    local++;
    global_static++;
}

int main(){
    int i;
    for(i=0; i<5; i++){
        printf("i: %d --", i);
        incrementa();
    }
    return 0;
}