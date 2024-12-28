class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0; // Base case: T0 = 0
        if (n == 1 || n == 2) return 1; // Base cases: T1 = T2 = 1

        vector<int> Fib(n + 1); // Initialize vector to store values up to Tn
        Fib[0] = 0;
        Fib[1] = Fib[2] = 1;

        for (int i = 3; i <= n; i++) {
            Fib[i] = Fib[i - 1] + Fib[i - 2] + Fib[i - 3];
        }
        return Fib[n];
    }
};
