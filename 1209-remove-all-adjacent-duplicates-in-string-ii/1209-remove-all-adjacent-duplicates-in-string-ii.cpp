class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        string ans = "";
        
        int n = s.size();
        
        int i = 0;
        
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
                    auto pp = st.top();
                    st.pop();
                    pp.second += 1;
                    
                    if(pp.second != k)
                    st.push(pp);
                }
                else
                {
                    st.push({s[i], 1});
                }
            }
        }
        
        while(st.size() > 0)
        {
            auto pp = st.top();
            st.pop();
            ans += string(pp.second, pp.first);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};