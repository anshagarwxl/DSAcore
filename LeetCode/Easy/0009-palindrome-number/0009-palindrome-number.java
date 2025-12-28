class Solution {
    public boolean isPalindrome(int N) {
        int revNum = 0;
        int duplicate = N;

        if(N<0){
            return false;
        }

        while(N!=0){
            int lastDigit = N%10;
            revNum = (revNum * 10 ) + lastDigit;
            N=N/10;
        }
        if (duplicate == revNum){
            return true;
        }
        else 
            return false;
        }
    }
