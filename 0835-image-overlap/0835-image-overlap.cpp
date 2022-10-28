class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector <pair <int, int> > vec_a, vec_b;
        
        int n = img1.size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(img1[i][j] == 1)
                    vec_a.push_back({i,j});
                if(img2[i][j] == 1)
                    vec_b.push_back({i,j});
            }
        }
        
        map <pair <int, int> , int> mp;
        int ans = 0;
        for(int i = 0; i < vec_a.size(); i++)
        {
            for(int j = 0; j < vec_b.size(); j++)
            {
                mp[{vec_a[i].first - vec_b[j].first, vec_a[i].second - vec_b[j].second}]++;
            }
        }
        
        for(auto &x : mp)
        {
            ans = max(ans, x.second);
        }
        return ans;
    }
};  