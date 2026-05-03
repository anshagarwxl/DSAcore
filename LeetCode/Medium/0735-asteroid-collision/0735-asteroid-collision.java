class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        int n = asteroids.length;
        List<Integer> st = new ArrayList<>();
        for(int i =0;i<n;i++){  //O(N)
            if(asteroids[i]>0){
                st.add(asteroids[i]);
            }
            else{
                //st.get(st.size() -1) -> acts as the top/last element in the list
                //destroy all smaller right direction asteroids
                while(!st.isEmpty() && st.get(st.size() -1)>0 && st.get(st.size() -1) < Math.abs(asteroids[i])){
                    st.remove(st.size()-1); // O(N)
                }
                //destroyed when both are of equal sizes
                if(!st.isEmpty() && st.get(st.size() - 1) == Math.abs(asteroids[i])){
                    st.remove(st.size()-1);
                }
                // case when there is no asteroid, or it is a negative one on top
                else if(st.isEmpty() || st.get(st.size()-1)<0){
                    st.add(asteroids[i]);
                }
            }
        }
        int [] result = new int[st.size()];
        for(int i = 0; i<st.size();i++){
            result[i] = st.get(i);
        }
        return result;
    }
}