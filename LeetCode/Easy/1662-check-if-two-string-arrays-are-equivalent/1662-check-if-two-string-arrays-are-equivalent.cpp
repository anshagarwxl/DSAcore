class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    string result1 = "";

    for(string s : word1){
        result1 += s;
    }
    string result2 ="";
    for(string s : word2){
        result2+= s;
    }

    if(result1==result2)
    return true;
    return false;
    }
};