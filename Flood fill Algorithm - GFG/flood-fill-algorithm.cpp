// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int pc;
    
    bool good(int a, int b, int n, int m)
    {
        return (a >= 0 && a < n && b < m && b >= 0);
    }
    
    void dfs(vector<vector<int>>& image, int sr, int sc, int nC, int n, int m)
    {
        if(image[sr][sc] == nC)
        return;
        
        image[sr][sc] = nC;
        
        if(good(sr+1, sc, n, m) && image[sr+1][sc] == pc)
        {
            dfs(image, sr+1, sc, nC, n, m);
        }
        
        if(good(sr-1, sc, n, m) && image[sr-1][sc] == pc)
        {
            dfs(image, sr-1, sc, nC, n, m);
        }
        
         if(good(sr, sc+1, n, m)&& image[sr][sc+1] == pc)
        {
            dfs(image, sr, sc+1, nC, n, m);
        }
        
        if(good(sr, sc-1, n, m)&& image[sr][sc-1] == pc)
        {
            dfs(image, sr, sc-1, nC, n, m);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int nC) {
        // Code here 
        int n = image.size();
        int m = image[0].size();
        
        pc = image[sr][sc];
        
        dfs(image, sr, sc, nC, n, m);
        
        return image;
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends