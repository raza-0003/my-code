class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size(),-1);
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size()+i+1;j++){
                int ind = j%nums.size();
                if(nums[ind]>nums[i]){
                    ans[i]=nums[ind];
                    break;
                }
            }
        }
        return ans;
    }
};