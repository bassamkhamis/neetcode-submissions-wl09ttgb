class KthLargest {
    vector<int> nums;
    int k;
public:
    KthLargest(int k, vector<int>& nums) : k(k), nums(nums) { }
    
    int add(int val) {
       nums.push_back(val);
       sort(nums.rbegin(), nums.rend());
       return nums[k-1]; 
    }
};
