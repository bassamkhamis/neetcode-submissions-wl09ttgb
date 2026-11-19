class Solution {
public:
    int reverse(int x) {
        int sign = x > 0 ? 1 : -1;
        long long num = std::abs(x);
        long long res = 0;

        while (num) {
            res = res * 10 + num % 10;
            num /= 10;
        } 

        res *= sign;

        if (res >= INT_MIN && res <= INT_MAX)
            return res;
        else
            return 0;    
    }
};
