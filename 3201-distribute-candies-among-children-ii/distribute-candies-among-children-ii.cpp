#include<bits/stdc++.h>
class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        // let childrens are: A B C
        for(int i=0;i<= min(n,limit);i++){
            // let A gets i choclate  
            if((n - i)  > 2 * limit ){
                // we can't distribute choclates to children
                continue;
            }
             // n-i candies are remaining to distribute this candies into 2 student B,C and  B+C = n-i
            int remaining = n - i;
            // B_max = min(remaining,limit)
            // B_min = max(0,remaining-limit)
            ans = ans +  min(remaining,limit) - max(0,remaining-limit) + 1;
        }
        return ans;

    }
};