class Solution {
    /**
     * @param {string} s
     * @return {boolean}
     */
    isValid(s) {
        let stack = new Array()

        for (const ch of s) {
            if (ch === "(" || ch === "[" || ch === "{")
                stack.push(ch)
            else {
                let top = stack[stack.length - 1]
                if (stack.length !== 0 && (top === "(" && ch === ")" || top === "[" && ch === "]" || top === "{" && ch === "}"))
                    stack.pop()
                else
                    return false    
            }    
        }

        return stack.length === 0

    }
}
