class Solution {
public:
    string sortString(string s) {
        map<char, int> mpp;
        // Count the frequency of each character in the string
        for (char c : s) {
            mpp[c]++;
        }

        string result = "";
        while (result.size() < s.size()) {
            // Ascending order: add characters in increasing order
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                if (mpp[ch] > 0) {
                    result += ch;
                    mpp[ch]--;
                }
            }
            // Descending order: add characters in decreasing order
            for (char ch = 'z'; ch >= 'a'; --ch) {
                if (mpp[ch] > 0) {
                    result += ch;
                    mpp[ch]--;
                }
            }
        }
        return result;
    }
};
