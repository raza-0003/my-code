class Solution {
public:
    int globalMax;
    int f(int index,vector<int>& nums){
        if(index == 0){
            return nums[0];
        }
        //calculating previous sum;
        int prev = f(index-1,nums);
        // we have choices: 1)go with prev subarray 2)getting alone
        int withprev = prev + nums[index];
        int alone = nums[index];
        int maxEnding = max(withprev,alone);
        globalMax = max(globalMax,maxEnding);
        return maxEnding;
    }
    int maxSubArray(vector<int>& nums) {
        globalMax = nums[0];
        f(nums.size()-1,nums);
        return globalMax;
        
    }
};