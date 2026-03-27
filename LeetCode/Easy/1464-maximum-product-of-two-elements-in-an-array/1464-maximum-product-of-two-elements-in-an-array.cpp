class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int largest = 0;
        int second_largest = 0;
        for(int &num: nums){
            if(num>largest){
                second_largest = largest;
                largest = num;
            }
            else{
                second_largest = max(num,second_largest);
            }
        }
        return (largest-1)*(second_largest-1);
    }
};