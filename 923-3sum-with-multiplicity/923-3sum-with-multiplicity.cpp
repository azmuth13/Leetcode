class Solution {
public:
    int threeSumMulti(vector<int>& nums, int target) {
        
        int n = nums.size();
        long long mod = 1e9 + 7;
        
        if(n==0)
            return 0;
        long long ans = 0;
        
        sort(nums.begin(), nums.end());
        
        long long count[101];
        
        for(int i = 0; i < 101 ;i++)
            count[i] = 0;
        
        for(int i = 0; i < n; i++)
            count[nums[i]]++;
        
        vector <long long> uniq;
        
        for(int i = 0; i <= 100; i++)
        {
            if(count[i] > 0)
                uniq.push_back(i);
        }
        // for(auto x : uniq)
        //     cout << x << " ";
        // cout << endl;
        int sz = uniq.size();
        
        for(int i=0; i<sz; ++i)
        {
            
            int j = i;
            int k = sz-1;
            
            while(j <= k)
            {
                if(uniq[j] + uniq[k] + uniq[i] > target)
                {
                    k--;
                }
                else if(uniq[j] + uniq[k] + uniq[i] < target)
                {
                    j++;
                }
                else
                {
                    if(i < j && j < k)
                    {
                        ans += count[uniq[i]] * count[uniq[j]] * count[uniq[k]];
                    }
                    else if(i == j && j < k)
                    {
                        ans += (count[uniq[i]] * (count[uniq[i]]-1))/2 * count[uniq[k]];
                    }
                    else if(i < j && j == k)
                    {
                        ans += (count[uniq[j]] * (count[uniq[j]]-1))/2 * count[uniq[i]];
                    }
                    else
                    {
                        ans += (count[uniq[j]] * (count[uniq[j]]-1) * (count[uniq[j]]-2))/6;
                    }
                    ans %= mod;
                    j++, k--;
                }   
            }
        }
        
        return ans;
    }
};