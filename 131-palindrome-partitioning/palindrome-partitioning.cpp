class Solution {
public:
    bool isPalindrome(int start,int end,string s){
        while(start<end){
            if(s[start] != s[end]){
                return 0;
            }
            start++;
            end--;
        }
        return true;
    }
    void solve(int index,string s,vector<string>&otp,vector<vector<string>>&ans){
        if(index == s.size()){
            ans.push_back(otp);
            return;
        }
        for(int parInd = index;parInd<s.size();parInd++){
            if(isPalindrome(index,parInd,s)){
                otp.push_back(s.substr(index,parInd-index+1));
                solve(parInd+1,s,otp,ans);
                otp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>otp;
        vector<vector<string>>ans;
        solve(0,s,otp,ans);
        return ans;
        
    }
};