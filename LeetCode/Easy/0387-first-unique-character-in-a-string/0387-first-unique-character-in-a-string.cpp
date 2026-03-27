class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26] = {0};

        int n = s.length();
        //inputting each char of string into array
        for(int i =0; i<n;i++){
            char ch = s[i];
            arr[ch-'a']++;
        }
        //checking in array which is first char to have value 1 in arr
        for(int i =0; i<n;i++){
            char ch = s[i];
            if(arr[ch-'a'] ==1 ){
                return i;
            }
        }
        // if none
        return -1;
    }
};