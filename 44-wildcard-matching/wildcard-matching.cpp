class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(); // Length of string s
        int m = p.size(); // Length of pattern p

        // Initialize two 1D arrays of size (m+1)
        vector<bool> prev(m + 1, false), curr(m + 1, false);

        // Base case: Empty string matches empty pattern
        prev[0] = true;

        // Base case: Pattern matches an empty string only if it contains '*' at all positions
        for (int j = 1; j <= m; j++) {
            prev[j] = prev[j - 1] && p[j - 1] == '*';
        }

        // Fill the DP table row by row
        for (int i = 1; i <= n; i++) {
            curr[0] = false; // Non-empty string cannot match an empty pattern
            for (int j = 1; j <= m; j++) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                    curr[j] = prev[j - 1]; // Characters match or '?' matches any single character
                } else if (p[j - 1] == '*') {
                    curr[j] = prev[j] || curr[j - 1]; // '*' matches zero or more characters
                } else {
                    curr[j] = false; // No match
                }
            }
            // Move to the next row
            prev = curr;
        }

        // Final result is stored in prev[m] after processing all rows
        return prev[m];
    }
};

