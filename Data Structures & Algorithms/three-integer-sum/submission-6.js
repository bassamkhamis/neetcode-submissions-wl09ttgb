class Solution {
    /**
     * @param {number[]} nums
     * @return {number[][]}
     */
    threeSum(nums) {
        // two pointer + outer loop without set
        const len = nums.length
        let res = []
        nums.sort((a, b) => a - b)

        for (let i = 0; i < len; i++) {
            if (nums[i] > 0) break // all the remining numbers are +ve, leave out the loop now
            if (i > 0 && nums[i] === nums[i-1]) continue // ignore the duplication
            
            let left = i + 1
            let right = len - 1

            while(left < right) {
                let sum = nums[i] + nums[left] + nums[right]
                if (sum === 0) {
                    res.push([nums[i], nums[left], nums[right]])
                    left++
                    right--

                    while (right > left && nums[left] === nums[left - 1])
                        left++
                }
                else if (sum > 0)
                    right--
                else
                    left++    
            }
        }

        return res

        // two pointer + outer loop
        // const len = nums.length
        // let res = []
        // let st = new Set()

        // nums.sort((a, b) => a - b)
        // for (let i = 0; i < len; i++) {
        //     let left = i + 1
        //     let right = len - 1

        //     while(left < right) {
        //         let sum = nums[i] + nums[left] + nums[right]
        //         if (sum === 0) {
        //             let arr = [nums[i], nums[left], nums[right]]
        //             let str = JSON.stringify(arr)
        //             if (!st.has(str)) {
        //                 res.push([nums[i], nums[left], nums[right]])
        //                 st.add(str)
        //             }
        //             left++
        //             right--
        //         }
        //         else if (sum > 0)
        //             right--
        //         else
        //             left++    
        //     }
        // }

        // return res


        // brute force
        // const len = nums.length
        // let res = []
        // let st = new Set()

        // nums.sort()
        // for (let i = 0; i < len; i++) {
        //     for (let j = i + 1; j < len; j++) {
        //         for (let k = j + 1; k < len; k++) {
        //             if (nums[i] + nums[j] + nums[k] === 0)
        //                 st.add(JSON.stringify([nums[i], nums[j], nums[k]])) // set cannot detect duplication of array of array was pushed
        //         }
        //     }
        // }

        // st.forEach((item) => res.push(JSON.parse(item)))
        // return res                
    }
}
