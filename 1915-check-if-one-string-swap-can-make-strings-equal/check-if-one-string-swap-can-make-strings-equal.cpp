class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2) return true;
        if(s1.length() != s2.length()) return false;
        
        vector<int> diff_positions;
        
        // Find positions where characters differ
        for(int i = 0; i < s1.length(); i++) {
            if(s1[i] != s2[i]) {
                diff_positions.push_back(i);
            }
        }
        
        // If number of different positions is not 2, return false
        if(diff_positions.size() != 2) return false;
        
        // Check if swapping these positions makes strings equal
        return (s1[diff_positions[0]] == s2[diff_positions[1]] && 
                s1[diff_positions[1]] == s2[diff_positions[0]]);
    }
};