/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    return s.trim().split(" ").filter(ele=>ele.length>0).reverse().join(" ");
};