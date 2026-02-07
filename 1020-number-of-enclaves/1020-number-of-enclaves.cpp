class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j){
        grid[i][j]=0;
        if( (i-1>=0) && (grid[i-1][j]==1) )  dfs(grid, i-1 ,j);
        if( (i+1<grid.size()) && (grid[i+1][j]==1) )  dfs(grid, i+1, j );
        if( (j-1>=0) && (grid[i][j-1]==1) )  dfs(grid, i, j-1);
        if( (j+1<grid[0].size()) && (grid[i][j+1]==1) )   dfs(grid, i, j+1);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        for( int i=0; i<grid.size(); i++){
            if(grid[i][0]==1){
                dfs(grid, i, 0);
            }
        }
        for(int i=0; i<grid.size(); i++){
            if(grid[i][grid[0].size()-1]==1){
                dfs(grid, i, grid[0].size()-1);
            }
        }
        for(int j=0; j<grid[0].size(); j++){
            if(grid[0][j]==1){
                dfs(grid, 0, j);
            }
        }
        for(int j=0; j<grid[0].size(); j++){
            if(grid[grid.size()-1][j]==1){
                dfs(grid, grid.size()-1, j);
            }
        }
        int ans=0;
        for(int a=0; a<grid.size(); a++){
            for(int b=0; b<grid[0].size(); b++){
                if(grid[a][b]==1) ans++;
            }
        }
        return ans;
    }
};