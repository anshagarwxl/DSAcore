class Solution {
    public boolean isPalindrome(String s) {
        String cleaned = s.toLowerCase().replaceAll("[^a-z0-9]", "");
        return checkPalindrome(0, cleaned);
    }
    public boolean checkPalindrome( int i , String cleaned){
        int n = cleaned.length();
        if(i>=n/2)
        return true;
        if(cleaned.charAt(i) != cleaned.charAt(n-i-1))
    return false;
    return checkPalindrome(i+1, cleaned);
    }
}