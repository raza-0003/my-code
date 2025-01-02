class Solution {
public:
    int f(int index,int target,vector<int>&coins,vector<vector<int>>&dp){
        if(index == 0){
            if(target%coins[0]== 0) return target/coins[0];
            return 1e8;
        }
        if(dp[index][target]!=-1) return dp[index][target];
        int notTake = 0 + f(index-1,target,coins,dp);
        int take = 1e9;
        if(coins[index]<=target){
            take = 1 + f(index,target-coins[index],coins,dp);
        }
        return dp[index][target] = min(take,notTake);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        sort(coins.begin(),coins.end());
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int result = f(n-1,amount,coins,dp);
        return (result >= 1e8) ? -1 : result;      
    }
};