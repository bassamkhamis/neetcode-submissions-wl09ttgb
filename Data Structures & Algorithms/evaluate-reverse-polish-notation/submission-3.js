class Solution {
    /**
     * @param {string[]} tokens
     * @return {number}
     */
    is_operator(token) {
        if (token === "+" || token === "-" || token === "*" || token === "/")
            return true
        else
            return false    
    }
    evalRPN(tokens) {
        let stack = []

        for (const token of tokens) {
            if (this.is_operator(token))
            {
                let operand2 = stack.pop()
                let operand1 = stack.pop()
                let res

                if (token === "+")
                    res = operand1 + operand2
                else if (token === "-")
                    res= operand1 - operand2
                else if (token === "*") 
                    res = operand1 * operand2
                else
                    res = Math.trunc(operand1 / operand2)

                stack.push(res)           
            }
            else
                stack.push(parseInt(token))
        }

        return stack[stack.length - 1]
    }
}
