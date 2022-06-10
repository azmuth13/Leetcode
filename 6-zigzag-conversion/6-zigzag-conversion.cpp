class Solution {
public:
    string convert(string s, int n) {
        
        int sz = s.size();
        if(n == 1)
            return s;
        
        vector < vector <char> > ans(n);
        
        int cnt = 0;
        int crem = -1;
        for(int i = 0; i < sz; i++)
        {
           // cout << cnt << endl;
            if(cnt == 0)
                crem*=(-1);
            
            if(cnt == n-1)
                crem*=(-1);
            
            ans[cnt].push_back(s[i]);
                
            cnt += crem;
        }
        
        string res = "";
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < ans[i].size(); j++)
                res += ans[i][j];
        }
        
        return res;
    }
};