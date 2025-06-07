class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int>hash(256,-1);
        int left = 0,right = 0;
        int maxLen = 0;
        while(right < n){
            if(hash[s[right]] != -1){
                // it is found in the map
                if(hash[s[right]] >= left){
                    left = hash[s[right]] + 1;
                }

            }
            maxLen = max(maxLen,right-left+1);
            hash[s[right]] = right;
            right++;
            
        }
        return maxLen;
        
    }
};