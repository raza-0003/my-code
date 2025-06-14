class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string maxNum = s,minNum = s;

        // for maximum: replace the first non-9 digit with 9
        char maxReplace = 0;
        for(char ch : s){
            if(ch != '9'){
                maxReplace = ch;
                break;
            }
        }
        if(maxReplace != 0){
            for(char &ch:maxNum){
                if(ch == maxReplace) ch = '9';
            }
        }

        // For min: replace the first digit that is not 0 or 1 with 0
        char minReplace = s[0];
        for(char ch:s){
           if(ch == minReplace) ch = '0';
        }
        if(minReplace != 0){
            for(char &ch: minNum){
                if(ch == minReplace) ch = '0';
            }
        }
        return stoi(maxNum) - stoi(minNum);
    }
};