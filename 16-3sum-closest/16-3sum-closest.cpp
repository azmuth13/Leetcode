class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int ans = 1e9;
            
        int a, b, c;
        
        for(int i = 0; i < n; i++)
        {
            int l = 0; 
            int r = n-1;
            
            int rem = target - nums[i];
            
            while(l < r)
            {
                if(l == i)
                {
                    l++;
                    continue;
                }
                
                if(r == i)
                {
                    r--;
                    continue;
                }
                
                if(abs(nums[i] + nums[l] + nums[r] - target) < ans)
                {
                    ans = abs(nums[i] + nums[l] + nums[r] - target);
                    a = nums[i];
                    b = nums[l];
                    c = nums[r];
                }
                    
                
                if(nums[l] + nums[r] > rem)
                { 
                    r--;
                }
                else if(nums[l] + nums[r] < rem)
                {
                    l++;
                }
                else
                {
                    break;
                }
            }
        }
        
        //cout<<a<<" "<<b<<" "<<c<<endl;
        return a + b + c;
    }
};