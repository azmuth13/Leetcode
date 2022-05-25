class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& man, vector<int>& informTime) {
        
        
        vector < vector <int> > adj(n);
        for(int i = 0; i < man.size(); i++)
        {
            if(man[i]!=-1)
                adj[man[i]].push_back(i);
        }
        
        queue < pair <int, int> > q;
        q.push({headID, 0});
        int ans = 0;
        while(!q.empty())
        {
            //cout << "YES\n";
            int sz = q.size();
            while(sz--)
            {
                auto pp = q.front();
                q.pop();
                
                int emp = pp.first;
                int cost = pp.second;
                
                ans = max(ans, cost);
                
                for(auto &child : adj[emp])
                {
                    q.push({child, cost + informTime[emp]});
                }
            }
        }
        return ans;
    }
};