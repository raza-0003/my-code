class Solution {
public:
    void solve(int open,int close,string otp,vector<string>&ans){
        if(open == 0 && close == 0){
            ans.push_back(otp);
            return;
        }
        if(open != 0){
            string otp1 = otp;
            otp1.push_back('(');
            solve(open-1,close,otp1,ans);
        }
        if(close > open){
            string otp2 = otp;
            otp2.push_back(')');
            solve(open,close-1,otp2,ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string otp = "";
        int open = n,close = n;
        solve(open,close,otp,ans);
        return ans;
    }
};