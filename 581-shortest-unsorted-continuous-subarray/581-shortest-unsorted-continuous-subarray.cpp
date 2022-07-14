class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 1e9;
        int r = -1e9;
        
        stack <int> st;
        int i = 0;
        
        while(i < n)
        {
            if(st.empty())
            {
                st.push(i);
            }
            else
            {
                while(!st.empty() && nums[st.top()] > nums[i])
                {
                    l = min(l, st.top());
                    st.pop();
                }
                st.push(i);
            }
            i++;
        }
        
        while(!st.empty())
            st.pop();
        i = n-1;
        while(i >= 0)
        {
            if(st.empty())
            {
                st.push(i);
            }
            else
            {
                while(!st.empty() && nums[st.top()] < nums[i])
                {
                    r = max(r, st.top());
                    st.pop();
                }
                st.push(i);
            }
            i--;
        }
        
        
        if(l == 1e9 && r == -1e9)
            return 0;
        
        return max(0,r-l+1);
    }
};