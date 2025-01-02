class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>prev(amount+1,0),curr(amount+1,0);
        //filling the first row dp 
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0){
                prev[i]=i/coins[0];
            }
            else{
                prev[i] = 1e9;
            }
        }
        for(int i=1;i<n;i++){
            for(int tar=0;tar<=amount;tar++){
                int notTake = 0 + prev[tar];
                int take = 1e9;
                if(coins[i]<=tar){
                    take = 1 + curr[tar-coins[i]];
                }
                curr[tar] = min(take,notTake);
            }
            prev = curr;
        }
        return (prev[amount] >= 1e8) ? -1:prev[amount];   
    }
};