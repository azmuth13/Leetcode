class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        int n = nums.size();
        
        // previous greater
        
        vector <int> prevGreater(n,-1);
        
        stack <int> st;
        
        for(int i = 0; i < n; i++)
        {
            if(st.empty())
            {
                st.push(i);
                continue;
            }
            
            while(!st.empty() && nums[st.top()] <= nums[i])
                st.pop();
            
            if(!st.empty())
                prevGreater[i] = st.top();
            
            st.push(i);
        }
        
        vector <int> mini(n,-1);
        
        int minim = nums[0];
        mini[0] = minim;
        
        for(int i = 1; i < n; i++)
        {
            minim = min(minim, nums[i]);
            mini[i] = minim;
        }
        
        for(int k = 0; k < n; k++)
        {
            int pgi = prevGreater[k];
            
            if(pgi == -1 || pgi == 0)
                continue;
            
            int minTill = mini[pgi-1];
            
            if(minTill < nums[k])
                return true;
            
        }
        return false;
    }
};