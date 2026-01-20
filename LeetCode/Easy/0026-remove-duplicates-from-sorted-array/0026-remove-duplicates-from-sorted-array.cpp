class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int index = 0;
        for(int j =1; j<arr.size(); j++){
            if(arr[j] != arr[index])
            {
                arr[index+1] = arr[j];
                index++;
            }
        }
        return index+1;
    }
};