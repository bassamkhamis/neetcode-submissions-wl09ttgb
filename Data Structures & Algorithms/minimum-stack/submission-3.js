class MinStack {
    constructor() {
        this.stack = new Array()
        this.stack_min = new Array() // keeps only the min value
    }

    /**
     * @param {number} val
     * @return {void}
     */
    push(val) {
        this.stack.push(val)

        if (this.stack_min.length === 0 || this.stack_min[this.stack_min.length - 1] >= val)
            this.stack_min.push(val)   
    }

    /**
     * @return {void}
     */
    pop() {
        let top = this.stack[this.stack.length - 1]

        if (top === this.stack_min[this.stack_min.length - 1])
            this.stack_min.pop()

        this.stack.pop()
    }

    /**
     * @return {number}
     */
    top() {
        return this.stack[this.stack.length - 1]
    }

    /**
     * @return {number}
     */
    getMin() {

        return this.stack_min[this.stack_min.length - 1]
    }
}
