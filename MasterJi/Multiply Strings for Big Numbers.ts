Multiply Strings for Big Numbers
Accepted
MEDIUM

Tags

Companies

Hints
Given two numbers as strings s1 and s2, calculate their product as a string. The numbers in the strings can be positive or negative and may include leading zeros.

Examples:
Example 1:

Input: s1 = "0033", s2 = "2"
Output: "66"
Explanation: 33 * 2 = 66
Example 2:

Input: s1 = "11", s2 = "23"
Output: "253"
Explanation: 11 * 23  = 253
Example 3:

Input: s1 = "123", s2 = "0"
Output: "0"
Explanation: Anything multiplied by 0 is equal to 0.
Note: You should implement the multiplication without directly converting the input strings into big integers using any built-in methods. Keep in mind the signs of the numbers and handle the sign of the result accordingly. The result should also not contain any leading zeros unless the product is exactly zero.

Constraints
The lengths of the input strings can be up to 2000 characters.

The input strings represent valid integers including positive and negative signs.class Solution {
    multiplyStrings(s1: string, s2: string): string {
        const trimZeros = (str: string): string => str.replace(/^0+/, '') || "0";

        let negative = false;
        if (s1[0] === '-') {
            negative = !negative;
            s1 = s1.slice(1);
        }
        if (s2[0] === '-') {
            negative = !negative;
            s2 = s2.slice(1);
        }

        s1 = trimZeros(s1);
        s2 = trimZeros(s2);

        if (s1 === "0" || s2 === "0") return "0";

        const n1 = s1.length;
        const n2 = s2.length;
        const product: number[] = new Array(n1 + n2).fill(0);

        for (let i = n1 - 1; i >= 0; i--) {
            const digit1 = s1.charCodeAt(i) - 48;
            for (let j = n2 - 1; j >= 0; j--) {
                const digit2 = s2.charCodeAt(j) - 48;
                const sum = product[i + j + 1] + digit1 * digit2;
                product[i + j + 1] = sum % 10;
                product[i + j] += Math.floor(sum / 10);
            }
        }

        let result = product.join('').replace(/^0+/, '');
        if (negative) result = "-" + result;

        return result;
    }
}
