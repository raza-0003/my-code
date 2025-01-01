class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int maxi = -1e9;
        int cntLeft = 0;
        for(int left=0;left<n-1;left++){
            int cntRight = 0;
            if(s[left]=='0') cntLeft++;
            for(int right=left+1;right<n;right++){
                if(s[right]=='1') cntRight++;
            }
            maxi = max(maxi,cntLeft + cntRight);
        }
        return maxi;
    }
};