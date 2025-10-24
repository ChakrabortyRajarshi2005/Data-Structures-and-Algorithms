Convert to Base 7
Accepted
EASY

Tags

Companies

Hints
Given an integer num, your task is to convert it into its base 7 representation and return it as a string. Base 7 numbers use only the digits 0 through 6. This means that after counting to 6, you move to a new column, similar to how base 10 works after the digit 9.

For example, when converting a base 10 number like 20 (imagine Hitesh has 20 candies) to base 7, it would be represented as '26'. Similarly, negative numbers should also be correctly represented in base 7.

The challenge is to convert any integer, positive or negative, into this base 7 form, presented as a string.

Example 1:
Input: num = 100
Output: "202"
Example 2:
Input: num = -7
Output: "-10"
Your task is to implement a function that performs this conversion accurately.

Constraints
num is an integer where -10^7 <= num <= 10^7class Solution {
  convertToBase7(num: number): string {
    if (num === 0) return "0";

    const isNegative = num < 0;
    num = Math.abs(num);

    let result = "";

    while (num > 0) {
      const remainder = num % 7;
      result = remainder.toString() + result;
      num = Math.floor(num / 7);
    }

    if (isNegative) result = "-" + result;

    return result;
  }
}
