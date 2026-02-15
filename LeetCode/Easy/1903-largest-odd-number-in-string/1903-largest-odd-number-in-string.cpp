class Solution {
public:
    string largestOddNumber(string num) {
        int start = 0;
        int end = num.length()-1;
        if((num[end]-'0')%2!=0){    //'7'-'0'= 7, checking for odd
            return num; //if last digit is odd, whole number is odd thus return the whole number itself
        }
        while(end >= 0 && (num[end]-'0') % 2 == 0){ //end shoould not go past the first number, checking if digit is even
                                //stops at the first odd digit
            end--;  // keeps on shifting end one position to the left
           }
          return num.substr(start,end+1);  
        }
};