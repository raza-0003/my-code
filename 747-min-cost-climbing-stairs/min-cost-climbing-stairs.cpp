class Solution {
public:
    int f1(int ind,vector<int>&cost,vector<int>&dp){
        if(ind<0) return 0;
        if(ind == 0 || ind ==1) return cost[ind];
        if(dp[ind]!=-1) return dp[ind];
        int fs = cost[ind] + f1(ind-1,cost,dp);
        int ss = cost[ind] + f1(ind-2,cost,dp);
        return dp[ind] = min(fs,ss);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n,-1);
        return min(f1(n-1,cost,dp),f1(n-2,cost,dp));
        
    }
};