class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        int n = profits.size();
        
        vector <pair <int, int> > vp(n);
        
        for(int i = 0; i < n; i++)
        {
            vp[i].first = capital[i];
            vp[i].second = profits[i];
        }
        
        sort(vp.begin(), vp.end());
        
        priority_queue < int > pq;
        
        int ans = 0;
        
        int i = 0;
        
        while(i < n)
        {
            if(w < vp[i].first)
                break;
            
            while(i < n && vp[i].first <= w)
            {
                pq.push(vp[i].second);
                i++;
            }
            
            long long curr = 0;
            
            if(i == n)
                curr = 1e11;
            else
                curr = vp[i].first;
            
            while(pq.size() > 0 && curr > w)
            {
                int tt = pq.top();
                pq.pop();
                
                w += tt;
                k--;
                
                if(k == 0)
                    break;
            }
           
            if(k == 0)
                break;
        }
        
        return w;
    }
};