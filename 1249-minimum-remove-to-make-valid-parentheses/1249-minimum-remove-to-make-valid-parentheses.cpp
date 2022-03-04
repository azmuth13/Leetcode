class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        int n = s.length();
        
        stack <int> st;
        
        int i = 0;
        while(i < n)
        {
            if(s[i] == '(')
            {
                st.push(i);
            }
            else if(s[i] == ')')
            {
                if(st.empty() || s[st.top()] != '(')
                {
                    st.push(i);
                }
                else
                {
                    st.pop();
                }
            }
            i++;
        }
        
        string ans = "";
        
        for(int j = n-1; j >= 0; j--)
        {
            if(st.size() && j == st.top())
            {
                st.pop();
            }
            else
            {
                ans += s[j];
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};