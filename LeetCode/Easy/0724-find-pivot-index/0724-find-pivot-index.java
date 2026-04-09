class Solution {
    public int pivotIndex(int[] nums) {
        int n = nums.length;
        int sum = 0;
        for(int x=0; x<n; x++){
            sum+=nums[x];
        }
        int cumulative_sum = 0;
        for(int i =0; i<n;i++){
            int left_sum = cumulative_sum;
            int right_sum = sum - left_sum - nums[i];

            if(left_sum == right_sum)
            return i;

            cumulative_sum+=nums[i];
        }
        return -1;
    }
}