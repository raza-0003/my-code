class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        vector<string>ans;
        // task-1 extract all the words from the string is your task01
        for(int i=0;i<n;i++){
            string word;
            if(s[i] != ' '){
                while(s[i] != ' ' && i < n){
                    word += s[i];
                    i++;
                }
                ans.push_back(word);
            }
            else{
                while(s[i] != ' ' && i < n){
                    i++;
                }
            }
        }
        string Ans;
        int m = ans.size();
        for(int i=m-1;i>=0;i--){
            if(i != 0){
                Ans = Ans + ans[i] + " ";
            }
            else{
                     Ans = Ans + ans[i];

            }
            
        }
        return Ans;
    }
};