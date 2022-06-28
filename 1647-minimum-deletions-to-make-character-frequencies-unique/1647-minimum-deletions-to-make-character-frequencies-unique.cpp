class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();
        
        vector <int> a(27,0);
        
        for(int i = 0; i < n; i++)
        {
            a[s[i]-'a']++;
        }
        
        priority_queue <int> pq;
        for(int i = 0; i < 26; i++)
        {
            if(a[i] > 0)
                pq.push(a[i]);
        }
        int ans = 0;
        while(!pq.empty())
        {
            int tp = pq.top();
            pq.pop();
            
            if(pq.empty())
                break;
            
            int tp2 = pq.top();
            pq.pop();
            
            if(tp == tp2)
            {
                tp2--;
                pq.push(tp);
                ans++;
                if(tp2 > 0)
                    pq.push(tp2);
            }
            else
            {
                pq.push(tp2);
            }
        }
        return ans;
    }
};