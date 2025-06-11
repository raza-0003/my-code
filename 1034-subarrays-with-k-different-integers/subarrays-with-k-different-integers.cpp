class Solution {
public:
    int funCntSubWithDiffk(vector<int>& nums, int k){
        int n = nums.size();
        int cnt = 0;
        int left = 0;
        int right = 0;
        int sum = 0;
        unordered_map<int,int>mpp;
        while(right < n){
            mpp[nums[right]]++;
            while(mpp.size() > k){
                mpp[nums[left]]--;
                if(mpp[nums[left]] == 0){
                    mpp.erase(nums[left]);
                }
                left++;
            }
            cnt += right - left + 1;
            right++;
        }
        return cnt; 

    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans = funCntSubWithDiffk(nums,k) - funCntSubWithDiffk(nums,k-1);
        return ans;
    }
};