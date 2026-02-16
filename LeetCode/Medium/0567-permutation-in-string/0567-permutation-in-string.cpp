class Solution {
public:
    bool checkEqual(int a[26], int b[26]){
        for(int i=0;i<26;i++){
            if(a[i]!=b[i]) return 0;
        }
        return 1;
    }

    bool checkInclusion(string s1, string s2) {
        if(s2.length()<s1.length()) return 0;

        int count1[26]={0};
        for(char c:s1) count1[c-'a']++;

        int count2[26]={0};
        int windowSize=s1.length();

        for(int i=0;i<windowSize;i++)
            count2[s2[i]-'a']++;

        if(checkEqual(count1,count2)) return 1;

        for(int i=windowSize;i<s2.length();i++){
            count2[s2[i]-'a']++;
            count2[s2[i-windowSize]-'a']--;

            if(checkEqual(count1,count2)) return 1;
        }
        return 0;
    }
};
