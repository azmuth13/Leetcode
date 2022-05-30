class Solution {
public:
    
    int find(vector < pair <pair <int, int>,int> > &v, int n)
    {
        // need to find the rightmost index where v[n].startTime >= v[i].endTime
        
        int l = 0, r = v.size()-1;
        int ans = -1;
        while(l <= r)
        {
            int mid = (l+r)/2;
            
            if(v[n].first.second >= v[mid].first.first)
            {
                ans = mid;
                l = mid+1;
            }
            else
            {
                r = mid-1;
            }
        }
        return ans;
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int n = startTime.size();
        vector < pair < pair <int, int>  , int> > v(n);
        
        for(int i = 0; i < n; i++)
        {
            v[i] = {{endTime[i],startTime[i]},profit[i]};
        }
        
        sort(v.begin(),v.end());
        
        int dp[n+1];
        
        dp[0] = v[0].second;
        int ans = 0;
        for(int i = 1; i < n; i++)
        {
            dp[i] = dp[i-1];
            
            int ind = find(v, i);
            
            if(ind == -1)
            {
                dp[i] = max(dp[i], v[i].second);
            }
            else
            {
                dp[i] = max(dp[i], dp[ind] + v[i].second);
            }
            
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};