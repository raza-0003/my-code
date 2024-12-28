class Solution {
public:
    int f(int index){
        if(index ==1 || index == 0) return index;
        return f(index-1) + f(index-2);
    }
    int fib(int n) {
        return f(n);
    }
};