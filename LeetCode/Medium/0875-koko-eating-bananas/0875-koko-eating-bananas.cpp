class Solution {
public:
  long long totalHours(vector<int>&v, int k){
    long long t =0;
    for(int i=0;i<v.size();i++){
        t+=ceil((double)v[i]/k); // (double) is a must, to avoid integer division, then ceil is of no use
    }                            // or instead of ceil use: t+=ceil(v[i]+k-1)/k;
    return t;
  }
  int minEatingSpeed(vector<int>&piles, int h){
    int low =1; 
    int high = *max_element(piles.begin(),piles.end());//STL function to find largest value
    while(low<=high){
        int mid = (low+high)/2;
        if(totalHours(piles,mid)<=h){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
  }
};
