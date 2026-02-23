
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 1e9));

        dp[0][0] = triangle[0][0];

        for(int i = 1; i < n; i++){
            for(int j = 0; j <= i; j++){

                int same_idx = 1e9;
                int one_before = 1e9;

                if(j <= i-1) same_idx = dp[i-1][j];


                if(j-1 >= 0) one_before = dp[i-1][j-1];

                dp[i][j] = triangle[i][j] + min(same_idx, one_before);
            }
        }
        
        int ans = 1e9;
        for(int j = 0; j < n; j++){
            ans = min(ans, dp[n-1][j]);
        }
        return ans;
    }
};