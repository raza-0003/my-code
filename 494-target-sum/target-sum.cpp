class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totSum = 0;
        for(int i=0;i<n;i++){
            totSum += nums[i];
        }
        int aim = (totSum-target)/2;
        if(totSum-target < 0 || (totSum-target)%2 == 1) return 0;
        vector<vector<int>>dp(n,vector<int>(aim+1,0));
        if(nums[0]==0){
            dp[0][0]=2; // two cases pick or not pick
        }
        else{
            dp[0][0] = 1;   //only one case not pick
        }
        if(nums[0]!=0 && nums[0]<=aim){
            dp[0][nums[0]] = 1;     //only one case pick
        }
        for(int i=1;i<n;i++){
            for(int tar=0;tar<=aim;tar++){
                int notTake = dp[i-1][tar];
                int take = 0;
                if(tar>=nums[i]){
                    take = dp[i-1][tar-nums[i]];
                }
                dp[i][tar] = take + notTake;
            }
        }
        return dp[n-1][aim];
    }
};