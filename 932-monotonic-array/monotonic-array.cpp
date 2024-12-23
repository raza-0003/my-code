class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        vector<int>asc = nums;
        sort(asc.begin(),asc.end());
        if(asc == nums) return true;
        vector<int>desc = nums;
        sort(desc.begin(),desc.end(),greater<int>());
        if(desc == nums) return true;
        return false;
        
    }
};