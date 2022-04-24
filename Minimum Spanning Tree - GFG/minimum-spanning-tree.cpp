// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
            int N = V;
            
            int parent[N];
            int key[N];
        
            bool mstSet[N];
        
            for(int i = 0; i < N; i++)
            {
                key[i] = INT_MAX, mstSet[i] = false, parent[i] = -1;
            }
        
            key[0] = 0;
            parent[0] = -1;
        
            /*
            brute appraoch
        
            for(int count = 0; count < N-1; count++)
            {
                // edges times
                int mini = INT_MAX, u;
                
                // mini stores weight
                // u is the node associated with that weight
        
                for(int v = 0; v < N; v++)
                {
                    if(mstSet[v] == false && key[v] < mini)
                    {
                        mini = key[v], u = v;
                    }
                }
        
                // found the node with minimum weight
                // added that node in the MST
        
                mstSet[u] = true;
        
                // visited all the neighbours of that node
                for(auto it : adj[u])
                {
                    int v = it.first;
                    int wt = it.second;
                    // if not already present in the MST and its weight is less than what is in the key array
                    // update its parent and key value, very similar to dijkstra
                    
                    if(mstSet[v] == false && wt < key[v])
                        parent[v] = u, key[v] = wt;
                }
            }
        
            */
        
            // efficient appraoch
        
            priority_queue < pair <int, int>, vector < pair <int, int> >, greater <pair <int, int> > > pq;
        
            pq.push({0, 0});
        
            while(!pq.empty())
            {
                int u = pq.top().second;
                pq.pop();
                
                mstSet[u] = true;
                for(auto it : adj[u])
                {
                    int v = it[0];
                    int wt = it[1];
        
                    if(mstSet[v] == false && wt < key[v])
                    {
                        parent[v] = u;
                        key[v] = wt;
                        pq.push({key[v], v});
                    }
                }
            }
            
            int sum = 0;
            
            for(int i = 0; i < N; i++)
            {
                // cout << parent[i] << " - " << i << endl;
                sum += key[i];
            }
            
            return sum;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends