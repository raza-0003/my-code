class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        vector<bool> is_prime(n, true);
        is_prime[0] = is_prime[1] = false;

        for (int p = 2; p * p < n; ++p) {
            if (is_prime[p]) {
                for (int multiple = p * p; multiple < n; multiple += p) {
                    is_prime[multiple] = false;
                }
            }
        }

        return count(is_prime.begin(), is_prime.end(), true);
    }
};