
class Solution {
public:
 
    void fill(vector <int> &st, vector <int> &v, int i, int sum)
    {
        if(i == v.size())
        {
            st.push_back(sum);
            return;
        }
        
        fill(st, v, i+1, sum);
        fill(st, v, i+1, sum + v[i]);
    }
    
    int minAbsDifference(vector<int>& nums, int goal) {
        
        int n = nums.size();
        
        vector <int> st1, st2;
        int ans = 1e9;
        vector <int> a, b;
        for(int i = 0; i < n; i++)
        {
            if(i < n/2)
            {
                a.push_back(nums[i]);
            }
            else
            {
                b.push_back(nums[i]);
            }
        }
        
        fill(st1, a, 0, 0);
        fill(st2, b, 0, 0);
        
        sort(st1.begin(), st1.end());
        sort(st2.begin(), st2.end());
        
        for(auto &x : st1)
        {
            int t = goal - x;
            
            auto it = lower_bound(st2.begin(), st2.end(), t);
            
            if(it != st2.end())
            {
                ans = min(ans, abs(goal - (*it + x)));
                
                auto it1 = it;
                it1++;
                
                if(it1 != st2.end())
                {
                    ans = min(ans, abs(goal - (*it1 + x)));
                }
            }
            
            if(it != st2.begin())
            {
                auto it2 = it;
                it2--;
                
                ans = min(ans, abs(goal - (*it2 + x)));
            }
            
            if(ans==0)
                return ans;
        }
        
        return ans;
    }
};