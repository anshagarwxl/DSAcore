class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Stack<Integer> st = new Stack<>();
        Map<Integer, Integer> map = new HashMap<>();
        int n = nums2.length;
        for(int i = n-1 ; i>=0 ; i--){
            //making sure that the stack is not empty and the top element on the stack is greater than the element below it
            while(!st.isEmpty() && st.peek()<=nums2[i]){
                st.pop();
            }
            //if stack is empty, then return -1
            if(st.isEmpty()) 
                map.put(nums2[i],-1);
            //otherwise return the element on the top of the stack
            else
                map.put(nums2[i],st.peek());

            st.push(nums2[i]);
        }
        //creating answer for nums1 from the map
        int[] res = new int[nums1.length];
        for(int i =0;i<nums1.length;i++){
            res[i] = map.get(nums1[i]);
        }
        return res;
    }
}