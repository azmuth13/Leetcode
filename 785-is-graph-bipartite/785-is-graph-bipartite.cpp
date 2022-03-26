class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
    
    int n = graph.size();

    vector <int> col(n+1, 0);

    queue <int> q;

    for(int i = 0; i < n; i++)
    {
        if(col[i])
        continue;
        
        col[i] = 1;

        q.push(i);

        while(!q.empty())
        {
            int pp = q.front();
            q.pop();

            for(auto x : graph[pp])
            {
                if(col[x] == 0)
                {
                    col[x] = -1*col[pp];
                    q.push(x);
                }
                else
                {
                    if(col[pp] == col[x])
                    return false;
                }
               
            }
        }
    }

    return 1;
}
    
};