 /* given nums = [1, 2, 4, 6, 8, 9, 14, 15] and target = 13, return true because 4 + 9 = 13.
 */
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

bool target_sum_found(int *nums, int nums_size, int target){
    int low = 0;
    int high = nums_size - 1;
    while (low < high) {
        int sum = nums[low] + nums[high];
        if (sum > target) {
            high--;
        } else if (sum < target) {
            low++;
        }
        else {
            return true;
        }
    }
    return false;
}
/* Given two sorted integer arrays arr1 and arr2, return a new array that combines both of them and is also sorted. */
int* sorted_combined(int *arr1, int *arr2, int l1, int l2) {
    int *return_array = (int*)malloc(sizeof(int)*(l1 + l2));

    int i1 = 0;
    int i2 = 0;

    int index = 0;

    while (i1 < l1 && i2 < l2) {
        if (arr1[i1] < arr2[i2]){
            return_array[index] = arr1[i1];
            i1++;
            index++;
        } else {
            return_array[index] = arr2[i2];
            i2++;
            index++;
        }
    }
    while (i1 < l1){
        return_array[index++] = arr1[i1++];
    }
    while (i2 < l2) {
        return_array[index++] = arr2[i2++];
    }

    return return_array;
}
/*Given an array of positive integers nums and an integer k, find the length of the 
longest subarray whose sum is less than or equal to k.
*/
int longest_subarray(int *nums, int numsSize, int k) {
    int curr = 0;
    int left = 0;
    int length = 0;
    for (int right = 0; right < numsSize; right++) {
        curr += nums[right];
        while (curr > k) {
            curr -= nums[left];
            left++;
        }
        if ((right - left + 1) > length) {
            length = right - left + 1;
        }
    }
    return length;
}

/* You are given a binary string s (a string containing only "0" and "1"). 
You may choose up to one "0" and flip it to a "1". What is the length of the 
longest substring achievable that contains only "1"?*/

int findLength(char *s) {
    int l = strlen(s);
    int curr = 0;
    int left = 0;
    int length = 0;
    for (int right = 0; right < l; right++){
        if (s[right] == '0'){
            curr++;
        }
        while (curr > 1){
            if (s[left] == '0') {
                curr--;
            }
            left++;
        }
        if (right - left + 1 > length) {
            length = right - left + 1;
        }
    }
    return length;
}

/* Example 4: Given an integer array nums and an integer k, find 
the sum of the subarray with the largest sum whose length is k.*/

int largest_sum(int *nums, int numsSize, int k) {
    int curr = 0;
    int ans = 0;
    for (int i = 0; i < k; i++){
        curr += nums[i];
    }
    ans = curr;
    for (int i = k; i < numsSize; i++){
        curr += nums[i];
        curr -= nums[i - k];
        if (curr > ans){
            ans = curr;
        }
    }
    return ans;

}

/* Example 1: Given an integer array nums, an array queries 
where queries[i] = [x, y] and an integer limit, return a boolean 
array that represents the answer to each query. A query is 
true if the sum of the subarray from x to y is less than limit, 
or false otherwise */

bool* answerQueries(int *nums, int numsSize, int **queries, int queriesSize, int limit) {
    bool *ans = (bool*)malloc(sizeof(bool) * queriesSize);

    int *prefix = (int*)malloc(sizeof(int) * numsSize);

    prefix[0] = nums[0];
    for (int i = 1; i < numsSize; i++){
        prefix[i] = prefix[i-1] + nums[i];
    }
    for (int i = 0; i < queriesSize; i++){
        int x = queries[i][0];
        int y = queries[i][1];
        int sum = prefix[y] - prefix[x] + nums[x];
        ans[i] = sum < limit;
    }
    return ans;
}