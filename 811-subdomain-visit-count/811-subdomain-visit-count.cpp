class Solution {
public:
    
    void trimS(string &res)
    {
        
        while(res.size() > 0 && (res.back() == ' ' || res.back() == '\0'))
        {
            res.pop_back();
        }
    }
    
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map <string, int> mp;
        
        for(auto &x : cpdomains)
        {
            int sz = x.size();
            int num = 0;
            int i = 0;
            while(i < sz && x[i] != ' ')
            {
                num = num*10 + x[i]-'0';
                i++;
            }
            
            i++;
            string res = "";
            while(i < sz && x[i] != '.')
            {
                res += x[i];
                i++;
            }
            res += x[i];
            string res2 = "";
            i++;
            while(i < sz && x[i] != '.')
            {
                res2 += x[i];
                res += x[i];
                i++;
            }
            res += x[i];
            res2 += x[i];
            string res3 = "";
            i++;
            
            while(i < sz)
            {
                res += x[i];
                res2 += x[i];
                res3 += x[i];
                i++;
            }
        
            trimS(res); trimS(res2); trimS(res3);
            
            // cout << res <<'-' << res2 <<'-' << res3 << endl;
            if(res != "")
            {
                mp[res]+=num;
            }
            
            if(res2 != "")
            {
                mp[res2]+=num;
            }
            
            if(res3 != "")
            {
                mp[res3]+=num;
            }
        }
        vector <string> ans;
        
        for(auto &x : mp)
        {
            // cout << x.first << '-' << x.second << endl;
            string res = "";
            res += to_string(x.second);
            res += ' ';
            res += x.first;
            ans.push_back(res);
        }
        return ans;
    }
};