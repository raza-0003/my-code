class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLen = 0;
        for(int i=0;i<n;i++){
            set<char>st;
            int temp = 0;
            for(int j=i;j<n;j++){
                if(st.find(s[j]) != st.end()){
                    break;
                }
                else{
                    st.insert(s[j]);
                    temp++;
                    maxLen = max(maxLen,temp);

                }
            }
        }
        return maxLen;
        
    }
};