class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        
        unordered_map <int, int> mp;
        int n = arr.size();
        for(int i = 0; i < n; i++)
        {
            arr[i]%=k;
            if(arr[i] < 0)
                arr[i] += k;
            
            mp[arr[i]]++;
        }
            
        if(mp[0]&1)
            return false;
        auto x = mp.begin();
        //x++;
        
        
        while(x != mp.end())
        {
            int val = k - x->first;
            if(val == k)
            {
                x++;
                continue;
            }
            
            if(mp[val] != mp[x->first])
                return false;
            
            x++;
        }
        return true;
    }
};