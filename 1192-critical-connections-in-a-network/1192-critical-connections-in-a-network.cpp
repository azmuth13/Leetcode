class Solution {
public:
    int timer = 0;
    vector <vector<int>> result;
int helper(vector<vector<int>>& graph, int now, int prev, vector <int> &disc, vector <int> &low)
{
    timer++;
    
    disc[now] = timer;
    low[now] = timer;

    int ans = 0;

    for(auto &x : graph[now])
    {
        if(!disc[x])
        {
            ans += helper(graph,x,now,disc,low);
            low[now] = min(low[now],low[x]);
        }
        else if(x != prev)
        {
            low[now] = min(low[now],low[x]);
        }

        if(low[x] > disc[now])
        {
            ans++;
            result.push_back({x,now});
        }
    }

    return ans;
}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& c) {
        
        timer = 0;

        vector <vector <int> > graph(n);
        for(auto x : c)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }

        vector <int> disc(n,0), low(n,0);

        int ans = helper(graph,0,-1,disc,low);
        return result;
    }
};