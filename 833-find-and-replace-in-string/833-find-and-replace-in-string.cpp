class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        
        int n = s.size();
        
        set <int> st;
        int sz = indices.size();
        map <int, pair <string, string> > mp;
        for(int k = 0; k < sz; k++)
        {
            int i = indices[k];
            int j = 0;
            while(i < n && s[i] == sources[k][j])
            {
                i++;
                j++;
            }
            if(j == sources[k].size())
                mp[indices[k]] = {targets[k], sources[k]};
        }
        
        // for(auto x : mp)
        // {
        //     cout << x.first << ' ' << x.second << endl;
        // }
        string ans = "";
        
        for(int i = 0; i < n; i++)
        {
            if(mp.find(i) != mp.end())
            {
                //cout << i << endl;
                ans += mp[i].first;
                i+= mp[i].second.size();
                i--;
            }
            else
            {
                ans += s[i];
            }
        }
        return ans;
    }
};