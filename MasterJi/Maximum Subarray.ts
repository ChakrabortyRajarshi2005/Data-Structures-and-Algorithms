Maximum Subarray
Accepted
MEDIUM

Tags

Companies

Hints
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:
Input: nums = [1]
Output: 1
Explanation: The array contains only one element, which is the max subarray.
Example 3:
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The entire array is the largest subarray with sum = 23.
Note:

A subarray is a contiguous part of an array. In the above problem, you're required to find the subarray which has the maximum sum.

It's possible for the input array to have negative numbers, and the optimal subarray might start or end at a negative number to maximize the overall sum.

Constraints
1 <= nums.length <= 10^5

-10^4 <= nums[i] <= 10^4class Solution {
  findMaxSubarraySum(nums: number[]): number {
    if (nums.length === 0) return 0;

    let maxSum = nums[0];
    let currentSum = 0;

    for (const n of nums) {
      if (currentSum < 0) {
        currentSum = 0;
      }

      currentSum += n;
      maxSum = Math.max(maxSum, currentSum);
    }

    return maxSum;
  }
}
