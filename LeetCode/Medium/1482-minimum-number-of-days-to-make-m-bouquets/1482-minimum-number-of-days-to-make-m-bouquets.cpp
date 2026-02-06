class Solution {
public:
    bool possible(vector <int> &arr, int day, int m, int k){
        int cnt =0;
        int noOfB =0;
        for(int i =0; i<arr.size();i++){
            if(arr[i]<=day){ //check if flower is bloomed
                cnt++;
            }
            else{
                 noOfB += cnt/k;
                cnt =0;
            }
        }
        noOfB += (cnt/k);
        return noOfB>=m;
    }
    int minDays(vector<int>& arr, int m, int k) {
        long long val = m * 1LL * k *1LL; //converted to long long, to avoid integer overflow
        if(val>arr.size())
        return -1;

        int mini = INT_MAX; //starts at the largest value, to be replaced by the smallest value in the array.
        int maxi = INT_MIN;

        for(int i=0; i<arr.size();i++){
            mini = min(arr[i], mini);
            maxi = max(arr[i],maxi);
        }
        int low = mini;
        int high = maxi;
        while(low<=high){
            int mid = (low+high)/2;
            if (possible( arr,  mid, m, k)){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
         return low;
    }
};