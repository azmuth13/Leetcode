class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& q) {
        int n = s.size();
        
        vector <int> pref(n,0);
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '*')
                cnt++;
            pref[i] = cnt;
        }
        
        vector <int> pos;
        
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '|')
                pos.push_back(i);
        }
        
        // r-l
        int sz = q.size();
        vector <int> ans(sz,0);
        if(pos.size() == 0)
            return ans;
        for(int k = 0; k < sz; k++)
        {   
            int l = q[k][0], r = q[k][1];
            
            auto itr = upper_bound(pos.begin(),pos.end(),r);
            if(itr == pos.begin()) continue;
            itr--;
                    

            auto itl = lower_bound(pos.begin(),pos.end(),l);
            if(itl == pos.end()) continue;
            int lDash = *itl;
            
            int rDash = *itr;
            
            if(lDash < l || rDash < l || lDash > r) continue;
            
            if(rDash >= lDash)
            {
                ans[k] = pref[rDash]-((lDash > 0)?pref[lDash-1]:0);
            }
        }
        return ans;
    }
};