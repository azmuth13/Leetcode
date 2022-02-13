class Solution {
public:
    
    bool present(vector <int> &a, int l)
    {
        return (upper_bound(a.begin(), a.end(), l) != a.end());
    }
    
    string removeDuplicateLetters(string s) {
        
        map <char, vector <int> > mp;
        int n = s.size();
        
        for(int i = 0; i < n; i++)
        {
            mp[s[i]].push_back(i);
        }
        
        set <char> st;
        
        stack <char> stk;
        
        st.insert(s[0]);
        stk.push(s[0]);
        
        
       

        for(int i = 1; i < n; i++)
        {
            if(st.find(s[i]) != st.end())
                continue;

            while(!stk.empty() && (s[i] < stk.top() && present(mp[stk.top()],i)))
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