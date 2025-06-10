class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char,int>mpp;
        int left = 0;
        int right = 0;
        int maxLen = 0;
        int maxfreq = 0;
        while(right < n){
            mpp[s[right]]++;
            if(mpp[s[right]] > maxfreq) maxfreq = mpp[s[right]];
            if((right-left+1) - maxfreq <= k){
                maxLen = max(maxLen,right-left+1);
            }
            else{
                while((right-left+1) - maxfreq > k){
                    mpp[s[left]]--;
                    left++;
                }
            }
            right++;

        }
        return maxLen;
        
    }
};