class Solution {
public:
    
    bool present(vector <int> &v, int i)
    {
        return (upper_bound(v.begin(), v.end(), i) != v.end());
    }
    
    string smallestSubsequence(string s) {
        
        int n = s.length();
        
        map <char, vector <int> > mp;
        
        for(int i = 0; i < n; i++)
        {
            mp[s[i]].push_back(i);
        }
        
        stack <char> stk;
        set <char> st;
        st.insert(s[0]);
        
        stk.push(s[0]);
        
        for(int i = 1; i < n; i++)
        {
            if(st.count(s[i]))
                continue;
            
            while(!stk.empty() && stk.top() > s[i] && present(mp[stk.top()], i))
            {
                st.erase(stk.top());
                stk.pop();
            }
            
            st.insert(s[i]);
            stk.push(s[i]);
        }
        
        string ans = "";
        
        while(!stk.empty())
        {
            ans += stk.top();
            stk.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};