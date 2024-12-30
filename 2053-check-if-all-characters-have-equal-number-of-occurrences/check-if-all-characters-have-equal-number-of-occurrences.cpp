class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int n = s.size();
        map<char,int>mpp;
        for(auto it:s){
            mpp[it]++;
        }
        int z = mpp[s[0]];
        for(int i=0;i<n;i++){
            if(mpp[s[i]]!= z) return false;
        }
        return true;
    }
};