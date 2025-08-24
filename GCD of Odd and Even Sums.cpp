class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        long long oddSum = 1ll * n * n;
        long long evenSum = 1ll * n * (n+1);
        return gcd(oddSum, evenSum);
    }
};