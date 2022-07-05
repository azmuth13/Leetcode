class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack <int> st;
        
        int n = nums.size();
        int ind1 = 1e9, ind2 = -1e9;
        
        for(int i = 0; i < n; i++)
        {
            if(st.empty())
            {
                st.push(i);
            }
            else if(nums[st.top()] <= nums[i])
            {
                st.push(i);
            }
            else
            {
                while(st.size() && nums[st.top()] > nums[i])
                {
                    ind1 = min(ind1, st.top());
                    st.pop();
                }
            }
        }
        
        while(st.size())
            st.pop();
        
        for(int i = n-1; i >=0; i--)
        {
            if(st.empty())
            {
                st.push(i);
            }
            else if(nums[st.top()] >= nums[i])
            {
                st.push(i);
            }
            else
            {
                while(st.size() && nums[st.top()] < nums[i])
                {
                    ind2 = max(ind2, st.top());
                    st.pop();
                }
            }
        }
        
        if(ind1+ind2==0) return 0;
        
        return max(0,ind2-ind1+1);
        
    }
};