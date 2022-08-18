class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        int n = arr.size();
        
        map <int, int> mp;
        
        for(int i=0; i<n; i++)
        {
            mp[arr[i]]++;
        }
        
        vector <pair <int, int> > vp;
        
        for(auto x : mp)
        {
            vp.emplace_back(x.second, x.first);
        }
        
        sort(vp.rbegin(), vp.rend());
        
        int sz = vp.size();
        int count = 0;
        
        int i=0;
        int ans = 0;
        while(1)
        {
            count += vp[i++].first;
            ans++;
            if(count>=n/2)
                break;
        }
        
        return ans;
    }
};