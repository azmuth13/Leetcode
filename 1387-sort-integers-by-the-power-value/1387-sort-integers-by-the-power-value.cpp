class Solution {
public:
    
    int helper(int x)
    {
        if(x <= 1)
            return 0;
        
        if(x&1)
        {
            return 1 + helper(3*x + 1);
        }
        else
        {
            return 1 + helper(x/2);
        }
    }
    
    int getKth(int lo, int hi, int k) {
        
        vector < pair <int, int> > arr;
        
        for(int i = lo; i <= hi; i++)
        {
            int val = helper(i);
            arr.push_back({val,i});
        }
        
        sort(arr.begin(), arr.end());
        
        return arr[k-1].second;
    }
};