class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        int validSplit = 0;
        long long left = 0;
        long long totSum = 0;
        for(int i=0;i<n;i++){
            totSum += nums[i];
        }
        for(int i=0;i<n-1;i++){
            left += nums[i];
            if(left >= (totSum-left)){
                validSplit++;
            }
        }
        return validSplit;
    }
};