class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        if (digits[digits.size()-1] < 9)
        {
            digits[digits.size()-1]++;
            return digits;
        }


        int num{};
        for (int digit : digits)
            num = num * 10 + digit;

        num++; 

        vector<int> res; 
        while(num){
            int remainder = num % 10;
            num /= 10;
            res.insert(res.begin(), remainder);
        }    

        return res;
    }
};
