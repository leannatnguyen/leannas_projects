#include <stdio.h>
/* how it works
-keep dividing the array into smaller and smaller subarrays
-start -> divide array down middle
-keep dividing until it's 1 element basically then keep merging the sorted arrays
    -"divide and conquer"
*/

void merge_sort(int a[], int length);
void merge_sort_recursion(int a[], int l, int r); //recursive step where we continually divide the array into smaller and smaller portions
void merge_sorted_arrays(int a[], int l, int m, int r);

int main(){

    int array[] = {9, 4, 8, 1, 7, 0, 3, 2, 5, 6};
    int length = 10;

    merge_sort(array, length);

    for (int i = 0; i < length; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}

void merge_sort(int a[], int length){
    //this function will call the recursive function
    merge_sort_recursion(a, 0, length - 1); // start at index 0 and the final index aka length - 1
}

void merge_sort_recursion(int a[], int l, int r){

    //keep going so long as left is less than right index
    if(l < r)
    {
        //this finds the middle of the array
        int m = l + (r - l)/ 2; // left + (right - left) / 2

        merge_sort_recursion(a, l, m); //left side of the array
        merge_sort_recursion(a, m + 1, r); // right side of the array

        merge_sorted_arrays(a, l, m, r);
    }
    
}

void merge_sorted_arrays(int a[], int l, int m, int r){
    //need length of each portion

    int left_length = m - l + 1; //middle - length + 1 = left
    int right_length = r - m; //right - middle = right

    //need to create 2 subarrays to represent the left and right sides of the array

    int temp_left[left_length];
    int temp_right[right_length];

    int i, j, k;


    // the left side of the main array a
    for (int i = 0; i < left_length; i++){
        temp_left[i] = a[l + i];
    }

    //the right side of the main array a
    for (int i = 0; i < right_length; i++){
        temp_right[i] = a[m + 1 + i];
    }

    //merging these sorted subarrays
    for (i = 0, j = 0, k = l; k <= r; k++){
        //k = index actual array we're sorting (into main array a)
        //starting k up until r

        //find next element in either temp left or temp right to copy into index k

        //i and j are indexes into temp left and temp right, respectively
            // we increment these only if we use what we're going to put into the main array a

        // for i: if we haven't hit the max index of the left temp array
        // for j: if we are greater or equal to the max index of the right temp array
            //these both handle the case that we reach the end of the temp arrays
        // or temp_left[i] (left array element) <= temp_right[j] (right array element) 
            //sees which array (left or right) has the smallest element of where we are in each element
        if ((i < left_length) && 
            (j >= right_length || temp_left[i] <= temp_right[j])){
            a[k] = temp_left[i]; //copy left array element in
            i++; //increment the temp left index
        }
        else {
            a[k] = temp_right[j]; //copy right array element in
            j++; //increment temp right index
        }
    }
        //other notes: if reach the end of the temp left array -> we only copy from the temp right array
        // if j >= right_length: we reached the end of temp right array --> we're just done so copy straight from temp right

}