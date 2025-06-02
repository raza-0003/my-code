class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 0) return "";
        int start = 0;
        int maxLength = 1;
        for(int i=0;i<n;i++){
            // checking for odd length palindrome
            int left = i;
            int right = i;
            while(left >= 0 && right < n && s[left] == s[right]){
                if(right - left + 1 > maxLength){
                    start = left;
                    maxLength = right - left + 1;
                }
                left--;
                right++;
            }
            // checking for the even lenght palindrome
            left = i;
            right = i+1;
            while(left >= 0 && right < n && s[left] == s[right]){
                if(right - left + 1 > maxLength){
                    start = left;
                    maxLength = right - left + 1;
                }
                left--;
                right++;
            } 
        }
        return s.substr(start,maxLength);
    }
};