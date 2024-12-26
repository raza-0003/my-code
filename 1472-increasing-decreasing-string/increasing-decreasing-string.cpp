class Solution {
public:
    string sortString(string s) {
        map<char,int>mpp;
        for(auto it:s){
            mpp[it]++;
        }
        vector<char>st;
        for(int i=0;i<s.size();i++){
            for(char ch='a';ch<='z';ch++){
            if(mpp[ch]!=0){
                st.push_back(ch);
                mpp[ch]--;
                }
            }
            for(char ch='z';ch>='a';ch--){
                if(mpp[ch]!=0){
                    st.push_back(ch);
                    mpp[ch]--;
                }
            }
        }
        string ans(st.size(),' ');
        for(int i=0;i<st.size();i++){
            ans[i] = st[i];
        }
        return ans;

    }
};