class Solution {
public:
    int longestSubstring(string s, int k) {
        
        int n = s.size();
        int ans = 0;
        
        for(int uniq = 1; uniq <= 26; uniq++)
        {
            // uniq number of characters in a substring
            
            map <int, int> mp;
            
            int l = 0, r = 0;
            int freq = 0;
            int cnt = 0;
            
            while(r < n)
            {
                mp[s[r]]++;
                
                if(mp[s[r]] == 1)
                    cnt++;
                
                if(mp[s[r]] == k)
                    freq++;
                
                while(l <= r && cnt > uniq)
                {
                    mp[s[l]]--;
                    if(mp[s[l]] == 0)
                    {
                        mp.erase(s[l]);
                        cnt--;
                    }
                    
                    if(mp[s[l]] == k-1)
                    {
                        freq--;
                    }
                    
                    l++;
                }
                
                if(freq == uniq)
                {
                    //cout << "Yes\n";
                    ans = max(ans, r-l+1);
                }
                r++;
            }
            
        }
        return ans;
    }
};