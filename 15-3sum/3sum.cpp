class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        int left,right,target,sum;
        if(nums[0] > 0) return {};
        for(int i=0;i<n;i++){
            if(nums[i]>0) break;
            if(i>0 && nums[i]==nums[i-1]) continue; // skip the current iteration(duplicate)
            // intialize the two pointer approach
            left = i+1;
            right = n-1;
            target = 0-nums[i];
            while(left<right){
                sum = nums[left] + nums[right];
                if(sum == target){
                    res.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                    while(left<right && nums[left] == nums[left-1]){
                        left++;
                    }
                    while(left < right && nums[right] == nums[right+1]){
                        right--;
                    } 
                }
                else if(sum < target) left++;
                else right--;
            }
            
        }
        return res;
    }
};