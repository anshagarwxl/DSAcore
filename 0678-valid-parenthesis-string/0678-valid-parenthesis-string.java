
import java.util.Stack;

public class Solution{
    public static boolean checkValidString(String s) {
        Stack<Integer> openStack = new Stack<>();
        Stack<Integer> starStack = new Stack<>();
        // we dont need to define a closeStack as, closers are handled immediately while scanning elements

        //Forward pass
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            if (c == '(') {
                openStack.push(i);
            } else if (c == '*') {
                starStack.push(i);
            } else if (c == ')') {
                if (!openStack.isEmpty()) {
                    openStack.pop(); //matched with opener
                } else if (!starStack.isEmpty()) {
                    starStack.pop();    //using wildcard
                } else {
                    return false; // no opener or wildcard available
                }
            }
        }
        //backward pass
        while (!openStack.isEmpty() && !starStack.isEmpty()) {
            if (starStack.peek() > openStack.peek()) {
                openStack.pop();
                starStack.pop();
            } else {
                break;
            }
        }
        if (!openStack.isEmpty())
            return false;
        return true;
    }
}

