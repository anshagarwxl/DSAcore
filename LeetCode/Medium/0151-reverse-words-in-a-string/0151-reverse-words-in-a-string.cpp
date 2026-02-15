class Solution {
public:
    string reverseWords(string s){
       string res = "";
       int i =0;
       while(i<s.length() && s[i] == ' '){
        i++;
       }
        for(i; i < s.length(); i++){
            if(s[i] != ' ')
            res+= s[i];
            else if(!res.empty() && res.back() != ' '){ //checks if last added char not a string, if not then add a ' '
                res+= ' ';
            }
        }
            //remove trailing spaces
            if(!res.empty() && res.back() == ' ') //checks if there are spaces at the end
                res.pop_back();    
                    
        reverse(res.begin(), res.end());
        int n = res.length();
        int start = 0;
        for(int j =0; j<=n;j++){
            if(j==n || res[j] == ' '){
                reverse(res.begin()+start, res.begin() +j);
                start=j+1;
            }
        }
    return res;
    }
};