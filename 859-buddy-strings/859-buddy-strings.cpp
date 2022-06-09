class Solution {
public:
    bool buddyStrings(string s, string goal) {
        
        int cnt = 0;
        vector <int> inds;
        bool flag = 0;
        map <char, int> mp;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != goal[i])
            {
                inds.push_back(i);
            }
            else
            {
                mp[s[i]]++;
                if(mp[s[i]] > 1)
                {
                    flag = 1;
                }
            }
        }
        
        if(inds.size() > 2)
            return false;
        
        if(inds.size() == 0 && flag == 1)
            return true;
        else if(inds.size() == 0 && flag == 0)
            return false;
        else if(inds.size() == 1)
            return false;
            
        
        swap(s[inds[0]], s[inds[1]]);
            
        return (s == goal);
    }
};