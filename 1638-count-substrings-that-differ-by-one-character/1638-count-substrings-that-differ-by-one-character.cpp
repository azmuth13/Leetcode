class Solution {
public:
    unordered_map <string, int> store;
    
    int check(string &curr)
    {
        //cout << curr << endl;
        int len = curr.size();
        int ans = 0;
        
        for(int i = 0; i < len; i++)
        {
            char temp = curr[i];
            for(char ch = 'a'; ch <= 'z'; ch++)
            {
                if(ch == temp)
                    continue;
                
                curr[i] = ch;
                if(store.find(curr) != store.end())
                {
                    ans += store[curr];
                } 
            }
            curr[i] = temp;
        }

        return ans;
    }
    
    int countSubstrings(string s, string t) {
        
        int n = t.size();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            string curr = "";
            for(int j = i; j < n; j++)
            {
                curr += t[j];
                store[curr]++;
            }
        }
        
        int m = s.size();
        for(int i = 0; i < m; i++)
        {
            string curr = "";
            for(int j = i; j < m; j++)
            {
                curr += s[j];
                
                int res = check(curr);
                ans += res;
            }
        }
        return ans;
    }
};