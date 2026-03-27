class Solution {
    public boolean isAnagram(String s, String t) {
        int [] count = new int[26];

        for(char ch: s.toCharArray()){
            count[ch-'a']++;
        }
        for(char ch : t.toCharArray()){
            count[ch-'a']--;
        }

        //checking if all elements in the array are 0
        boolean allZeroes = Arrays.stream(count).allMatch(element->element == 0);

        return allZeroes;
    }
}