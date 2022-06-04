class Solution {
public:
    
    int find(vector < pair < pair <int, int> , int> > &v, int i)
    {
        
        int ind = -1;
        
        int left = 0, right = i;
        
        while(left <= right)
        {
            int mid = (left + right)/2;
            
            if(v[mid].first.first <= v[i].first.second)
            {
                ind = mid;
                left = mid+1;
            }
            else
            {
                right = mid-1;
            }
        }
        
        return ind;
    }
    
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        
        int sz = rides.size();
        vector <long long> ans(sz+1,0);
        vector < pair < pair <int, int>, int > > v(sz);
        for(int i = 0; i < sz; i++)
        {
            v[i] = {{rides[i][1],rides[i][0]}, rides[i][1] - rides[i][0] + rides[i][2]};
        }
        
        sort(v.begin(),v.end());
        
        ans[0] = v[0].second;
        
        for(int i = 1; i < sz; i++)
        {
            ans[i] = ans[i-1];
            // find the index before i lets say k such that start[i] >= end[ind]
            // k < ind
            int ind = find(v,i);
            
            if(ind == -1)
            {
                ans[i] = max(ans[i], (long long)v[i].second);
            }
            else
            {
                ans[i] = max(ans[i], ans[ind] + (long long)v[i].second);
            }
        }
        
        return ans[sz-1];
    }
};