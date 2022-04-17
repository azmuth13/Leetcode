class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        vector <int> col(n, -1);
        queue <int> q;
        
        for(int i = 0; i < n; i++)
        {
            if(col[i] == -1)
            {
                q.push(i);
                col[i] = 0;
                
                while(!q.empty())
                {
                    int v = q.front();
                    q.pop();
                    
                    for(auto x : graph[v])
                    {
                        if(col[x] == -1)
                        {
                            col[x] = 1 - col[v];
                            q.push(x);
                        }
                        else if(col[x] == col[v])
                        {
                            return false;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};