class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int speed = 1;
        while (true) {
            long long totalTime = 0;
            for (int pile : piles) {
                totalTime +=  ceil(static_cast<double>(pile) / speed); //(pile + speed - 1) / speed;
            }

            if (totalTime <= h) {
                //return speed;
                break;
            }
            speed++;
        } 

        return speed;
    }
};
