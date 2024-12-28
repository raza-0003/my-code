class Solution {
public:
    int f(int index,vector<int>&prices,int minSofar){
        if(index == prices.size()) return 0;
        minSofar = min(minSofar,prices[index]);
        int curProfit = prices[index] - minSofar;
        int nextProfit = f(index+1,prices,minSofar);
        return max(curProfit,nextProfit);
    }
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        return f(0,prices,prices[0]);
    }
};