/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(arr) {
    let n = arr.length;
    let sum = 0;

    for (let val of arr) sum += val;

    let actualSum = (n * (n + 1)) / 2;

    return actualSum - sum;
};