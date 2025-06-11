class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        unordered_map<char,int>mpp;
        mpp['a']=-1;
        mpp['b']=-1;
        mpp['c']=-1;
        for(int i=0;i<n;i++){
            mpp[s[i]] = i;
            if(mpp['a']!=-1 && mpp['b']!=-1 && mpp['c']!=-1){
                cnt += min(mpp['a'],min(mpp['b'],mpp['c'])) + 1;
            }

        }
        return cnt;
        
    }
};