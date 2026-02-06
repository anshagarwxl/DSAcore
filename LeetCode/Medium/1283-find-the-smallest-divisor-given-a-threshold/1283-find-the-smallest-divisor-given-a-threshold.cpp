class Solution {
public:
    int sumByD(vector<int> &arr, int div){
        int sum=0;
        int n = arr.size();
        for(int i =0;i<arr.size();i++){
            sum = sum+ ceil((double)(arr[i])/(double)(div)); //ceil returns the higher value, if 1.25 -> 2 
        }
        return sum;
    }
    int smallestDivisor(vector<int>& arr, int limit) {
        // if(arr.size()>limit) return -1;
        int low =1;
        int high = *max_element(arr.begin(),arr.end()); // c++ stl func to give max element in a range
        while(low<=high){
            int mid = (low+high)/2;
            if(sumByD(arr,mid)<=limit){
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};