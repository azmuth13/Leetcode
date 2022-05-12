class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        
        int n = nums.size();
        
        int N = n/2;
        int sum = 0;
        for(int i = 0; i < n; i++)
            sum += nums[i];
        
        vector <int> left[N+1], right[N+1];
        
        for(int mask = 0; mask < (1<< N); mask++)
        {
            int sz = 0, l = 0, r = 0;
            
            for(int i = 0; i < N; i++)
            {
                if(mask & (1<<i))
                {
                    sz++;
                    l += nums[i];
                    r += nums[i + N];
                }
            }
            left[sz].push_back(l);
            right[sz].push_back(r);
        }
        
        /*
            
            subset : size = sz1, sum = a
            
            subset : size = N - sz1, sum = b
            
            a + b , total_sum - (a+b)
        
        */
        
        int ans = 1e9;
        
        for(int sz = 0; sz <= N; sz++)
        {
            sort(right[sz].begin(), right[sz].end());
        }
        
        
        for(int sz1 = 0; sz1 <= N; sz1++)
        {
            int sz2 = N - sz1;
            for(int a : left[sz1])
            {
                int b = (sum - 2*a)/2;
                
                auto it = lower_bound(right[sz2].begin(), right[sz2].end(), b);
                if(it != right[sz2].end())
                {
                    ans = min(ans, abs(sum - 2*(a + (*it))));
                }
                
                if(it != right[sz2].begin())
                {
                    it--;
                    ans = min(ans, abs(sum - 2*(a + (*it))));
                }
            }
        }
        return ans;
    }
};