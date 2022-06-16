#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
#define ordered_set tree<int, null_type ,less_equal <int>, rb_tree_tag,tree_order_statistics_node_update>
/*    cout<<*(oset.find_by_order(2))<<endl;
    cout<<oset.order_of_key(6)<<endl; */
class Solution {
public:
    int createSortedArray(vector<int>& ins) {
        int n = ins.size();
        int mod = 1e9 + 7;
        int ans = 0;
        
        ordered_set oset;
        
        for(int i = 0; i < n; i++)
        {
            int smaller = oset.order_of_key(ins[i]);
            int bigger = oset.size() - oset.order_of_key(ins[i]+1);
            
            ans += min(smaller,bigger);
            ans %= mod;
            
            oset.insert(ins[i]);
        }
        
        return ans;
    }
};