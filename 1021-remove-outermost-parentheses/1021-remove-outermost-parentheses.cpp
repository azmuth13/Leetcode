class Solution {
public:
    string removeOuterParentheses(string s) {
        
        string ans = "";
        
        int n = s.size();
        int count = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(')
                count++;
            else
            {
                count--;
            }
            
            if(s[i] == '(' && count == 1)
                continue;
            
            if(s[i] == ')' && count == 0)
                continue;
            
            ans += s[i];
        }
        
        return ans;
    }
};