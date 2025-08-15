class Solution {
public:
    bool isPowerOfFour(int n) {
        long long temp  = 1;
        while(temp <= n)
        {
            if(n==temp) return true;
            temp *= 4;
        }
        return false;
    }
};