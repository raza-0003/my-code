class Solution {
public:
    void perm(vector<int>&ds,vector<int>&nums,vector<vector<int>>&ans,vector<int>&freq){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                // it means not visited
                freq[i] = 1;
                ds.push_back(nums[i]);
                perm(ds,nums,ans,freq);
                freq[i]=0;
                ds.pop_back();  // pop out the last element from the ds
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int>ds;
        vector<vector<int>>ans;
        vector<int>freq(n,0);
        perm(ds,nums,ans,freq);
        return ans;
    }
};