class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int target = -nums[i];
            unordered_map<int,int>mpp;
            for(int j=i+1;j<n;j++){
                int complement = target - nums[j];
                if(mpp.count(complement)){
                    ans.push_back({nums[i],nums[j],complement});
                    while(j+1< n && nums[j] == nums[j+1]){
                        j++;
                    }
                }
                mpp[nums[j]] = j;
            }
        }
        return ans;
        
    }
};