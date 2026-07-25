class Solution {
    /**
     * @param {number[]} nums
     * @return {number[][]}
     */
    threeSum(nums) {
        // brute force
        const len = nums.length
        let res = []
        let st = new Set()

        nums.sort()
        for (let i = 0; i < len; i++) {
            for (let j = i + 1; j < len; j++) {
                for (let k = j + 1; k < len; k++) {
                    if (nums[i] + nums[j] + nums[k] === 0)
                        st.add(JSON.stringify([nums[i], nums[j], nums[k]])) // set cannot detect duplication of array of array was pushed
                }
            }
        }

        st.forEach((item) => res.push(JSON.parse(item)))
        return res                
    }
}
