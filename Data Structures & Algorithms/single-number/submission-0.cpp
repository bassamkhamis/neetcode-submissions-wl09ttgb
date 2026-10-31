class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*
            xor tricky:
            1 ^ 1 = 0
            1 ^ 0 = 1
            0 ^ 1 = 1

            rule:  two number are the same the result will be 0
                    two number different => result 1

            in this case: the the repated numbers will removed because they have the same bits
            and none repated one wil be kept        

        */

        int missed_number{};
        for (int num: nums)
            missed_number ^= num;

        return missed_number;
    }
};
