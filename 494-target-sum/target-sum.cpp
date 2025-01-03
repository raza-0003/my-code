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
        vector<int>prev(aim+1,0),curr(aim+1,0);
        if(nums[0]==0){
            prev[0]=2; // two cases pick or not pick
        }
        else{
            prev[0] = 1;   //only one case not pick
        }
        if(nums[0]!=0 && nums[0]<=aim){
            prev[nums[0]] = 1;     //only one case pick
        }
        for(int i=1;i<n;i++){
            for(int tar=0;tar<=aim;tar++){
                int notTake = prev[tar];
                int take = 0;
                if(tar>=nums[i]){
                    take = prev[tar-nums[i]];
                }
                curr[tar] = take + notTake;
            }
            prev = curr;
        }
        return prev[aim];
    }
};