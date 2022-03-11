class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
            
        int n = arr.size();
        
        int mod = 1e9+ 7;
        
        vector <int> nextSmall(n, n), prevSmall(n, -1);
        
        vector <int> stk;
        
        for(int i = n-1; i >= 0; i--)
        {
            if(stk.empty())
            {
                stk.push_back(i);
                continue;
            }
            
            while(!stk.empty() && arr[stk.back()]  >= arr[i])
                stk.pop_back();
            
            if(!stk.empty())
                nextSmall[i] = stk.back();
            
            stk.push_back(i);
        }
        
        stk.clear();
        
        for(int i = 0; i < n; i++)
        {
            if(stk.empty())
            {
                stk.push_back(i);
                continue;
            }
            
            while(!stk.empty() && arr[stk.back()] > arr[i])
                stk.pop_back();
            
            if(!stk.empty())
                prevSmall[i] = stk.back();
            
            stk.push_back(i);
        }
        
        long long int ans = 0;
        
        for(int i = 0; i < n; i++)
        {
//             cout << arr[i] << endl;
//             cout <<"    Next Smaller : "<<nextSmall[i]<<endl;
//             cout <<"    Prev Smaller : "<<prevSmall[i]<<endl;
            int aageElements = nextSmall[i] - i - 1;
            int peecheElements = i - prevSmall[i] - 1;
            
//             cout <<"    aageElements :" <<aageElements<<endl;
//             cout <<"    peecheElements :" <<peecheElements<<endl;
            
            int N = aageElements + peecheElements + 1;
            int pos = peecheElements ;
            
//             cout <<"    sizeOfthisSubarray :" <<N<<endl;
//             cout <<"    position of this elements :" <<pos<<endl;
            
            
            long long int val = ((arr[i]%mod * (N-pos)%mod))%mod;
            val = (val%mod * (pos + 1)%mod)%mod;
            
           // cout <<"    Contribution :" <<val<<endl;
            
            ans += (val);
            ans %= mod;
            
        }

        
        return ans;
        
    }
};