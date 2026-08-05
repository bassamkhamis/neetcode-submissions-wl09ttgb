class Solution {
    /**
     * @param {number} target
     * @param {number[]} position
     * @param {number[]} speed
     * @return {number}
     */
    // 0 3 5 8 10
    // 1 3 1 4 2
    // 12 3 7 1 1
    carFleet(target, position, speed) {

        let pair = position.map((p, i) => [p, speed[i]])
        pair.sort((a, b) => b[0] - a[0])

        let stack = []
        for (let [p, s] of pair) {
            stack.push((target - p) / s)
            if (
                stack.length >= 2 &&
                stack[stack.length - 1] <= stack[stack.length - 2]
            ) {
                stack.pop()
            }
        }
        return stack.length

        // const pairs = position.map((item, index) => [item, speed[index]])

        // pairs.sort((a, b) => b[0] - a[0])
        // console.log(pairs)

        // let pre = (target - pairs[0][0]) / pairs[0][1]
        // let res = 1

        // for (let i = 1; i < speed.length; i++) {
        //     let t = (target - pairs[i][0]) / pairs[i][1]
        //     if (t > pre) {
        //         pre = t
        //         res++
        //     }
        // }
        // return res
    }
}
