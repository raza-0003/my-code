class Solution {
public:
    int funcNiceSub(vector<int>&nums,int k){
        if(k < 0) return 0;
        int n = nums.size();
        int left = 0;
        int right = 0;
        int maxCnt = 0;
        int sum = 0;
        while(right < n){
           sum += (nums[right] % 2);
           while(sum > k){
            sum -= (nums[left] % 2);
            left++;
           }
           maxCnt += right - left + 1;
           right++;
        }
        return maxCnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = funcNiceSub(nums,k) - funcNiceSub(nums,k-1);
        return ans;
        
    }
};