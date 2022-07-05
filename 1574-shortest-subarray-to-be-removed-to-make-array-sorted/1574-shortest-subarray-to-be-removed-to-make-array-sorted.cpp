class Solution {
public:

    
    int findLengthOfShortestSubarray(vector<int>& nums) {
        int n = nums.size();
        
        if(n==0) return 0;
        
        if(n==1) return 0;
        
        int ans = n-1;
        
        int l = 0,r = n-1;
        
        while(r >= 1)
        {
            if(nums[r] < nums[r-1])
                break;
            r--;
        }
        
        ans = min(ans, r);
        
        while(l < n)
        {
            if(l >= 1 && nums[l] < nums[l-1]) break;
            while(r < n && ((nums[r] < nums[l]) || (l==r)))
            {
                r++;
            }
            
            ans = min(ans, r-l-1);
            l++;
        }
        
        return ans;
            
    }
};
/*
[1,2,3,10,4,2,3,5]
[5,4,3,2,1]
[1,2,3]
[2,2,2,1,1,1]
[1,2]
[1]
*/