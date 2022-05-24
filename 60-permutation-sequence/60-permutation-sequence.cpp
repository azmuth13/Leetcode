class Solution {
public:
    string getPermutation(int n, int k) {
        
        string s = "";
        vector <int> nums(n);
        long long fac = 1;
        k--;
        for(int i = 1; i <= n; i++)
        {
            nums[i-1] = i;
            fac *= i;
        }

        int fac9 = 362880;
        int fac10 = 3628800;

        int i=0,after=0;
        for(i = 0; i < n; i++)
        {
            fac = fac/(n-i);

            /*
            after = after +1 i + k/fac;

            */

            after = i + k/fac;

            int val = nums[after];

            while(after > i)
            {
                nums[after] = nums[after-1];
                after--;
            }
            k%=fac;
            nums[i] = val;
        }

        for(auto x : nums)
        {
            s += to_string(x);
        }

        return s;
        
    }
};