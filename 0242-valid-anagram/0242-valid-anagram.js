/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    // step 1 : check if both of the string length is equal or not
    if (s.length !== t.length) return false;

    // take one object for count frequency
    let map = {};


    for (let char of s) {
        // if the char avilabe in object, you can increase the count
        if (map[char]) {
            map[char]++; // count the frequency
        } else { // if char is not avilable in obj then set char : 1
            map[char] = 1;
        }
    }

    for (let char of t) {
        if (!map[char]) {
            return false;
        } else {
            map[char]--;
        }
    }

    // if (map.length > 0) return false;
    return true;
};