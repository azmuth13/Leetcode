class Solution {
public:

    bool validPalindrome(string s) {
        
        int i = 0, j = s.length()-1;
    
        while(i < j)
        {
            if(s[i] == s[j])
            {
                i++, j--;
            }
            else
            {
                int i1 = i, j1 = j-1;
                int i2 = i+1, j2 = j;
                
                while(i1 < j1)
                {
                    if(s[i1] != s[j1])
                        break;
                    
                    i1++, j1--;
                }
                
                while(i2 < j2)
                {
                    if(s[i2] != s[j2])
                        break;
                    
                    i2++, j2--;
                }
                
                return ((i1 >= j1) || (i2 >= j2));
            }
        }
    
        return true;
    }
};