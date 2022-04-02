class Solution {
public:
    bool validPalindrome(string s) {
        
        int n = s.size();
        
        int bad = 0;
        
        int start = 0, end = n-1;
        
        while(start < end)
        {
            if(s[start] != s[end])
            {
                int a = start+1, b = end;
                
                int c = start, d = end-1;
                
                int count = 0;
                while(a < b)
                {
                    if(s[a++] != s[b--])
                    {
                        count++;
                        break;
                    }
                }
                
                while(c < d)
                {
                    if(s[c++] != s[d--])
                    {
                        count++;
                        break;
                    }
                }
                
                if(count >= 2)
                    return false;
                
                return true;
            }
            
            start++, end--;
        }
        
        return true;
    }
};