class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char,int>mpp1;
        unordered_map<char,int>mpp2;
        for(int i=0;i<s.size();i++){
            mpp1[s[i]]++;
            mpp2[t[i]]++;
        }
        return mpp1 == mpp2;
        
    }
};