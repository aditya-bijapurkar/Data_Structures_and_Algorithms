//   Link: https://leetcode.com/problems/minimum-path-sum/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int down, right;
        
        for(int i=m-1;i>-1;i--){
            for(int j=n-1;j>-1;j--){
                if(i==m-1 && j==n-1) continue;
                i+1<m?down=grid[i+1][j]:down=INT_MAX;
                j+1<n?right=grid[i][j+1]:right=INT_MAX;
                grid[i][j]+=min(down,right);
            }
        }
        
        return grid[0][0];
    }
};
