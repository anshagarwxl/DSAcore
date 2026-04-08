class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int n = nums.length;
        int sum=0;
        int i=0;
        int j=0;
        int minL = n+1;
        while(j<n){
            sum+=nums[j];
            while(sum>=target){
                minL = Math.min(minL, j-i+1);
                sum -=nums[i];
                i++;
            }
            j++;
        }
        return minL == n+1?0:minL;
    }
}