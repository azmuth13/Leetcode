class Solution {
public:
    int memo[10][2][2][10];
    int helper(string &s, int i, int f, int c, int cnt)
    {
        if(i >= s.size())
        {
            return cnt;
        }
        if(memo[i][f][c][cnt] != -1) return memo[i][f][c][cnt];
        
        int up = s[i] - '0';
        int ans = 0;
        
        if(f==1)
        {
              up = 9; 
        }
         
        if(c==0)
        {
            // number is not started
            
            ans += helper(s,i+1,1,c,cnt);
            
            for(int j = 1; j <= up; j++)
            {
                ans += helper(s,i+1, f || (j < up),1,cnt + (j==1));
            }
        }
        else
        {
            // number is started
            for(int j = 0; j <= up; j++)
            {
                ans += helper(s,i+1, f || (j < up),1,cnt + (j==1));
            }
        }

        return memo[i][f][c][cnt] = ans;
    }
    
    int countDigitOne(int n) {
        string s = to_string(n);
        memset(memo,-1,sizeof memo);
        int ans = helper(s,0,0,0,0);
        return ans;
    }
};