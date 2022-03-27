class Solution {
public:
    
    unordered_map <int, int> mp;
    
    int helper(vector <int> &arr, int d, int i)
    {
        if(i == arr.size())
        {
            return 0;
        }
        int ans = 1;
        if(mp.find(arr[i] - d) != mp.end())
        {
            mp[arr[i]] = max(mp[arr[i]], 1 + mp[arr[i] - d]);
            ans = max(ans, mp[arr[i]]);
        }
        mp[arr[i]] = max(mp[arr[i]], 1);
        return max(ans, helper(arr, d, i+1));
    }
    
    
    int longestSubsequence(vector<int>& arr, int d) {
        
        int n = arr.size();
        
//         unordered_map <int, int> mp;

//         int ans = 1;
//         for(int i = 0; i < n; i++)
//         {
//             if(mp.find(arr[i] - d) != mp.end())
//             {
//                 mp[arr[i]] = max(mp[arr[i]], 1 + mp[arr[i] - d]);
//                 ans = max(ans, mp[arr[i]]);
//             }
//             mp[arr[i]] = max(mp[arr[i]], 1);
//         }
        
//         return ans;
        
        int ans = helper(arr, d, 0);
        return ans;
    }
};