class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int min = INT_MAX;
        int sec_min = INT_MAX;
        for(int &choco : prices){
            if(choco<min){
                sec_min = min;
                min = choco;
            }
            else if(choco < sec_min){
                sec_min = choco;
            }
        }
        if(min + sec_min > money){
            return money;
        }
        return money = money - min - sec_min;
    }
};