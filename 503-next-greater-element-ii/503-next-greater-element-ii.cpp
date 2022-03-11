class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        vector <int> v = nums;
        v.insert(v.end(), nums.begin(), nums.end());
        
        int n = v.size();
        
        vector <int> ng(n,-1);
        
        stack <int> st;

        for(int i = n-1; i >= 0; i--)
        {
            if(st.empty())
            {
                st.push(i);
                continue;
            }
            
            while(st.size() > 0 && v[st.top()] <= v[i])
                st.pop();
            
            if(!st.empty())
                ng[i] = v[st.top()];
            
            st.push(i);
        }
        
        int sz = nums.size();
        
        for(int i = 0; i < sz; i++)
            nums[i] = ng[i];
        
        return nums;
    }
};