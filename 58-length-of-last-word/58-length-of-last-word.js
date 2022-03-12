/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    
    let len = 0;
    let flag = 0;
    
    for(let i = s.length-1; i >=0; i--)
        {
            if(s[i] === ' ' && flag === 1)
                {
                    break;
                }
            else if(s[i] !== ' ')
                {
                    flag = 1;
                    len++;
                }
        }
    
    return len;
};