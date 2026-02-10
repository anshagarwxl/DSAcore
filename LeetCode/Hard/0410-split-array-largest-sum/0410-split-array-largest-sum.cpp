class Solution {
public:
    int countSubarrays(vector<int> &nums, int maxSum){
        int subArrays=1;
        long long currentSum =0;

        for(int i =0; i<nums.size();i++){
            if(currentSum + nums[i] <= maxSum){
                currentSum += nums[i];
            } else {
                subArrays++;
                currentSum = nums[i];
            }
        }
        return subArrays;
    }
       int splitArray(vector<int>& nums, int k) {
         long long low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL);

        while (low <= high) {
            long long mid = (low + high) / 2;

            if (countSubarrays(nums, mid) > k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return (int)low;
    }
};