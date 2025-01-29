# hashing
'''
Example 3: Given an integer array nums, find all the 
unique numbers x in nums that satisfy the following: 
x + 1 is not in nums, and x - 1 is not in nums.
'''
def find_numbers(nums):
    ans = []
    nums = set(nums)

    for i in nums:
        if (i + 1) not in nums and (i - 1) not in nums:
            ans.append(i)

    return ans

'''
Ex 1: You are given a string s and an integer k. Find 
the length of the longest substring that contains at 
most k distinct characters.
'''
def find_longest_substring(s: str, k: int) -> int:
    count = 0
    left = 0
    ans = 0
    substring = {}

    for right in range(len(s)):
        substring[s[right]] += 1
    
        while len(substring) > k:
            substring[s[left]] -= 1
            if counts[s[left]] == 0:
                del counts[s[left]]
            left += 1
        ans = right - left + 1
    return ans   
                 