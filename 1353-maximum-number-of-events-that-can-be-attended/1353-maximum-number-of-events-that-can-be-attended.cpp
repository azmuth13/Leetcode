class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        
        int n = events.size();
        
        sort(events.begin(),events.end());
        int k = 0;
        
        priority_queue < pair <int, int> , vector < pair <int, int>  >, 
        greater < pair <int, int>  > > pq;
        int ans = 0;
        
        for(int d = 1; d <= 100000; d++)
        {
            while(!(pq.empty()) && (pq.top().first < d))
            {
                //cout << pq.size() << endl;
                //cout << "YES\n";
                pq.pop();
            }
                
            // cout << endl;
            while(k < n && events[k][0] <= d)
            {
                pq.push({events[k][1],events[k][0]});
                k++;
            }
            
            if(!pq.empty() && pq.top().first >= d)
            {
                pq.pop();
                ans++;
            }
        }
        
        return ans;
    }
};