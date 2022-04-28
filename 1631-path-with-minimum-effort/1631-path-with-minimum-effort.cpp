
pair<int, int > dir[] = { {1,0}, {0, 1}, {-1,0}, {0, -1} };

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
            
        int n = heights.size();
        int m = heights[0].size();

        vector < vector <int> > distance (n, vector <int> (m, INT_MAX));
        
        distance[0][0] = 0;
        
    priority_queue< vector <int>, vector < vector <int > >, greater<vector <int> > > pq;
        
        pq.push({0,0,0});
        // effortTillNow, x coordinate, y coordinate
        
        while(!pq.empty())
        {
            vector <int> ptop = pq.top();
            pq.pop();
            
            int x = ptop[1];
            int y = ptop[2];
            int effortTillNow = ptop[0];
            
            if(x == n-1 && y == m-1)
                break;
            
            if(effortTillNow < distance[x][y])
                continue;
            
            for(int i = 0; i<4; i++)
            {
                int newx = x+dir[i].first;
                int newy = y+dir[i].second;
                
                if(newx <0 || newx >= n || newy < 0 || newy >= m)
                    continue;
                
                int newEffort = max(effortTillNow, 
                                 abs(heights[x][y] - heights[newx][newy]));
                
                if(newEffort < distance[newx][newy])
                {
                    distance[newx][newy] = newEffort;
                    
                    pq.push({newEffort, newx, newy});
                }
            }
        }
        
        return distance[n-1][m-1];
    }
};