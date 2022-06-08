// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class DSU{
    int n;
    vector <int> parent;
    vector <int> size;
    public:

    DSU(int _n)
    {
        n = _n;
        parent.resize(n);
        size.resize(n);
        for(int i = 0; i < n; i++)
            parent[i] = i, size[i] = 1;
    }

    int getParent(int u)
    {
        int par = parent[u];
        if(par == u)
            return u;

        return parent[u] = getParent(par);
    }

    bool merge(int u, int v)
    {
        int pv = getParent(v);
        int pu = getParent(u);

        if(pv == pu)
        {
            // merge nahi hua
            return false;
        }

        if(size[pu] > size[pv])
            swap(pu,pv);

        size[pv] += size[pu];
        parent[pu] = pv;

        // merge ho gaya
        return true;
    }
};


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
            
        int sum = 0;
        
        vector < vector <int> > ed;
        
        for(int i = 0; i < V; i++)
        {
           // cout << i << endl;
            for(auto &x : adj[i])
            {
                // for(auto &y : x)
                // {
                //     cout << y << " ";
                // }
                // cout << endl;
                ed.push_back({x[1],i,x[0]});
            }
            
            //cout << endl;
        }
        sort(ed.begin(), ed.end());
        // for(auto x : ed)
        // {
        //     for(auto y : x)
        //     {
        //         cout << y << " ";
        //     }
        //     cout << endl;
        // }
        
        
        DSU dsu(V);
        int cnt = 0;
        for(int i = 0; i < ed.size(); i++)
        {
            if(cnt == V-1)
            break;
            int wt = ed[i][0];
            int a = ed[i][1];
            int b = ed[i][2];
            
            a = dsu.getParent(a);
            b = dsu.getParent(b);
            
            if(a != b)
            {
                dsu.merge(a,b);
                //cout << a << " " << b << endl;
                sum += wt;
                cnt++;
            }
        }
        
        return sum;
    }

};


// int N = V;
            
            // int parent[N];
            // int key[N];
        
            // bool mstSet[N];
        
            // for(int i = 0; i < N; i++)
            // {
            //     key[i] = INT_MAX, mstSet[i] = false, parent[i] = -1;
            // }
        
            // key[0] = 0;
            // parent[0] = -1;
        
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
        
            // efficient appraoch (prims)
        
            // priority_queue < pair <int, int>, vector < pair <int, int> >,
            // greater <pair <int, int> > > pq;
        
            // pq.push({0, 0});
        
            // while(!pq.empty())
            // {
            //     int u = pq.top().second;
            //     pq.pop();
                
            //     mstSet[u] = true;
            //     for(auto it : adj[u])
            //     {
            //         int v = it[0];
            //         int wt = it[1];
        
            //         if(mstSet[v] == false && wt < key[v])
            //         {
            //             parent[v] = u;
            //             key[v] = wt;
            //             pq.push({key[v], v});
            //         }
            //     }
            // }
            
            // int sum = 0;
            
            // for(int i = 0; i < N; i++)
            // {
            //     // cout << parent[i] << " - " << i << endl;
            //     sum += key[i];
            // }
            
            // return sum;




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