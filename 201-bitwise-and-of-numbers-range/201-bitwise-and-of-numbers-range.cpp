class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
    
        if(right == 0)
            return 0;
        int ans = 0;
        
        for(int i = 31; i >= 0; i--)
        {
            if( ((1 << i)&left) != ((1 << i)&right) )
                break;
            
            if((1 << i)&left)
            ans |= (1<<i);
             
        }
        return ans;

    }
};