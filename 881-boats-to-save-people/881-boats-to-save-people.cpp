class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        multiset <int> st(people.begin(), people.end());
        
        int ans = 0;
        
        while(st.size() > 0)
        {
            auto it = st.begin();
            int p1 = *it;
            
            int mwtp2 = limit - p1;
                
            st.erase(st.find(p1));
            
            if(st.size() == 0)
            {
                ans++;
                break;
            }
            
            auto it2 = st.lower_bound(mwtp2);
            
            if(it2 == st.begin() && *it2 > mwtp2)
            {
                ans++;
                continue;
            }
            
            if(it2 == st.end() || *it2 > mwtp2)
                it2--;
                
            int p2 = *it2;
            st.erase(st.find(p2));
            ans++;
        }
        
        return ans;
    }
};