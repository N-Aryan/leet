class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n=grid.size();

        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;

        queue<pair<pair<int,int>, int>> q;
        q.push({ {0,0}, 0 });

        while(!q.empty()){

            auto curr=q.front();
            q.pop();

            int i=curr.first.first;
            int j=curr.first.second;
            int dis=curr.second;

            if(i==n-1 && j==n-1) return dis+1;
            
            if(i-1>=0 && grid[i-1][j]==0){
                q.push({ {i-1,j},dis+1 });
                grid[i-1][j]=1;
            } 
            if(i+1<n && grid[i+1][j]==0){
                q.push({ {i+1,j},dis+1 });
                grid[i+1][j]=1;
            } 
            if(j-1>=0 && grid[i][j-1]==0){
                q.push({ {i,j-1},dis+1 });
                grid[i][j-1]=1;
            } 
            if(j+1<n && grid[i][j+1]==0){
                q.push({ {i,j+1},dis+1 });
                grid[i][j+1]=1;
            } 

            if(i-1>=0 && j-1>=0 && grid[i-1][j-1]==0){
            q.push({ {i-1,j-1}, dis+1 });
            grid[i-1][j-1] = 1;
            }

            if(i-1>=0 && j+1<n && grid[i-1][j+1]==0){
            q.push({ {i-1,j+1}, dis+1 });
            grid[i-1][j+1] = 1;
            }

            if(i+1<n && j-1>=0 && grid[i+1][j-1]==0){
            q.push({ {i+1,j-1}, dis+1 });
            grid[i+1][j-1] = 1;
            }

            if(i+1<n && j+1<n && grid[i+1][j+1]==0){
            q.push({ {i+1,j+1}, dis+1 });
            grid[i+1][j+1] = 1;
            }


        }
        return -1;
    }
};