//keeping smaller digits at start
//getting rid of 'k' larger digits 
class Solution {
    public String removeKdigits(String num, int k) {
         Stack<Character> st = new Stack<>();
         for(int i =0;i<num.length();i++){
            char digit = num.charAt(i);

            //pop the last digit, if it is greater than current digit and k should be > 0 
            while(!st.isEmpty() && k>0 && st.peek() > digit){
                st.pop();
                k--;
            }
            st.push(digit);
         }
         //check if more digits can be removed, if k>0
         while(k>0){
            st.pop();
            k--;
         }
         //stack is empty : edge case
         if(st.isEmpty()) return "0";

         StringBuilder res = new StringBuilder();
         while(!st.isEmpty()){
            res.append(st.pop());
         }

        res.reverse();
         //removing the leading zeroes
         while(res.length()>0 && res.charAt(0)=='0'){
            res.deleteCharAt(0);
         }

         //check for empty result
         if(res.length() ==0) return "0";

         return res.toString();
    }
}