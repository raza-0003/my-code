class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>ans(2);
        //ans[0] --> list of all distinct integer in nums1 not in nums2
        //ans[1] -->list of all distinct integer in nums2 not in nums1
        unordered_set<int>st1(nums1.begin(),nums1.end());
        unordered_set<int>st2(nums2.begin(),nums2.end());
        for(auto it:st1){
            if(st2.find(it) == st2.end()){  // element is not found
                // it means it is unique which is present in nums1, not in nums2
                ans[0].push_back(it);
            }
        }
        for(auto it:st2){
            if(st1.find(it) == st1.end()){
                ans[1].push_back(it);
            }
        }
        return ans; 
    }
};