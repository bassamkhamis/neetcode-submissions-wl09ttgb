class Solution {
    /**
     * @param {number[]} height
     * @return {number}
     */
    trap(height) {
        if (height.length === 0)
            return 0 

        let left = 0, right  = height.length - 1
        let maxLeft = height[left], maxRight = height[right]
        let res = 0

        while (left < right) {
            if (maxLeft < maxRight) {
                left++
                maxLeft = Math.max(maxLeft, height[left])
                res += maxLeft - height[left]   
            } 
            else {
                right--
                maxRight = Math.max(maxRight, height[right])
                res += maxRight - height[right]   
            }
        }

        return res
        
        // let leftMax = Array(height.length).fill(0)
        // let rightMax = Array(height.length).fill(0)
        // let res = 0

        // for (let i = 1; i < height.length; i++)
        //     leftMax[i] = Math.max(leftMax[i - 1], height[i - 1])

        // for (let i = height.length - 2; i >=0; i--)
        //     rightMax[i] = Math.max(rightMax[i + 1], height[i + 1])  

        //  for (let i = 0; i < height.length; i++) {
        //     let val = Math.min(leftMax[i], rightMax[i]) - height[i]  
        //     if (val > 0)
        //         res += val 

        //  }

        //  return res
    }
}
