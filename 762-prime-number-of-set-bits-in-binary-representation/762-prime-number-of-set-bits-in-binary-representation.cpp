
class Solution {
public:
    vector <int> prime;
    int memo[32][2][2][32];
    
    int helper(string &a, string &b, int i, int down, int up, int cnt)
    {
        if(i >= a.size())
        {
            if(prime[cnt]==1)
                return 1;
            return 0;
        }
        
        if(memo[i][down][up][cnt] != -1) return memo[i][down][up][cnt]; 
        
        int ans = 0;
        
        int low = 0;
        int high = 1;
        
        if(!down)
            low = a[i]-'0';
        
        if(!up)
            high = b[i]-'0';
        
        for(int j = low; j <= high; j++)
        {
            ans += helper(a,b,i+1,down||(j > low), up||(j < high), cnt + (j==1));
        }
        
        return memo[i][down][up][cnt] = ans;
    }
    
    int countPrimeSetBits(int left, int right) {
        
        string a,b;
        prime.resize(33,0);
        prime[2] = 1;
        prime[3] = 1;
        prime[5] = 1;
        prime[7] = 1;
        prime[11] = 1;
        prime[13] = 1;
        prime[17] = 1;
        prime[19] = 1;
        prime[23] = 1;
        prime[29] = 1;
        prime[31] = 1;

        while(left)
        {
            a += '0' + left%2;
            left/=2;
        }
        
        while(right)
        {
            b += '0' + right%2;
            right/=2;
        }
        
        while(a.size() < 31)
            a += '0';
        
        while(b.size() < 31)
            b += '0';
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        memset(memo,-1,sizeof memo);
        int ans = helper(a,b,0,0,0,0);
        return ans;
    }
};