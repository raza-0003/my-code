class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        sort(coins.begin(),coins.end());
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        //filling the first row dp 
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0){
                dp[0][i]=i/coins[0];
            }
            else{
                dp[0][i] = 1e9;
            }
        }
        for(int i=1;i<n;i++){
            for(int tar=0;tar<=amount;tar++){
                int notTake = 0 + dp[i-1][tar];
                int take = 1e9;
                if(coins[i]<=tar){
                    take = 1 + dp[i][tar-coins[i]];
                }
                dp[i][tar] = min(take,notTake);
            }
        }
        return (dp[n-1][amount] >= 1e8) ? -1:dp[n-1][amount];   
    }
};