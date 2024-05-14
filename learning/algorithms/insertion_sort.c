#include <stdio.h>
#include <stdbool.h>

/*
sort array/list
-start off with left hand list = sorted
-right hand list = unsorted

--> continuously inserting the element into the correct position

*/

void insertion_sort(int a[], int length);

int main()
{
    int a[] = {8,4,9,5,7,6,3,2};

    int length = 8;

    for (int i = 0; i < 8; i++){
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}

void insertion_sort(int a[], int length){
    //two loops
    //outer loop looks at each element in the array one at a time
    //inner loop focuses at shifting element over to right position in left hand portion

    for (int i = 1; i < length; i++){ // starting at 1 because we assume that one is "sorted"
        int key = a[i]; //keep track of element we're currently looking at
        int j = i-1; //index to the left of what we're currently looking at (left side of array)

        //inner loop is doing shifting on the left side of the array
        //so long as we're not at the start and the element is not greater than the key
        while (j >= 0 && a[j] > key){
            //want to continously shift over the elements
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = key; // this is where we insert because we're no longer greater than the key
    }
}