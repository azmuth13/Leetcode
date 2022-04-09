class Solution {
public:
    
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        
        map <int, int> mp;
        
        for(int i=0; i<n; i++)
        {
            mp[nums[i]]++;
        }
        vector < pair <int, int> > vp;
        
        for(auto x : mp)
        {
            vp.push_back({x.second, x.first});
        }
        sort(vp.begin(), vp.end());
        
        
        vector <int> ans;
        
        for(int i = vp.size()-1; i>=0; i--)
        {
            ans.push_back(vp[i].second);
            k--;
            
            if(k==0)
                break;
        }
        
        return ans;
        
    }
};