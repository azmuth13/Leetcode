class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        
        vector < vector <int> > adj(n);
        
        for(int i = 0; i < n; i++)
        {
            if(edges[i] == -1) continue;
            adj[i].push_back(edges[i]);
        }
        
        vector <int> dis1(n,2e9), dis2(n,2e9);
        
        queue <int> q;
        q.push(node1);
        dis1[node1] = 0;
        int lvl = 0;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                int tp = q.front();
                q.pop();
                
                dis1[tp] = lvl;
                
                for(auto &neigh : adj[tp])
                {
                    if(dis1[neigh] != 2e9) continue;
                    q.push(neigh);
                }
            }
            lvl++;
        }
        
        while(!q.empty())
            q.pop();
        
        q.push(node2);
        dis2[node2] = 0;
        lvl = 0;
        
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                int tp = q.front();
                q.pop();
                
                dis2[tp] = lvl;
                
                for(auto &neigh : adj[tp])
                {
                    if(dis2[neigh] != 2e9) continue;
                    q.push(neigh);
                }
            }
            lvl++;
        }
        int ans = 2e9;
        int node = -1;
        
        for(int i = 0; i < n; i++)
        {
            int maxi = max(dis1[i], dis2[i]);
            if(maxi < ans)
            {
                ans = maxi;
                node = i;
            }
        }
        return node;
    }
};