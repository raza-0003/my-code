class Solution {
public:
    char find(char ch, map<char, char> &mpp) {
        while (mpp.find(ch) != mpp.end() && mpp[ch] != ch) {
            ch = mpp[ch];
            }
        return ch;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        map<char, char> mpp;
        for (int i = 0; i < n; i++) {
            char a = find(s1[i],mpp);
            char b = find(s2[i],mpp);
            if(a == b) continue;
            if(a < b) mpp[b] = a;
            else mpp[a] = b;
        }
        int m = baseStr.size();
        string ans = "";
        for (int i = 0; i < m; i++) {
            ans += find(baseStr[i],mpp);
        }
        return ans;
    }
};