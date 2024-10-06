class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;
        long n = abs(dividend);
        long d = abs(divisor);
        bool sign = true;
        if(dividend>=0 && divisor<0) sign = false;
        if(dividend<=0 && divisor>0) sign = false;

        int res = 0;
        // check condition if no is negative or divisor is negative
        while(n>=d){
            int cnt = 0;
            while(d << (cnt+1) <= n){ // iwrite cnt+1 not cnt because in above while loop condition is already checked
            
                cnt++;
            }
            res+= 1<<(cnt);
            n = n - (d<<(cnt));
        }
        if((res == 1<<31) && (sign == true)){
            return INT_MAX;
        }
        if((res == 1<<31) && (sign == false)){
            return INT_MIN;
        }

        return sign ? res : -res;
        
    }
};