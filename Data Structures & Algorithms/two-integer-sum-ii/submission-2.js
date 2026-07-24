class Solution {
    /**
     * @param {number[]} numbers
     * @param {number} target
     * @return {number[]}
     */
    twoSum(numbers, target) {
        let mp = new Map()

        for (let i = 0; i < numbers.length; i++)
        {
            if (mp.has(target - numbers[i]))
                return [mp.get(target - numbers[i]) + 1, i + 1]

            mp.set(numbers[i], i)    
        }

        return [-1, -1]
    }
}
