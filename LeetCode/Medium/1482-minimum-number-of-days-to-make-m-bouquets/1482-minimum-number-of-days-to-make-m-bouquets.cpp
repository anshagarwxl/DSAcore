class Solution {
public:
    bool possible(vector <int>& arr, int day, int m, int k){
        int count = 0; int noOfB=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=day){
                count++;
            }
            else{
                noOfB += (count/k);
                count=0;
            }
        }
        noOfB +=(count/k);
        return noOfB>=m;
    }
    int minDays(vector<int>&arr, int r, int b){
        long long val = r*1LL*b*1LL;
        if(val>arr.size()){
            return -1;
        }
        int mini = *min_element(arr.begin(),arr.end());
        int maxi = *max_element(arr.begin(),arr.end());
        int low =mini;
        int high =maxi;
        while(low<=high){
            int mid = (low+high)/2;
                if(possible(arr,mid,r,b)){
                    high=mid-1;
                }
                else{
                low=mid+1;
            }
        }
        return low;
    }
};