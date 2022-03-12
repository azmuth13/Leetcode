/**
 * @param {number[]} nums
 * @return {number[]}
 */
var runningSum = function(nums) {
    
    let ans = 0;
    let arr = [];
    
    for(let i = 0; i < nums.length; i++)
        {
            ans += nums[i];
            arr[i] = ans;
        }
    
    return arr;
};