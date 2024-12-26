class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        for (int i = n - 1; i >= 0; i--) {
            if ((num[i] - '0') & 1) {  // Check if the digit is odd
                return num.substr(0, i + 1);  // Return the substring up to this index
            } else {
                num.erase(i, 1);  // Remove the even digit
            }
        }
        return "";  // If no odd digit is found, return an empty string
    }
};
