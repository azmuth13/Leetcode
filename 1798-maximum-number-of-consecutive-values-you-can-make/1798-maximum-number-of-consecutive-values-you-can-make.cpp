class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(),coins.end());
        
        int n = coins.size();
        int pre = 1;
        for(int i = 0; i < n; i++)
        {
            if(coins[i] <= pre)
            {
                pre += coins[i];
            }
            else
                break;
        }
        
        return pre;
    }
};