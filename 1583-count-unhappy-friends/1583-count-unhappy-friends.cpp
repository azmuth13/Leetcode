class Solution {
public:
    
    int prefScore(int a, int b, vector<vector<int>>& pref)
    {
        for(int i = 0; i < pref[a].size(); i++)
        {
            if(pref[a][i] == b)
            {
                return i;
            }
        }
        return 1e9;
    }
    
    int unhappyFriends(int n, vector<vector<int>>& pref, vector<vector<int>>& pairs) {
        
        int ans = 0;
        int sz = pairs.size();
        set <int> st;
        for(int i = 0; i < sz; i++)
        {
            for(int j = i+1; j < sz; j++)
            {
                if(i==j) continue;
                
                int x = pairs[i][0];
                int y = pairs[i][1];
                
                int u = pairs[j][0];
                int v = pairs[j][1];
                
                int a = (prefScore(x,u,pref) < prefScore(x,y,pref) && 
                  prefScore(u,x,pref) < prefScore(u,v,pref));
                
                if(a)
                {
                    //cout << x << " " << u << endl;
                    st.insert(x);
                    st.insert(u);

                }
                
                int b = (prefScore(x,v,pref) < prefScore(x,y,pref) && 
                  prefScore(v,x,pref) < prefScore(v,u,pref));
                
                if(b)
                {
                    //cout << x << " " << v << endl;
                    st.insert(x);
                    st.insert(v);
                }
                
                int c = (prefScore(y,u,pref) < prefScore(y,x,pref) && 
                  prefScore(u,y,pref) < prefScore(u,v,pref));
                
                if(c)
                {
                    //cout << y << " " << u << endl;
                    st.insert(y);
                    st.insert(u);
                }
                
                int d = (prefScore(y,v,pref) < prefScore(y,x,pref) && 
                  prefScore(v,y,pref) < prefScore(v,u,pref));
                
                if(d)
                {
                    //cout << y << ' ' << v << endl;
                    st.insert(y);
                    st.insert(v);
                }
                
                // if((prefScore(x,u,pref) < prefScore(x,y,pref) && 
                //   prefScore(u,x,pref) < prefScore(u,v,pref))
                //    ||
                //   (prefScore(x,v,pref) < prefScore(x,y,pref) && 
                //   prefScore(v,x,pref) < prefScore(v,u,pref)))
                // {
                //     ans++;
                // }
                // else if((prefScore(y,u,pref) < prefScore(y,x,pref) && 
                //   prefScore(u,y,pref) < prefScore(u,v,pref))
                //    ||
                //   (prefScore(y,v,pref) < prefScore(y,x,pref) && 
                //   prefScore(v,y,pref) < prefScore(v,u,pref)))
                // {
                //     ans++;
                // }
            }
        }
        return (int)st.size();
    }
};