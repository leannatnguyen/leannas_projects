#include <stdio.h>

int main(){
    int *values = malloc(40);
    // say we want a bigger array now
    // --> use realloc
    values = realloc(values, 20000*sizeof(int));
    return 0;
}