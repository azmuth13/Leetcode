class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        
        // find previous greater and next greater 
        
        int nextG[n+1];
        int prevG[n+1];
        
        for(int i=0; i<=n; i++)
        {
            nextG[i] = prevG[i] = 0;
        }
        
        int maxi = 0;
        
        for(int i=0; i<n; i++)
        {
            if(height[i] > maxi)
            {
                prevG[i] = maxi;
                maxi = height[i];
            }
            else
            {
                prevG[i] = maxi;
            }
        }
        
        maxi = 0;
        
        for(int i=n-1; i>=0; i--)
        {
            if(height[i] > maxi)
            {
                nextG[i] = maxi;
                maxi = height[i];
            }
            else
            {
                nextG[i] = maxi;
            }
        }
        
        int ans = 0;
//         for(int i=0; i<n; i++)
//         {
//             cout << nextG[i] << " ";
           
//         }
//         cout << endl;
//         for(int i=0; i<n; i++)
//         {
//             cout << prevG[i] << " ";
//         }
        
        
        for(int i=0; i<n; i++)
        {
            
            int h = min(nextG[i], prevG[i]);
            ans += max(0, h - height[i]);
        }
        
        return ans;
    }
};