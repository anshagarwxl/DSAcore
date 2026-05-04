class Solution {
    public long subArrayRanges(int[] nums) {
        int n = nums.length;
        return sumMax(nums, n) - sumMin(nums,n);
    }
    private long sumMin(int [] nums, int n){
        long res=0;
        Stack<Integer> st = new Stack<>();

        for(int i =0;i<=n;i++){
            while(!st.isEmpty() && (i==n|| nums[st.peek()]>= nums[i])){
                int mid = st.pop();
                int left = st.isEmpty() ? -1 : st.peek();
                int right = i;
                res+=(long) nums[mid] * (mid-left) * (right-mid);
            }
            st.push(i);
        }
        return res;
    }
    private long sumMax(int[] nums, int n){
        long res = 0;
        Stack<Integer> st = new Stack<>();

        for(int i=0;i<=n;i++){
            while(!st.isEmpty() && (i==n || nums[st.peek()] <= nums[i])){
                int mid = st.pop();
                int left = st.isEmpty() ? -1 : st.peek();
                int right = i;
                res += (long) nums[mid] * (mid-left) * (right-mid);
            }
            st.push(i);
        }
        return res;
    }
}