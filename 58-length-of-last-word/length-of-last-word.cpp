class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        bool flag = false;
        int cnt = 0;
        for(int i=n-1;i>=0;i--){
            if(s[i] != ' '){
                cnt++;
            }
            else if(cnt>0){
                break;
            }
        }
        return cnt;
        
    }
};