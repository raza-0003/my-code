class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int>mpp;
        int left = 0,right = 0;
        int maxLen = 0;
        while(right < n){
            if(mpp.find(s[right]) != mpp.end()){
                // it is found in the map
                if(mpp[s[right]] >= left){
                    left = mpp[s[right]] + 1;
                }

            }
            maxLen = max(maxLen,right-left+1);
            mpp[s[right]] = right;
            right++;
            
        }
        return maxLen;
        
    }
};