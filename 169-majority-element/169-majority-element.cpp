class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
//         int ans = nums[0];
//         int count = 1;
        
//         for(int i=1; i<nums.size(); i++) {
//             if(nums[i]==ans) {
//                 count++;
//             } else {
//                 if(count==1) {
//                     ans = nums[i];
//                     count=1;
//                 } else {
//                     count--;
//                 }
//             }
//         }
//         return ans;
        
//         vector <int> cnt(32,0);
        
//         for(int i = 0; i < n; i++)
//         {
//             for(int j = 0; j < 32; j++)
//             {
//                 if((1<<j)&nums[i])
//                     cnt[j]++;
//             }
//         }
//         int ans = 0;
//         for(int i = 0; i < 32; i++)
//         {
//             if(cnt[i] > n/2)
//                 ans |= (1<<i);
//         }
//         return ans;
        
        int candidate = nums[0];
        int count = 1;
        for(int i = 1; i < n; i++)
        {
            if(count==0)
            {
                count = 1;
                candidate = nums[i];
            }
            else if(nums[i] == candidate)
                count++;
            else
                count--;
        }
        return candidate;
    }
};

// class Solution {
//     public int majorityElement(int[] nums) {
//         int ans = nums[0];
//         int count = 1;
        
//         // ----Moore's Voting Algorithm----
        
//         // we will assume first that the answer is element at index 0 and its freq. is 1
//         // then we will start checking the next elements, if its same as the "ans" then we will inc the "count"
//         // else if the count of the prev ans is 1 we will change the "ans" to current element and initialize 
//         // count to 1. and if the count is not 1 we will simply dec the count.
        
//         for(int i=1; i<nums.length; i++) {
//             if(nums[i]==ans) {
//                 count++;
//             } else {
//                 if(count==1) {
//                     ans = nums[i];
//                     count=1;
//                 } else {
//                     count--;
//                 }
//             }
//         }
//         return ans;
//     }
// }