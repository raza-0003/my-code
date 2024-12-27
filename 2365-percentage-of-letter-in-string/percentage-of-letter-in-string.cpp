class Solution {
public:
    int percentageLetter(string s, char letter) {
        int n = s.size();
        map<char,int>mpp;
        for(auto it:s){
            mpp[it]++;
        }
        int ans = (mpp[letter] * 100) / n;
        return ans;
    }
};