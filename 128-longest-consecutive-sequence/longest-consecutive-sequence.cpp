class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxLen = 0;
    
        for (int num : nums) {
            if (!numSet.count(num - 1)) {  // Find sequence start
                int currNum = num;
                int currLen = 1;
                
                while (numSet.count(currNum + 1)) {
                    currNum++;
                    currLen++;
                }
                maxLen = max(maxLen, currLen);
            }
        }
        return maxLen;
    }
};