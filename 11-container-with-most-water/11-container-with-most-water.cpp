class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        
        int i = 0; 
        int j = n-1;
        
        int ans = 0;
        
        while(i < j)
        {
            ans = max(ans, (j-i)*min(height[i], height[j]));
            if(height[j] > height[i])
                i++;
            else
                j--;
        }
        return ans;
    }
};