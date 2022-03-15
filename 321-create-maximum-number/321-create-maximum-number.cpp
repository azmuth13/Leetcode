int speedup = []{ios::sync_with_stdio(0); cin.tie(0); return 0;}();

class Solution {
public:
    
    vector <int> maxVector(vector <int> nums, int l)
    {
        while(nums.size() > l)
        {
            int i = 0, n = nums.size();
            
            for(; i < n-1; i++)
            {
                if(nums[i] < nums[i+1])
                {
                    nums.erase(nums.begin() + i);
                    break;
                }
            }
            
            if(i == n-1)
            {
                nums.erase(nums.begin() + i);
            }
        }
        return nums;
    }
    
    bool compare(vector <int> &nums1, int i, vector <int> &nums2, int j)
    {
        while(i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j])
        {
            i++, j++;
        }
        
        if(i < nums1.size() && j < nums2.size())
        {
            return nums1[i] > nums2[j]; 
        }
        else if(j == nums2.size())
            return true;
        else
            return false;
    }
    
    vector <int> merge(vector <int> &nums1, vector <int> &nums2, int k)
    {
        vector <int> ans(k,0);
        
        int i = 0, j = 0, r = 0;
        
        while(r < k)
        {
            if(compare(nums1, i, nums2, j))
            {
                ans[r++] = nums1[i++];
            }
            else
            {
                ans[r++] = nums2[j++];
            }
        }
        return ans;
    }
    
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int m = nums1.size();
        int n = nums2.size();
        
        vector <int> ans(k,0);
        
        for (int l1 = max(0, k-n); l1 <= min(k, m); ++l1)
        {
//             int l1 = i;
//             int l2 = k - i;
            
//             if(l1 >= k || l1< 0 || l2 >= k || l2 < 0)
//             {
//                 continue;
//             }
            
            auto v1 = maxVector(nums1, l1);
            auto v2 = maxVector(nums2, k-l1);
            auto v3 = merge(v1, v2, k);
            
            if(compare(v3,0,ans,0))
            {
                ans = v3;
            }
        }
        
        return ans;
    }
};