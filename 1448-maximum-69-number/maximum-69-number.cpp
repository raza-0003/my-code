class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '6') {
                s[i] = '9';
                break; // only flip the first '6'
            }
        }
        return stoi(s);
    }
};
