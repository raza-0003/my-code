class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i] += 1;  // Add 1 if the digit is less than 9
                return digits;  // No carry needed, return the result
            }
            digits[i] = 0;  // Set current digit to 0 and carry over
        }
        // If all digits were 9, we need an extra digit
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
