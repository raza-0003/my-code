class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mpp1, mpp2;
        vector<int> ans(2,0);
        
        // Mark presence
        for(int num : nums1) mpp1[num] = 1;
        for(int num : nums2) mpp2[num] = 1;
        
        // Count all occurrences
        for(int num : nums1) {
            if(mpp2.count(num)) ans[0]++;
        }
        
        for(int num : nums2) {
            if(mpp1.count(num)) ans[1]++;
        }
        
        return ans;
    }
};