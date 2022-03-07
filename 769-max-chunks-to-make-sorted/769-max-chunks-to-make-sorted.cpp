class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int n = arr.size();
        
        int i = 0;
        stack <int> st;

        while(i < n)
        {
            int largest = arr[i];
            
            while(st.size() > 0 && st.top() > arr[i])
            {
                largest = max(largest, st.top());
                st.pop();
            }
            
            st.push(largest);
            i++;
        }
        
        return st.size();
        
    }
};