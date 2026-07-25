class Solution {
    /**
     * @param {number[]} heights
     * @return {number}
     */
    maxArea(heights) {
        let left = 0
        let right = heights.length - 1 

        let res = Number.MIN_SAFE_INTEGER


        while (left < right) {
            res = Math.max(res, Math.min(heights[left], heights[right]) * (right - left))

            if (heights[right] > heights[left])
                left++
            else
                right--    
        }

        return res
    }
}
