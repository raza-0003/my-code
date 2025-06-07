class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0;    // keeps two pointer left and right
        int maxLen = 0;
        int zeros = 0;              // to keep track of all zerso 
        while(right < n){
            if(nums[right] == 0){
                zeros++;
            }
            while(zeros > k){
                if(nums[left] == 0){
                    zeros--;
                }
                left++;
            }
            int len = right - left + 1;
            maxLen = max(maxLen,right - left + 1);
            right++;
        }
        return maxLen;
    }
};