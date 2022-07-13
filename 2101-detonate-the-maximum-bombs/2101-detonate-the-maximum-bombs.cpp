class Solution {
public:
    
    bool inRange(vector <int> &a, vector <int> &b)
    {
        long long x1 = a[0], y1 = a[1], r1 = a[2];
        
        long long x = b[0], y = b[1];
        
        if((x-x1)*(x-x1) + (y-y1)*(y-y1) <= r1*r1)
            return true;
        return false;
    }
    
    int bfs(vector < vector <int> > &adj, int src, int n)
    {
        queue <int> q;
        q.push(src);
        
        int cnt = 1;
        vector <int> vis(n,0);
        vis[src] = 1;
        
        while(!q.empty())
        {
            int sz = q.size();
            
            while(sz--)
            {
                int det = q.front();
                q.pop();
                
                for(auto &neigh : adj[det])
                {
                    if(!vis[neigh])
                    {
                        vis[neigh] = 1;
                        cnt++;
                        q.push(neigh);
                    }
                }
            }
        }
        return cnt;
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector < vector <int> > adj(n);
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i==j) continue;
                if(inRange(bombs[i], bombs[j]))
                {
                    adj[i].push_back(j);
                }
            }
        }
        
        int ans = 1;
        
        for(int i = 0; i < n; i++)
        {
            int res = bfs(adj,i, n);
            ans = max(ans, res);
        }
        return ans;
    }
};