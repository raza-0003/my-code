class Solution {
public:
    vector<int> genSubset(int ind,vector<int>& nums,vector<vector<int>>&ans, vector<int>&temp){
        if(ind == nums.size()){
            ans.push_back(temp);
            return temp;
        }
        genSubset(ind+1,nums,ans,temp);
        temp.push_back(nums[ind]);
        genSubset(ind+1,nums,ans,temp);
        temp.pop_back();
        return temp;

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        int n = nums.size();
        genSubset(0,nums,ans,temp);
        return ans;
    }
};