class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& man, vector<int>& informTime) {
        vector < vector <int> > adj(n);
        for(int i = 0; i < man.size(); i++)
        {
            if(man[i]==-1) continue;
            
            adj[man[i]].push_back(i);
        }
        queue < pair <int, int> > q;
        q.push({headID, 0});
        int ans = 0;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto pp = q.front();
                q.pop();
                
                int emp = pp.first;
                int cost = pp.second;
                
                if(ans < cost)
                    ans = cost;
                
                for(auto &child : adj[emp])
                {
                    q.push({child, cost + informTime[emp]});
                }
            }
        }
        return ans;
    }
};