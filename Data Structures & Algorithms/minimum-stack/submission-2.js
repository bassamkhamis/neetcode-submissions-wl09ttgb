class MinStack {
    constructor() {
        this.stack = new Array()
        this.stack_min = new Array()
    }

    /**
     * @param {number} val
     * @return {void}
     */
    push(val) {
        this.stack.push(val)
        if (this.stack_min.length !== 0 && this.stack_min[this.stack_min.length - 1] <= val)
            this.stack_min.push(this.stack_min[this.stack_min.length - 1])
        else
            this.stack_min.push(val)    
    }

    /**
     * @return {void}
     */
    pop() {
        this.stack.pop()
        this.stack_min.pop()
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
