class Solution {
public:
    
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        
        int ans = 0;
        int sN = 0;
        stations.push_back({target,0});
        priority_queue <int> pq;
        int len = stations.size();
        int pos = startFuel;
        while(pos < target)
        {
            while(sN < len && pos >= stations[sN][0])
            {
                pq.push(stations[sN][1]);
                sN++;
            }
            
            while(pq.size() > 0 && stations[sN][0] > pos)
            {
                pos += pq.top();
                pq.pop();
                ans++;
            }
            
            if(stations[sN][0] > pos)
                return -1;
        }
        return ans;
    }
};