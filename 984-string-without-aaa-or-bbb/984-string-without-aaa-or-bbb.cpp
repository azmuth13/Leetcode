class Solution {
public:

    string strWithout3a3b(int a, int b) {
        
        
        string ans = "";
        char ch1 = 'a', ch2 = 'b';
        
        if(b > a)
        {
            swap(ch1,ch2);
            swap(a,b);
        }
         
        
            while(a-b > 1 && a > 0 && b > 0)
            {
                ans += ch1;
                ans += ch1;
                a-=2;
                ans += ch2;
                b-=1;
            }
            int i = 0;
            while(a > 0 && b > 0)
            {
                if(i%2==0)
                {
                    ans += ch1;
                    a--;
                }
                else
                {
                    ans += ch2;
                    b--;
                }
                i++;
            }
            while(a > 0)
                ans += ch1,a--;
            while(b > 0)
                ans += ch2,b--;
        
        
        return ans;
    }
};