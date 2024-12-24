class Solution {
public:
    int balancedStringSplit(string s) {
        int balance = 0;
        int cntL = 0;
        int cntR = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == 'L'){
                cntL++;
            }
            else if(s[i] == 'R'){
                cntR++;
            }
            if(abs(cntL-cntR) == 0){
                balance++;
            }
        }
        return balance;
        
    }
};