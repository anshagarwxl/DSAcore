class Solution {
    //next smaller element
    private int[] findNSE(int [] arr){
        int n = arr.length;
        int [] ans = new int[n];
        Stack<Integer> st = new Stack<>();

        for(int i = n-1; i>=0; i--){
            //pop elements greater than or equal to current
            while(!st.isEmpty() && arr[st.peek()] >= arr[i]){
            st.pop();
        }
        //case when stack is empty
        ans[i] = !st.isEmpty() ? st.peek() : n;

        //push current index to stack
        st.push(i);
    }
    return ans;
}
//previous smaller element
    private int[] findPSEE(int [] arr){
        int n = arr.length;
        int [] ans = new int[n];
        Stack<Integer> st = new Stack<>();

        for(int i = 0; i<n;i++){
            //pop elements greater than current
            while(!st.isEmpty() && arr[st.peek()] > arr[i]){
                st.pop();
            }
            //if stack is empty, PSEE does not exist so set to -1
            ans [i] = !st.isEmpty() ? st.peek():-1;
            //push current index to stack
            st.push(i);
        }
        return ans;
    }
    public int sumSubarrayMins(int[] arr) {
        int n = arr.length;
        int[] nse = findNSE(arr);
        int[] psee = findPSEE(arr);

        int mod = (int)1e9 + 7;
        int sum = 0;

        for(int i=0;i<n;i++){
            //number of elements in left including current element
            int left = i-psee[i];
            //number of elements in right including current element
            int right = nse[i]-i;
            //Total subarrays where arr[i] is the minimum
            long freq = left * right * 1L;
            // frequency * value = contribution
            int val = (int)((freq * arr[i]) %mod);

        //adding contribution to the final sum
        sum = (sum+val)%mod;
        }
        return sum;
    }
}