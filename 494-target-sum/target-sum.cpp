class Solution {
public:
    int f(int index,int target,vector<int>&nums,vector<vector<int>>&dp){
        if(index==0){
            if(target == 0 && nums[0] == 0) return 2;
            if(target ==0 || target == nums[0]) return 1;
            return 0;
        }
        if(dp[index][target]!=-1) return dp[index][target];
        int notTake = f(index-1,target,nums,dp);
        int take = 0;
        if(nums[index]<=target){
            take = f(index-1,target-nums[index],nums,dp);
        }
        return dp[index][target] = (take + notTake);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totSum = 0;
        for(int i=0;i<n;i++){
            totSum += nums[i];
        }
        int aim = (totSum-target)/2;
        if(totSum-target < 0 || (totSum-target)%2 == 1) return 0;
        vector<vector<int>>dp(n,vector<int>(aim+1,-1));
        return f(n-1,aim,nums,dp);
    }
};