class Solution {
public:
    bool good(int i, int j, int n, int m)
    {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    
    int trapRainWater(vector<vector<int>>& matrix) {
        int dx[] = {0,1,-1,0};
        int dy[] = {1,0,0,-1};

        int n = matrix.size(), m = matrix[0].size();

        vector <vector <int> > vis(n, vector <int> (m,0));

        priority_queue < pair <int, pair <int, int> >,
        vector <pair <int, pair <int, int> >>, greater <pair <int, pair <int, int> > > > pq;

        for(int i = 0;  i < n; i++)
        {
            pq.push({matrix[i][0],{i,0}});
            pq.push({matrix[i][m-1],{i,m-1}});
            vis[i][0] = 1;
            vis[i][m-1] = 1;
        }

        for(int j = 0; j < m; j++)
        {
            pq.push({matrix[0][j],{0,j}});
            pq.push({matrix[n-1][j],{n-1,j}});
            vis[0][j] = 1;
            vis[n-1][j] = 1;
        }

        int water = 0;

        while(!pq.empty())
        {
            pair <int, pair <int,int> > cell = pq.top();
            pq.pop();

            // four neighbours

            int i = cell.second.first;
            int j = cell.second.second;
            int height = cell.first;

            for(int d = 0; d < 4; d++)
            {
                int ni = i + dx[d];
                int nj = j + dy[d];

                if(good(ni,nj,n,m) && !vis[ni][nj])
                {
                    int htN = matrix[ni][nj];
                    vis[ni][nj] = 1;
                    if(htN >= height)
                    {
                        pq.push({htN, {ni, nj}});
                    }
                    else
                    {
                        water += height - htN;
                        pq.push({height, {ni, nj}});
                    }
                }
            }
        }

        return water;
    }
};