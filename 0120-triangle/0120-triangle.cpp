class Solution {
public:
    int f(int i, int j, vector<vector<int>>& triangle, vector<vector<int>> &dp){

        if(i==0 && j==0) return triangle[0][0];
        if(i<0||j<0) return 1e9;
        if(j > i) return 1e9;

        if(dp[i][j]!=-1) return dp[i][j];

        int same_idx= triangle[i][j] + f(i-1,j,triangle, dp);
        int one_before= triangle[i][j] + f(i-1,j-1,triangle, dp);

        return dp[i][j]=min(same_idx, one_before);

    }
    int minimumTotal(vector<vector<int>>& triangle) {

        int n=triangle.size();
        int m=triangle[n-1].size();
        vector<vector<int>> dp(n, vector<int> (m,-1));

        int ans=1e9;
        for(int m=0; m<triangle[n-1].size(); m++){
            ans = min(ans ,f(n-1,m,triangle, dp));
        }

        return ans;

    }
};