class Solution {
public:
    int findMax(vector<int>& v){
        int m = INT_MIN;
        for(int x : v) m = max(m, x);
        return m;
    }
    
    long long totalHours(vector<int>& v, int k){
        long long t = 0;
        for(int x : v){
            t += (x + k - 1) / k;
        }
        return t;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = findMax(piles);
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            if(totalHours(piles, mid) <= h)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};
