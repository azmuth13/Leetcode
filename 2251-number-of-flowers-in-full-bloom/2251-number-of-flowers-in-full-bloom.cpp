class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& f, vector<int>& p) {
        int n = p.size();
        vector <int> ans(n);
        
        map <int, int> mp;
        
        for(auto &x : f)
        {
            mp[x[0]]++;
            mp[x[1] + 1]--;
        }
        
        set < pair <int, int> > presum;
        
        int sum = 0;
        auto it = mp.begin();
        
        for(auto &x : mp)
        {
            sum += x.second;
            presum.insert({x.first, sum});
        }
        
        for(int i = 0; i < n; i++)
        {
            int val = p[i];
            
           // auto it = lower_bound(presum.begin(), presum.end(), val);
            auto it = presum.lower_bound({val,0});
            if(it != presum.end())
            {
                if(it->first == val)
                {
                    ans[i] = it->second;
                }
                else
                {
                    if(it != presum.begin())
                    {
                        it--;
                        ans[i] = it->second;
                    }
                    else
                    {
                        ans[i] = 0;
                    }
                }
            }
            else
            {
                ans[i] = 0;
            }
        }
        
//         vector <int> v(100001,0);
        
//         for(auto &x : f)
//         {
//             v[x[0]]++;
//             v[x[1] + 1]--;
//         }
//         sum = 0;
//         for(int i = 0; i < 100001; i++)
//         {
//             sum += v[i];
//             v[i] = sum;
//         }
        
//         for(int i = 0; i < n; i++)
//         {
//             ans[i] = v[p[i]];
//         }
        
        return ans;
    }
};