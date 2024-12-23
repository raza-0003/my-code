class Solution {
public:
    int kthFactor(int n, int k) {
        // Iterate up to sqrt(n) to collect smaller factors
        for (int i = 1; i <= n; ++i) {
            if (n % i == 0) { // Check if i is a factor
                --k;         // Decrement k
                if (k == 0) return i; // Return the k-th factor
            }
        }
        return -1; // If k factors are not found
    }
};

