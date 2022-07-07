class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        
        gas.insert(gas.end(),gas.begin(),gas.end());
        cost.insert(cost.end(),cost.begin(),cost.end());
        int sz = gas.size();
        vector <int> v(sz+1,-1e9);
        int pre = 0;
        
        for(int i = 0; i < gas.size(); i++)
        {
            if(pre < 0)
                pre = 0;
            pre += gas[i];
            pre -= cost[i];
            
            v[i] = pre;
        }
        
        int i = 0;
        while(i < sz)
        {
            int j = i;
            int cnt = 0;
            while(i < sz && v[i] >= 0)
            {
                i++;
                cnt++;
            }
            
            if(cnt >= n)
            {
                return j;
            }
            i++;
        }
        
//         for(int i = 0; i < sz; i++)
//         {
//             cout << v[i] << " ";
//         }
//         cout << endl;
        
        return -1;
    }
};