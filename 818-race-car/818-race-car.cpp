class Solution {
public:
    
    int racecar(int target) {
        
        int ans = 0;
        
        queue < pair <int, int> > q;

        unordered_map <string, int> vis;
        
        q.push(make_pair(0,1));
            
        string key = to_string(0) + " " + to_string(1);
        vis[key] = 1;
        
        while(!q.empty())
        {
            int sz = q.size();
            
            while(sz--)
            {
                pair <int, int> pp = q.front();
                q.pop();
                 
                if(pp.first == target)
                {
                    return ans;
                }
                
                // instruction A
                
                if(pp.first + pp.second > 0 && pp.first + pp.second < 2*target)
                {
                    string key = to_string(pp.first + pp.second) + " " + to_string(2*pp.second);
                    if(!vis.count(key))
                    {
                        q.push(make_pair(pp.first + pp.second, pp.second*2));
                        vis[key] = 1;
                    }
                }
                
                
                // instruction R
                
                if(pp.second >= 0)
                {
                    string key = to_string(pp.first) + " " + to_string(-1);
                    if(!vis[key])
                    {
                        q.push(make_pair(pp.first, -1));
                        vis[key] = 1;
                    }
                   
                }
                else
                {
                    string key = to_string(pp.first) + " " + to_string(1);
                    if(!vis[key])
                    {
                        q.push(make_pair(pp.first, 1));
                        vis[key] = 1;
                    }
                    
                }
            }
            
            ans++;
        }
        
        return 0;
    }
};