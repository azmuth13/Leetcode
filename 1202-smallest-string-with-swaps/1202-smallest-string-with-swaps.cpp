class Solution {
public:
    
    void dfs(vector <vector <int> > &adj, int src, vector <int> &help, vector <int> &vis, string &s)
    {
        vis[src] = 1;
        
        help.push_back(src);
        
        for(auto j : adj[src])
        {
            if(!vis[j])
            {
                dfs(adj, j, help, vis, s);
            }
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {  
        int n = pairs.size();
        
        int sz = s.size();
        
        vector < vector <int> > adj(sz+1);
        for(auto x : pairs)
        {
            int i = x[0];
            int j = x[1];
            
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
        
        vector <int> vis(sz+1, 0);
        
        string ans = string(sz,' ');
        
        for(int i = 0; i < sz; i++)
        {
            if(!vis[i])
            {
                vector <int> help;
                
                dfs(adj, i, help, vis, s);
                
                string res = "";
                
                for(auto y : help)
                {
                    //cout << y << " ";
                    res += s[y];
                }
                //cout << endl;
                sort(res.begin(), res.end());
                sort(help.begin(), help.end());
                int v = 0;
                for(auto y : help)
                {
                    ans[y] = res[v++];
                }
            }
        }
        
        return ans;
    }
};
