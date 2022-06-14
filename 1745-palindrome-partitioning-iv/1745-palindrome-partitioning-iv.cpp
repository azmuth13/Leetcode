class Solution {
public:
    
    int isPal(string &s, int i, int j, vector <vector <int>> &pali)
    {
        if(pali[i][j] != -1)
            return pali[i][j];
        
        int ans = true;
        int a = i, b = j;
        while(i < j)
        {
            if(s[i] != s[j])
            {
                ans = false;
                break;
            }
            i++,j--;
        }
        return pali[a][b] = ans;
    }
    
   
    
    int helper(string &s, int i, int k, vector <vector <int>> &memo, vector <vector <int>> &pali)
    {
        if(k == 0)
        {
            if(isPal(s,i,s.size()-1,pali))
                return true;
            
            return false;
        }
        
        if(k < 0)
            return false;
        
        if(memo[i][k] != -1)
            return memo[i][k];
        
        int ans = false;
        
        for(int j = i; j < s.size()-1; j++)
        {
            if(isPal(s,i,j,pali))
            {
                ans = ans|helper(s,j+1, k-1, memo, pali);
                if(ans)
                    break;
            }
        }
        return memo[i][k] = ans;
    }
    
    
    bool checkPartitioning(string s) {
        int k = 2;
        int n = s.size();
        vector < vector <int> > memo(n+1,vector <int> (k+1,-1));
        // int ** memo = new int*[n+1];
        // for(int i = 0; i <= n; i++)
        // {
        //     memo[i] = new int[k+2];
        //     for(int j = 0; j <= k+1; j++)
        //     {
        //         memo[i][j] = -1;
        //     }
        // }
        vector < vector <int> > pali(n+1,vector <int> (n+1,-1));
        // int ** pali = new int*[n+1];
        // for(int i = 0; i <= n; i++)
        // {
        //     pali[i] = new int[n+1];
        //     for(int j = 0; j <= n; j++)
        //     {
        //         pali[i][j] = -1;
        //     }
        // }
        int ans = helper(s, 0, k, memo, pali);
        return ans;
    }
};