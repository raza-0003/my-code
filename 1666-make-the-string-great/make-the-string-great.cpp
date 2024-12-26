class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        
        // Loop through the string
        for (int i = 1; i < n; ) {
            // Check if the adjacent characters form a bad pair
            if (abs(s[i] - s[i - 1]) == 32) {
                // Remove the bad pair by erasing both characters
                s.erase(i - 1, 2);
                n -= 2;  // Adjust the length of the string after removal
                i = max(i - 1, 1);  // Move back to recheck previous character, avoid going to negative index
            } else {
                // If no bad pair, just move to the next character
                i++;
            }
        }
        
        return s;
    }
};
