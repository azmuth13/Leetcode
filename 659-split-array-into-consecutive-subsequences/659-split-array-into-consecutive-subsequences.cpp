class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
        map <int, int> mp, end;
        
        for(auto x : nums)
        {
            mp[x]++;
        }
        
        for(auto x : nums)
        {
            int val = x;
            
            if(mp[val] == 0)
                continue;
            
            if(end[val-1] > 0)
            {
                end[val]++;
                end[val-1]--;
                mp[val]--;
            }
            else if(mp[val+1] > 0 && mp[val+2] > 0)
            {
                end[val+2]++;
                mp[val]--;
                mp[val+1]--;
                mp[val+2]--;
            }
            else
            {
                return false;
            }
        }
        
        return true;
    }
};