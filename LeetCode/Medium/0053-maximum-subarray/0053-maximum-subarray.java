class Solution {
    public int maxSubArray(int[] nums) {
        int current_sum = nums[0];
        int maxSum = nums[0];
        for(int i=01;i<nums.length;i++){
            current_sum = Math.max(nums[i], current_sum + nums[i]);
            maxSum = Math.max(current_sum, maxSum);
        }
        return maxSum;
    }
}