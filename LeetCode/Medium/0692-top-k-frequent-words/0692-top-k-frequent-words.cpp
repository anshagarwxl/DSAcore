class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;

    //STEP->1 CREATE MAP TO STORE FREQUENCY
    for(string &word: words){
        mp[word]++;
    }
    //VECTOR CREATION
    vector<pair<string,int>>vec;

    //STEP->2 POPULATE VECTOR WITH {word,freq}
    for(auto &it:mp){
        vec.push_back({it.first,it.second});
    } 
    //STEP->3 SORT VECTOR USING COMPARATOR
    auto lambda = [](pair<string,int>&p1, pair<string,int>&p2){
        if(p1.second == p2.second) // incase of same frequency 
        return p1.first<p2.first;  // return lexicographically wise 

    return p1.second > p2.second;   //case of different frequency, return word with higher frequency
    };
    sort(vec.begin(),vec.end(),lambda);

    //STEP->4 PICK TOP 'K'
    int i =0;
    vector<string> result(k);
    while(i<k){
        result[i]=vec[i].first;
        i++;
    }
    return result;
    }
};