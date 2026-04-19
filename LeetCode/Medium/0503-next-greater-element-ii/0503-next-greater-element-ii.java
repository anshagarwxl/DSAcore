class Solution {
    public int[] nextGreaterElements(int[] nums) {
        //APPROACH 1: 
        //virtually double the array
        // and then use %(modulo) to access the virtual index

        //approach 2:
        int n = nums.length;
        int[] ans = new int[n];
        Stack <Integer> st = new Stack<>();

        //traverse the array twice from back to simulate circular array
        for(int i=2*n-1;i>=0;i--){
            int ind = i%n;
            int currEle = nums[ind];

        //pop elements from stack that are less than or equal to current
        while(!st.isEmpty() && st.peek() <= currEle){
            st.pop();
        }
        if(i<n){
            if(st.isEmpty()){
                ans[ind] = -1;
            } else{
                ans[ind] = st.peek();
            }
        }
        st.push(currEle);
        }    
        return ans;
    }
}