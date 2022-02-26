class Solution {
public:
    string reorganizeString(string s) {
        
        
        int n = s.length();
        string ans = "";
        
        map < char , int > mp;
        int maxi = 0;
        char ch;
        for(int i = 0; i < n; i++)
        {
            mp[s[i]]++;
            if(maxi < mp[s[i]])
            {
                maxi = mp[s[i]];
                ch = s[i];
            }
        }
        
        priority_queue <pair <int, char> > pq;
        
        for(auto x : mp)
        {
            pq.push({x.second, x.first});
        }
        
        char prev = pq.top().second;
        ans += prev;
        int prevFreq = pq.top().first - 1;
        
        pq.pop();
        
        while(!pq.empty())
        {
            pair <int, char> pp = pq.top();
            pq.pop();
            
            ans += pp.second;
            
            if(prevFreq > 0)
            pq.push({prevFreq, prev});
            
            prevFreq = pp.first-1;
            prev = pp.second;
        }
        
        for(int i = 1; i < ans.size(); i++)
        {
            if(ans[i] == ans[i-1])
                return "";
        }
        
        if(ans.length() != s.length())
            return "";
        
        return ans;
        
    }
};