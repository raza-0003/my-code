class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>>ans;
        map<int,int>mpp;    //{number,values}
        for(auto it:nums1){
            mpp[it[0]] = it[1];
        }
        for(auto it:nums2){
            mpp[it[0]] = it[1] + mpp[it[0]];
        }
        for(auto it:mpp){
            ans.push_back({it.first,it.second});
        }
        return ans;  
    }
};