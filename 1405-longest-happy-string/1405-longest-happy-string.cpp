class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string s = "";
        
        int mini = min(a, min(b,c));
        
        priority_queue < pair <int, char> > pq;
        
        if(a > 0)
        pq.push({a, 'a'});
        if(b > 0)
        pq.push({b, 'b'});
        if(c > 0)
        pq.push({c, 'c'});

        while(!pq.empty())
        {
            auto pp = pq.top();
            pq.pop();
            
            if(s.size() < 2)
            {
                s += pp.second;
                
                pp.first--;
                
                if(pp.first > 0)
                {
                    pq.push(pp);
                }
            }
            else
            {
                int i = s.size()-1;
                if(s[i] == s[i-1] &&  s[i] == pp.second)
                {
                    if(pq.empty())
                        break;
                    
                    auto qq = pq.top();
                    pq.pop();
                    
                    s += qq.second;
                    qq.first--;
                    
                    if(qq.first > 0)
                        pq.push(qq);
                    
                    pq.push(pp);
                }
                else
                {
                    s += pp.second;
                
                    pp.first--;

                    if(pp.first > 0)
                    {
                        pq.push(pp);
                    }
                }
            }
        }
        
        return s;
    }
};