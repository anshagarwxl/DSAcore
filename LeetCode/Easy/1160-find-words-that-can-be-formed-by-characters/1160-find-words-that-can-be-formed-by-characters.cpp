class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        //using an array of size 26

        //first storing frequncy of each char in chars 
        vector<int>charCount(26,0);
        for(char &ch:chars){
            charCount[ch-'a']++;
        }

        int result =0;
        //now iterating over each word inside words
        for(string &word:words){
            vector<int>wordCount(26,0);
            //storing frequency of each letter of each word stored in words
            for(char &ch: word){
                wordCount[ch-'a']++;
            }
            bool ok = true;
            //checking if wordCount>charCount, if yes return false
            for(int i=0; i<26;i++){
                if(wordCount[i]>charCount[i]){
                    ok = false;
                    break;
                }
            }
            if(ok==true)
            result += word.size();
        }
        return result;
    }
};