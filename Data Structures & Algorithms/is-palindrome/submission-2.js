class Solution {
    /**
     * @param {string} s
     * @return {boolean}
     */
    isPalindrome(s) {

        const is_alphanumeric  = (ch) => (ch >= "a" && ch <= "z" || ch >= "A" && ch <= "Z" || ch >= "0" && ch <= "9")

        let left = 0
        let right = s.length - 1

        while(left < right)
        {
            while (left < right && !is_alphanumeric(s.charAt(left)))
                left++

            while (left < right && !is_alphanumeric(s.charAt(right)))
                right--

            if (s.charAt(left).toLowerCase() !== s.charAt(right).toLowerCase())
                return false 

            left++
            right--           
        }

        return true 
    }
}
