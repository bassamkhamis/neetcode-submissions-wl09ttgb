class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool needOne = false; 
        for (int r = digits.size() - 1; r>=0; r--) {
            if (digits[r] < 9)
            {
                digits[r]++;
                break;
            }
            else {
                digits[r] = 0;
                if (r == 0)
                    needOne = true;
            }
        }

        if (needOne)
            digits.insert(digits.begin(), 1);

        return digits;
    }
};
