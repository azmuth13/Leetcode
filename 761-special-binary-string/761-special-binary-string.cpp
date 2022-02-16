class Solution {
public:
    string makeLargestSpecial(string s) {
        
        vector <string> res;
        
        int count = 0, i = 0;
        
        for(int j = 0; j < s.size(); j++)
        {
            if(s[j] == '1')
                count++;
            else
                count--;
            
            if(count == 0)
            {
                res.push_back("1" + makeLargestSpecial(s.substr(i+1, j-i-1)) + "0");
                i = j+1;
            }
        }
        
        sort(res.rbegin(), res.rend());
        
        string ans = "";
        for(auto x : res)
            ans += x;
        
        return ans;
    }
};