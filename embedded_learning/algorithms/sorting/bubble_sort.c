#include <stdio.h>
#include <stdbool.h>
/*
-during bubble sort, after the first pass of the array, the last element will aways be sorted
    -after each round/pass each element from the end will be sorted
-overall it's not very efficient
*/
void bubble_sort(int a[], int length){
    for (int i = 0; i < length; i++){
        for (int j = 0; j < length - 1; j++){ //compare each element with one another
            if (a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void bubble_sort_optimitzed(int a[], int length){
    bool swapped = false;
    int i = 0;
    do {
        swapped = false;
        for (int j = 0; j < length - 1 - i; j++){ //compare each element with one another
            if (a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                swapped = true; //if swap happens then that means NOT sorted
            }
        }
        i++; //keep track of number of times we pass through array
    } while (swapped);

}

int main(void){
    int a[] = {7,1,3,9,0,2,4,5,8,6};

    // would do the same number of passes looking for swaps as there are in the array

    int length = 10;
    //outer loop controls the number of passes (how many elements there are in the array)
    
    bubble_sort_optimitzed(a, length);

    for (int i = 0; i < length; i++){
        printf("a[%d] = %d\n", i, a[i]);
    }
    return 0;
}