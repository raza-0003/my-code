class Solution {
public:
    bool f(int ind,int target,vector<int>& nums,vector<vector<int>>&dp){
        if(target == 0) return true;
        if(ind == 0) return (nums[ind] == target);
        if(dp[ind][target]!=-1) return dp[ind][target];
        bool notTake = f(ind-1,target,nums,dp);
        bool Take = false;
        if(target >= nums[ind]){
            Take = f(ind-1,target-nums[ind],nums,dp);
        }
        return dp[ind][target] = Take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int arrSum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            arrSum += nums[i];
        }
        int k = arrSum/2;
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        if(arrSum & 1) return false;
        return f(n-1,k,nums,dp);
    }
};