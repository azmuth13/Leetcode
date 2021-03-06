class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        
//         gas.insert(gas.end(),gas.begin(),gas.end());
//         cost.insert(cost.end(),cost.begin(),cost.end());
        
//         int sz = gas.size();
//         vector <int> v(sz+1,-1e9);
//         int pre = 0;
        
//         for(int i = 0; i < gas.size(); i++)
//         {
//             if(pre < 0)
//                 pre = 0;
//             pre += gas[i];
//             pre -= cost[i];
            
//             v[i] = pre;
//         }
        
//         int i = 0;
//         while(i < sz)
//         {
//             int j = i;
//             int cnt = 0;
//             while(i < sz && v[i] >= 0)
//             {
//                 i++;
//                 cnt++;
//             }
            
//             if(cnt >= n)
//             {
//                 return j;
//             }
//             i++;
//         }

//         return -1;
        int ts = 0;
        int start = 0;
        int s = 0;
        for(int i = 0; i < n ; i++)
        {
            ts += gas[i]-cost[i];
            s += gas[i]-cost[i];
            if(s<0)
            {
                s = 0;
                start= i+1;
            }
        }
        if(ts >=0) return start;
        return -1;
    }
};