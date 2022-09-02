// Link:    https://leetcode.com/problems/maximum-length-of-repeated-subarray/

class Solution{
//   DP: if two characters are equal then they largest common length will be 1 more than the result in the diagonal

public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(), n=nums2.size();
        int ans=0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(nums1[i]==nums2[j]){
                    dp[i+1][j+1]=1+dp[i][j];
                    ans=max(ans,dp[i+1][j+1]);
                }
            }
        }
        
        return ans;
    }
};
