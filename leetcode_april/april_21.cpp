class Solution {
    int n;
    int dp[500][500];
public:
    int mindist(int i, int j, vector<vector<int>> &triangle) {
        if(i == n - 1) {
            return triangle[i][j];
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans1 = mindist(i + 1, j, triangle);
        int ans2 = mindist(i + 1, j + 1, triangle);
        
        return dp[i][j] = triangle[i][j] + min(ans1, ans2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();
        
        memset(dp, -1, sizeof(dp));
        
        int ans = mindist(0, 0, triangle);
        
        return ans;
    }
};