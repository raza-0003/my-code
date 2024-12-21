class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        unordered_map<int,int>prefix;
        unordered_map<int,int>suffix;
        int n = nums.size();
        vector<int>diff(n,0);
        for(auto it:nums){
            suffix[it]++;
        }
        for(int i=0;i<n;++i){
            prefix[nums[i]]++;
            suffix[nums[i]]--;
            if(suffix[nums[i]]==0){
                suffix.erase(nums[i]);
            }
            diff[i] = prefix.size() - suffix.size();
        }
        return diff;
    }
};