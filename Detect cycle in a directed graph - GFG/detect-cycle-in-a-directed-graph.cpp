// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool dfs(vector < int> adj[], vector <int> &vis, vector <int> &dfsVis, int i)
    {
        
        vis[i] = 1;
        dfsVis[i] = 1;

        for(auto &neigh : adj[i])
        {
            if(!vis[neigh])
            {
                if(dfs(adj,vis,dfsVis,neigh))
                    return true;
            }
            else if(dfsVis[neigh])
            {
                return true;
            }
        }
    
        dfsVis[i] = 0;
        return false;
    }


    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int A = V;
        vector <int> vis(A+1,0);
        vector <int> dfsVis(A+1,0);
        
        for(int i = 0; i < A; i++)
        {
            if(!vis[i])
            {
                bool res = dfs(adj, vis, dfsVis, i);
                if(res)
                return true;
            }
        }
        return 0;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends