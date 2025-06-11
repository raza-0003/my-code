class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        vector<int>freq(3,-1);
        for(int i=0;i<n;i++){
            freq[s[i]-'a'] = i;
            if(freq[0]!=-1 && freq[1]!=-1 && freq[2]!=-1){
                cnt += min(freq[0],min(freq[1],freq[2])) + 1;
            }
        }
        return cnt;
        
    }
};