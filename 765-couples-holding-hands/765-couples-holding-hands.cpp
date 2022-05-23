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
        return parent[a] = find_set(parent[a]);

        //return find_set(parent[a]);
    }

    // union_set (by size)
    bool union_set(int a, int b)
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
            return true;
        } 
        return false;
    }


};

    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        DSU dsu(n);
        int ans = 0;
        for(int i = 0; i < n; i+=2)
        {
            dsu.union_set(row[i],row[i+1]);
        }
        
        for(int i = 0; i < n; i+=2)
        {
            if(dsu.union_set(i,i+1))
            {
                ans++;
            }
        }
        return ans;
    }
};