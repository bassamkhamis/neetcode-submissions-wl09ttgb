class Solution {
public:
    bool isHappy(int n) {
        auto sum_sequence = [](int num){
            int sum{};
            while(num) {
                int remainder = num % 10;
                sum += remainder * remainder;
                num /= 10;
            }
            return sum;
        };

        unordered_set<int> seen;

        while(true) {
            n = sum_sequence(n);
            if (n == 1)
                return true;

            if(seen.count(n))
                return false;

            seen.insert(n);        
        }

        return false;
    }
};
