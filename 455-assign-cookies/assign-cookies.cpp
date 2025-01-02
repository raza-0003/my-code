class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int sptr = 0;
        int gptr = 0;
        int cnt = 0;
        int s_size = s.size();
        if(s_size==0) return 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(sptr!=s_size && gptr!=g.size()){
            if(s[sptr] >= g[gptr]){
                cnt++;
                sptr++;
                gptr++;
            }
            else{
                sptr++;
            }
        }
        return cnt;
    }
};