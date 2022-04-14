class Solution {
public:
    string pushDominoes(string dominoes) {
        
        int n = dominoes.size();
        
        queue < pair <int, char> > q;
        
        for(int i = 0; i < n; i++)
        {
            if(dominoes[i] == 'R')
            {
                q.push({i, 'R'});
            }
            else if(dominoes[i] == 'L')
            {
                q.push({i, 'L'});
            }
        }
        
        
        
        while(!q.empty())
        {
            int sz = q.size();
            set <int> L, R, N;
            while(sz--)
            {
                auto pp = q.front();
                q.pop();
                int i = pp.first;
                if(pp.second == 'R')
                {
                    if(i+1 < n && dominoes[i+1] == '.')
                    {
                        if(L.find(i+1) != L.end())
                        {
                            L.erase(i+1);
                            N.insert(i+1);
                        }
                        else
                        {
                            R.insert(i+1);
                            q.push({i+1, 'R'});
                        }
                    }
                }
                else if(pp.second == 'L')
                {
                    
                    
                    if(i-1 >= 0 && dominoes[i-1] == '.')
                    {
                        if(R.find(i-1) != R.end())
                        {
                            R.erase(i-1);
                            N.insert(i-1);
                        }
                        else
                        {
                            L.insert(i-1);
                            q.push({i-1, 'L'});
                        }
                    }
                }
            }
            for(auto x : L)
            dominoes[x] = 'L';
        
            for(auto x : R)
            dominoes[x] = 'R';
        }
        
        
        return dominoes;
    }
};