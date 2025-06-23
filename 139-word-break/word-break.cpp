class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        int n = s.size();
        int maxLen = 0;
        for(auto word:wordDict){
            int sizee = word.size();
            maxLen = max(maxLen,sizee);
        }
        vector<bool>dp(n+1);
        dp[0] = true;
        for(int i=1;i<=n;i++){
            for(int j = i-1;j>=max(0,i-maxLen);j--){
                string substrr = s.substr(j,i-j);
                if(dp[j] && st.find(substrr) != nullptr){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};