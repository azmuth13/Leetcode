// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    
	    queue <int> q;
	    //q.push(0);
	    
	    int col[V];
	    for(int i = 0; i < V; i++)
	    col[i] = -1;
	    
	    for(int i = 0; i < V; i++)
	    {
	        if(col[i] == -1)
	        {
	            q.push(i);
	            col[i] = 0;
	            
	            while(!q.empty())
	            {
	                int v = q.front();
	                q.pop();
	                
	                for(auto x : adj[v])
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

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends