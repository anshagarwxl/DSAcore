class Solution {
public:
    string reverseWords(string s) {
      int n = s.length();

      for(int i =0; i<n;i++){
        if(s[i] != ' ' && (i ==0 || s[i-1]== ' ')){
            int start = i;
            int j =i;
            while(j<n && s[j]!= ' ')
            j++;

            int end = j-1;

            while(start<end){
                swap(s[start],s[end]);
                start++;
                end--;
            }
            i=j-1;
        }
      }
      return s;
    }
};