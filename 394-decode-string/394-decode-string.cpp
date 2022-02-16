class Solution {
public:
    
    void helper(string s, string &ans, int i)
    {
        if(i >= s.length())
            return;
        
        if(s[i] == ']')
            return;
        
        while(i < s.length() && s[i] >= 97 && s[i] <= 122)
            ans += s[i++];
        
        if(s[i] == ']')
            return;
        
        int num = 0;
        while(i < s.length() && s[i] >= 48 && s[i] <= 57)
        {
            num = num*10 + (s[i] - '0');
            i++;
        }
        
        i++;
        
        for(int k=0; k<num; k++)
        {
            helper(s, ans, i);
        }
        
        while(i < s.length() && s[i] != ']')
            i++;
        
        i++;
        helper(s, ans, i);
    }
    
    string decodeString(string s) {
        
        string ans = "";
        int n = s.length();
        
        stack <char> st;
        
        for(int i = 0; i < n; i++)
        {
            if(s[i] != ']')
            {
                st.push(s[i]);
            }
            else
            {
                string res = "";
                while(st.top()!='[')
                {
                    res += st.top();
                    st.pop();
                }
                st.pop();
                
                // extract the number
                
                string NN = "";
                while(st.size() > 0 && st.top() >= 48 && st.top() <= 57)
                {
                    NN += st.top();
                    st.pop();
                }
                
                reverse(NN.begin(), NN.end());
                int num = stoi(NN);

                reverse(res.begin(), res.end());
                string newRes = "";
                while(num--)
                {
                    newRes += res;
                }
                
                for(int k = 0; k < newRes.size(); k++)
                {
                    st.push(newRes[k]);
                }
            }
        }
        
        while(st.size() > 0)
        {
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};