class Solution {
public:
    
    bool subs(string &a, string &b)
    {
        int i = 0, j = 0;
        while(i < a.size() && j < b.size())
        {
            if(a[i] == b[j])
            {
                i++, j++;
            }
            else
            {
                j++;
            }
        }
        return i == (int)a.size();
    }
    
    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        int ans = -1;
        for(int i = 0; i < n; i++)
        {
            bool falg = 0;
            for(int j = 0; j < n; j++)
            {
                if(i == j) continue;
                
                if(subs(strs[i], strs[j]))
                {
                    falg = 1;
                    break;
                }
            }
            if(!falg)
            {
                //cout << strs.size() << endl;
                ans = max(ans, (int)strs[i].size());
            }
        }
        return ans;
    }
};