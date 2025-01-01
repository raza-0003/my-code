class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        unordered_map<char,int>mpp;
        mpp['I'] = 1;
        mpp['V'] = 5;
        mpp['X'] = 10;
        mpp['L'] = 50;
        mpp['C'] = 100;
        mpp['D'] = 500;
        mpp['M'] = 1000;
        int ans = 0;
        for(int i=1;i<n;i++){
            if(mpp[s[i-1]] >= mpp[s[i]]){
                ans += mpp[s[i-1]];
            }
            else{
                ans -= mpp[s[i-1]];
            }
        }
        ans += mpp[s[n-1]];
        return ans;
    }
};