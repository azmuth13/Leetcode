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
            if(pali[i][s.size()-1])
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
            if(pali[i][j])
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

        vector < vector <int> > pali(n+1,vector <int> (n+1,0));
        
        for(int i = n-1; i >= 0; i--)
        {
            for(int j = i; j < n; j++)
            {
                if(s[i] == s[j])
                {
                    pali[i][j] = i+1 >= j || pali[i+1][j-1];
                }
                else if(i == j)
                {
                    pali[i][j] = 1;
                }
            }
        }

        int ans = helper(s, 0, k, memo, pali);
        return ans;
    }
};