class Solution {
public:
    int hammingWeight(uint32_t n) {
        int bit_count{};

        for (int i = 0; i < 32; i++)
            if (n & (1U<<i))
                bit_count++;
                
        return bit_count;
    }
};
