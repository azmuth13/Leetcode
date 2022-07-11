class Solution {
public:
    using ll = long long;
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size();
        vector <ll> bits1(32,0), bits2(32,0);
        
        for(int i = 0; i < 32; i++)
        {
            ll cnt = 0;
            for(int j = 0; j < n; j++)
            {
                if(arr1[j]&(1<<i))
                    cnt++;
            }
            bits1[i]+=cnt;
            
            cnt = 0;
            
            for(int j = 0; j < m; j++)
            {
                if(arr2[j]&(1<<i))
                    cnt++;
            }
            
            bits2[i]+=cnt;
        }
//         for(auto x : bits1)
//         {
//             cout << x << ' ';
//         }
//         cout << endl;
        
//         for(auto x : bits2)
//         {
//             cout << x << ' ';
//         }
//         cout << endl;
        
        int ans = 0;
        
        for(int i = 0; i < 32; i++)
        {
            if((bits1[i]*(bits2[i]))&1)
                ans |= (1<<i);
        }
        return ans;
        
    }
};