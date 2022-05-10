class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        
        int n = queries.size();
        int sz = s.size();
        
        vector <vector <int> > pre(sz, vector <int>(26,0));
        
        pre[0][s[0] - 'a'] = 1;
        
        for(int i = 1; i < sz; i++)
        {
            for(int j = 0; j < 26; j++)
            {
                pre[i][j] += pre[i-1][j];
            }
            
            pre[i][s[i] - 'a'] += 1;
        }
        
        vector <bool> ans(n);
        
        for(int i = 0; i < n; i++)
        {
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            int cnt = 0;
            
            if(l == 0)
            {
                for(int j = 0; j < 26; j++)
                {
                    int val = pre[r][j];
                    //cout << val << " ";

                    if(val&1)
                        cnt++;
                }
                
                if(cnt/2 <= k)
                    ans[i] = 1;
            }
            else
            {
                for(int j = 0; j < 26; j++)
                {
                    int val = pre[r][j] - pre[l-1][j] ;
                   // cout << val << " ";
                    if(val&1)
                        cnt++;
                }
                
                if(cnt/2 <= k)
                    ans[i] = 1;
            }
            //cout << endl;
        }
        
        return ans;
    }
};