// class Solution {
// public:
//     int helper(vector <int> &nums, int i, int k, vector <int> &memo)
//     {

//         if(i >= nums.size())
//             return -2e9;
     
//         if(i == nums.size()-1)
//         {
//             //cout << " Yes\n" ;
//             return nums[i];
//         }
        
//         if(memo[i] != -1)
//         return memo[i];

//         int ans = 0;
//         int res = -2e9;

//         for(int j = i; j < i+k && j < nums.size(); j++)
//         { 
//             ans = nums[i] + helper(nums, j+1, k,memo);
//             res = max(res, ans); 
//         }
        
//         for(int j = 1; j <= k; j++)
//         { 
//             ans = nums[i] + helper(nums, i+j, k,memo);
//             res = max(res, ans); 
//         }

//         return memo[i] =  res;
//     }
    
//     int maxResult(vector<int>& nums, int k) {
//         int n = nums.size();
        
//         vector <int> memo(n+1,-1);
        
//         int ans = helper(nums, 0, k, memo);
        
//         return ans;
//     }
// };

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        long long ans=0;
        deque<int> dq;
        for(int i=nums.size()-1;i>-1;--i){
            if(dq.empty())ans=nums[i];
            else
            ans=nums[i]+nums[dq.front()];
            while(!dq.empty() && ans>nums[dq.back()])dq.pop_back();
            dq.push_back(i);
            if(dq.front()>=i+k)dq.pop_front();
            nums[i]=ans;
        }
        return ans;
    }
};