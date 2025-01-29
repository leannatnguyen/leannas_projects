#include <stdio.h>
#include <stdbool.h>

int main(){
    int a[] = {5,9,7,6,4,0,2,3,8,1};
    int length = 10;

    for (int i = 0; i < length -1; i++){
        //right hand porition of the array is always going to be unsorted
        // --> one element left = sorted by default
        
        //inner loop is to find minimum index of the unsorted portion of the array
            //start with assumption that the index u start with is the smallest element
        int min_pos = i;

        //starting at i+1 since we're starting at the assumed min position
        for (int j = i + 1; j < length; j++){
            if (a[min_pos] > a[j]){
                min_pos = j;
            }
        }
        if (min_pos != i){
            int temp = a[i];
            a[i] = a[min_pos];
            a[min_pos] = temp;
        }
    }   
    
    for (int i = 0; i < length; i++){
        printf("a[%d] = %d\n", i, a[i]);
    }
    return 0;
}