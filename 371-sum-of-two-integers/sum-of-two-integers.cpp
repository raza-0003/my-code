class Solution {
public:
    int getSum(int a, int b) {
        while(b){
            int temp = (a & b) << 1;
            a = a ^ b;
            b = temp;
        }
        return a;
    }
};