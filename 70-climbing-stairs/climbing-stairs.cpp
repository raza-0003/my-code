class Solution {
    int fibo(int n,vector<int>&dp){
        if(n<=1) return 1;
        if(dp[n] != -1) return dp[n];
        return dp[n] = fibo(n-1,dp) + fibo(n-2,dp);
    }

public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return fibo(n,dp);
    }
};