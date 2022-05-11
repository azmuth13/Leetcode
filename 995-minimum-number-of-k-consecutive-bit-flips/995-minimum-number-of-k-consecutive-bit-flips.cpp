class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0, ans = 0;
        int a[n+1];
        fill(a,a+n,0);
        for(int i = 0; i < n; i++)
        {
            res -= a[i];
            if(res%2==0 && nums[i]==0)
            {
                ans++;
                res++;
                if(i+k > n)
                    return -1;
                else
                    a[i+k] += 1;
            }
            else if(res%2==1 && nums[i]==1)
            {
                ans++;
                res++;
                if(i+k > n)
                    return -1;
                else
                    a[i+k] += 1;
            }
        }
        return ans;
    }
};