class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        
        int n = arr.size();
        
        map <int, int> mp;
        
//         for(int i = 0; i < n; i++)
//         {
//             mp[arr[i]] = 1;
//         }
        
        int ans = 1;
        for(int i = 0; i < n; i++)
        {
            if(mp.find(arr[i] - d) != mp.end())
            {
                mp[arr[i]] = max(mp[arr[i]], 1 + mp[arr[i] - d]);
                ans = max(ans, mp[arr[i]]);
            }
            mp[arr[i]] = max(mp[arr[i]], 1);
        }
        
        return ans;
    }
};