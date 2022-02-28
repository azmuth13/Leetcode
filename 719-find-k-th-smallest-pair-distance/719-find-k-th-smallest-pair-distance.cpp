
class Solution {
public:
    
    bool good(int diff, vector <int> &nums, int k)
    {
        int res = 0;
        int j = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            while(j < nums.size() && nums[j] - nums[i] <= diff)
            {
                j++;
            }
            
            res += (j-i-1);
        }
        
        return res >= k;
    }
    
    int smallestDistancePair(vector<int>& nums, int k) 
    {
        ios_base::sync_with_stdio(0);cin.tie(0);
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int l = 0, r = 1e6;
            
        int ans = 0;
        
        while(l <= r)
        {
            int mid = (l + r)/2;

            if(good(mid, nums, k))
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        
        return ans;
    }
};