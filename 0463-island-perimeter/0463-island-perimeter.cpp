class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {

        int ans = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        
        int drow[] = {0, -1, 0, 1};
        int dcol[] = {-1, 0, 1, 0};
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                 if (grid[i][j] == 1) {
                    for(int k=0;k<4;k++){
                       int nrow=i+drow[k];
                       int ncol=j+dcol[k];

                       if(nrow<0||nrow>=rows||ncol<0||ncol>=cols||grid[nrow][ncol]==0)
                       ans++;
                    }

                }
            }
        }
        return ans;

    }
};