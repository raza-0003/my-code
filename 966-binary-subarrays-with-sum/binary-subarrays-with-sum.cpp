class Solution {
public:
    int sumOfSubLessOrEqual(vector<int>& nums, int goal){
        if(goal < 0) return 0;
        int left  = 0;
        int right = 0;
        int sum = 0;
        int cnt = 0;
        int n = nums.size();
        while(right < n){
            sum += nums[right];
            while(sum > goal){
                sum -= nums[left];
                left++;
            }
            cnt += right - left + 1;
            right++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = sumOfSubLessOrEqual(nums,goal) - sumOfSubLessOrEqual(nums,goal-1);
        return ans;
        
    }
};