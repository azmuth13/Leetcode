class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        
        vector <int> R(100001,0);
        int n = clips.size();
        
        for(int i = 0; i < n; i++)
        {
            R[clips[i][0]] = max(R[clips[i][0]], clips[i][1]);    
        }
        
        int end = 0, farthest = 0;
        int i = 0;
        int ans = 0;
        
        while(i < time && end < time)
        {
            ans++;
            
            while(i < time && i <= end)
            {
                farthest = max(farthest, R[i]);
                i++;
            }
            if(end == farthest)
                return -1;
            end = farthest;
        }
        
        return ans;
    }
};