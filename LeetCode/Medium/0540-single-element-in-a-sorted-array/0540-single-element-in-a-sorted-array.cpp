class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        //trim down the search space from (1->n-2)
        //adding extra checks for case where n=1, 0th element, n-1 element
        int n = arr.size();
        if(n==1) return arr[0];
        if(arr[0]!= arr[1]) return arr[0];
        if(arr[n-1]!=arr[n-2]) return arr[n-1];
        int low = 0;
        int high = n-2;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid] != arr[mid+1] && arr[mid] != arr[mid-1]){
                return arr[mid];
            }
            //left sort half
            if((mid%2==1 && arr[mid] == arr[mid-1]) || (mid%2==0 && arr[mid] == arr[mid+1])){
                low= mid+1;
            }
            //right sort half
            else{
                high = mid-1;
            }
        }
        return -1;
    }
};