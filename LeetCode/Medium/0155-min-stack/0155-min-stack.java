class MinStack {
    public Stack<Long> st;
    public long mini;

    public MinStack() {
        st = new Stack<>();
    }
    public void push(int value) {
        long val = value;

        if(st.isEmpty()){
            mini = val;
            st.push(val);
            return;
        }

        if(val >= mini){
            st.push(val);
        } else {
            st.push(2*val - mini);
            mini = val;
        }
    }
    public void pop() {
        if(st.isEmpty()) return;

        long x = st.pop();

        if(x < mini){
            mini = 2*mini - x;
        }
    }
    public int top() {
        if(st.isEmpty()) return -1;

        long x = st.peek();

        if(x >= mini){
            return (int)x;
        } else {
            return (int)mini;
        }
    }
    public int getMin() {
        if(st.isEmpty()) return -1;
        return (int)mini;
    }
}