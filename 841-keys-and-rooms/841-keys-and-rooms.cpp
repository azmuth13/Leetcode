class Solution {
public:
    void dfs(int src, vector<vector<int>>& rooms, vector <int> &vis)
    {
        vis[src] = 1;
        
        for(int i = 0; i < rooms[src].size(); i++)
            if(!vis[rooms[src][i]])
                dfs(rooms[src][i],rooms,vis);
        
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n = rooms.size();
        
        vector <int> vis(n,0);
        
        dfs(0,rooms,vis);
        
        for(int i = 0; i < n; i++) 
            if(vis[i]==0) return false; return true;
    }
};