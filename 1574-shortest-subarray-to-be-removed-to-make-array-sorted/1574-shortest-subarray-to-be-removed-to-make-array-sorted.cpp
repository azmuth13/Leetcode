class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int r = n-2;
        int l = 1;
        int ans = n-1;
        while(r >= 0)
        {
            if(arr[r] > arr[r+1])
                break;
            r--;
        }
        
        while(l < n && arr[l] >= arr[l-1])
        {
            l++;
        }
        if(l == n) return 0;
        ans = min(ans, n-l);
        l=1;
        if(r==-1)
            return 0;
        r++;
        
        ans = min(ans, r);
        if(arr[r] >= arr[l-1])
        {
            ans = min(ans, r-(l-1)-1);
        }

        while(l <= r && r < n)
        {
            if(arr[l] < arr[l-1])
            {
                // l--;
                // ans = min(ans, r-l-1);
                break;
            }
            
            if(arr[l] <= arr[r])
            {
                ans = min(ans, r-l-1);    
                l++;
            }
            else
            {
                r++;
            }
        }
        return ans;
    }
};