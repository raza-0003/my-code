class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int sInd = -1;
        int minLen = 1e9;
        int left = 0;
        int right = 0;
        int cnt = 0;
        map<char,int>mpp;
        for(auto ch:t){
            mpp[ch]++;
        }
        while(right<n){
            if(mpp[s[right]] > 0) cnt++;
            mpp[s[right]]--;
            while(cnt == m){
                if(right - left + 1 < minLen){
                    minLen = right - left + 1;
                    sInd = left;
                }
                mpp[s[left]]++;
                if(mpp[s[left]] > 0) cnt--;
                left++;
            }
            right = right + 1;
        }
        return sInd == -1 ? "" : s.substr(sInd,minLen);
    }
};