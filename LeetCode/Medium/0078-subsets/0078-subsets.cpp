class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        int total = 1 << n;   //1 << n  =  2^n

        for(int mask = 0; mask < total; mask++){
            vector<int> subset;

            for(int i = 0; i < n; i++){
                if(mask & (1 << i)){
                    subset.push_back(nums[i]);
                }
            }

            ans.push_back(subset);
        }

        return ans;
    }
};