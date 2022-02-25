class Solution {
public:
    
    map <char, int> mp;
    
    struct comp{
        
        map <char, int> mp;
        comp(map <char, int> &mp) { this->mp = mp;}
        
        bool operator()(string &a, string &b)
        {
            for(int i = 0; i < min(a.size(), b.size()); i++)
            {
                if(a[i] != b[i])
                {
                    return mp[a[i]] < mp[b[i]];
                }
            }
            return a.size() < b.size();
        }
    };
    
   
    bool isAlienSorted(vector<string>& words, string order) {
        
        
        for(int i = 0; i < order.size(); i++)
        {
            mp[order[i]] = i;
        }
        
        vector <string> v = words;
        
        sort(v.begin(), v.end(), comp(mp));
        
        return (v==words);
    }
};