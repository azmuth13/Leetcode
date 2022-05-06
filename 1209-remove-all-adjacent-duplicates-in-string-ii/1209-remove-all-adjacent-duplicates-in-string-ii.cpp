class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        string ans = "";
        
        int n = s.size();
        
        stack <pair <char, int> > st;
        
        for(int i = 0; i < n; i++)
        {
            if(st.empty())
            {
                st.push({s[i], 1});
            }
            else
            {
                if(s[i] == st.top().first)
                {
                    // auto pp = st.top();
                    // st.pop();
                    st.top().second += 1;
                    
                    if(st.top().second == k)
                    st.pop();
                }
                else
                {
                    st.push({s[i], 1});
                }
            }
        }
        
        while((int)st.size())
        {
            ans += string(st.top().second, st.top().first);
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};