#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

void quickSort(int *ar, int size)
{
    if(size > 1){
        int temp, pivot = ar[0], ub = size-1;

    for(int i = size-1; i >= 0; --i){
        if(ar[i] >= pivot){
            temp = ar[i];
            int j = i;
            while(j < ub){//Variation of Insertion Sorting
                ar[j] = ar[j+1];
                ++j;
                }
            ar[ub--] = temp;
        }
    }

    ++ub;

    quickSort(ar, ub);

    quickSort(ar+ub+1, size-ub-1);

//Output

for(int i = 0; i < size; ++i){

printf("%d ", ar[i]);

}

printf("\n");

}}





int main(void)

{

int N;

scanf("%d", &N);

int ar[N];

for(int i = 0; i < N; i++){

scanf("%d", &ar[i]);

}

quickSort(ar, N);

return 0;

}