class Solution {
public:
    string oddString(vector<string>& words) {
        int m = words[0].size();
        vector<vector<int>> diffs;
        
        // Calculate difference arrays for all words
        for (string& word : words) {
            vector<int> diff;
            for (int i = 0; i < m - 1; i++) {
                diff.push_back(word[i + 1] - word[i]);
            }
            diffs.push_back(diff);
        }
        
        // Find the odd one out
        if (diffs[0] != diffs[1]) {
            return diffs[0] == diffs[2] ? words[1] : words[0];
        }
        
        for (int i = 2; i < words.size(); i++) {
            if (diffs[i] != diffs[0]) {
                return words[i];
            }
        }
        
        return words[0];
    }
};