class Solution {
public:
    
    map <char, int> mp;
    
    struct comp{
        
        map <char, int> mp;
        comp(map <char, int> &mp) { this->mp = mp;}
        
        bool operator()(char a, char b)
        {
            return mp[a] < mp[b];
        }
    };
    
    string customSortString(string order, string s) {
        
        for(int i = 0; i < order.size(); i++)
        {
            mp[order[i]] = i;
        }
        
        sort(s.begin(), s.end(), comp(mp));
        return s;
    }
};