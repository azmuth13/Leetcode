class Solution {
public:
    
    long long numberOfWeeks(vector<int>& milestones) {
        

        
        int n = milestones.size();
            
        long long sum = 0;
        long long _max = 0;
        
        for(int i=0; i<n; i++)
        {
            sum += milestones[i];
            _max = max(_max, (long long)milestones[i]);
        }
        long long rest = sum - _max;
        
        if(_max > rest)
        {
            return 2*rest+1;
        }
        return sum;
        
        priority_queue <long long> q;
        
        for(int i = 0; i < n; i++)
        {
            q.push(milestones[i]);
        }
        
        long long ans = 0;
        while(q.size() >= 2)
        {
            int bigg = q.top();
            q.pop();
            
            int bigg2 = q.top();
            q.pop();
            
            if(bigg == bigg2)
            {
                cout << "YES\n" << bigg << endl;
                int cnt = 2;
                while(q.size() > 0 && q.top() == bigg)
                {
                    q.pop();
                    cnt++;
                }
                ans += cnt*bigg;
                continue;
            }
            
            ans += 2*bigg2;
            bigg-=bigg2;
            bigg2 = 0;
            
            if(bigg > 0)
            q.push(bigg);
        }
        if(!q.empty()) ans++;
        
        return ans;
    }
};