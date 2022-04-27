class Solution {
public:
    
struct DSU{

    vector <int> parent, size;

    // make_set
    DSU(int n)
    {
        parent = vector <int> (n);
        size = vector <int> (n, 1);

        for(int i=0; i<n; i++)
        {
            parent[i] = i;
        }
    }

    // find_set
    int find_set(int a)
    {
        if(a == parent[a])
        {
            return a;
        }
        parent[a] = find_set(parent[a]);

        return find_set(parent[a]);
    }

    // union_set (by size)
    void union_set(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);

        if(a != b)
        {
            if(size[a] < size[b])
            {
                swap(a,b);
            }

            size[a] += size[b];
            parent[b] = a;
        } 
    }
};

    
    vector<bool> friendRequests(int n, vector<vector<int>>& res, vector<vector<int>>& req) {
        
        DSU dsu(n);
        
        int sz = req.size();
        vector <bool> ans(sz,0);
        
        for(int i = 0; i < sz; i++)
        {
            int u = dsu.find_set(req[i][0]);
            int v = dsu.find_set(req[i][1]);
            
            bool flag = true;
            
            if(u != v)
            for(auto &x : res)
            {
                int e1 = dsu.find_set(x[0]), e2 = dsu.find_set(x[1]);
                
                if((e1 == u && e2 == v) || (e1 == v && e2 == u))
                {
                    flag = false;
                    break;
                }
            }
            
            if(flag)
            {
                ans[i] = flag;
                dsu.union_set(u, v);
            }
        }
        
        return ans;
    }
};