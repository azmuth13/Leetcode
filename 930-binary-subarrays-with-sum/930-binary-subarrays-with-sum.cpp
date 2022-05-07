class Solution {
public:
    
    int helper(vector<int>& nums, int goal)
    {
        int sum = 0;
        
        int i = 0, j = 0;
        int n = nums.size();
        int ans = 0;
        
        while(j < n)
        {
            sum += nums[j];
            
            while(i <= j && sum > goal)
            {
                sum -= nums[i];
                i++;
            }
            
            ans += (j-i+1);
            j++;
        }
        return ans;
    }
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        return helper(nums, goal) - helper(nums, goal-1);
//         int sum = 0;
        
//         int i = 0, j = 0;
//         int n = nums.size();
//         int ans = 0;
        
//         while(j < n)
//         {
//             if(sum < goal)
//             {
//                 sum += nums[j];
//                 j++;
//             }
//             else if(sum > goal)
//             {
//                 sum -= nums[i];
//                 i++;
//             }
//             else
//             {
//                 ans++;
//                 i++, j++;
//             }
//         }
//         return ans;
    }
};