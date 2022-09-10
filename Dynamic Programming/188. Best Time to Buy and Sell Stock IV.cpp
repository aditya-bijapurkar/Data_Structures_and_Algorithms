//  Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

class Solution{
private:
    int dp[1001][2][101];
    
    int fun(vector<int> &prices, int i, int n, int buy, int rem){
        if(rem==0)
            return 0;
        if(i==n)
            return 0;
        if(dp[i][buy][rem]!=-1)
            return dp[i][buy][rem];
        
        if(buy){
            return dp[i][buy][rem]=max(-prices[i]+fun(prices,i+1,n,0,rem), fun(prices,i+1,n,1,rem));
        }
        else{
            return dp[i][buy][rem]=max(prices[i]+fun(prices,i+1,n,1,rem-1), fun(prices,i+1,n,0,rem));
        }
        
        return dp[i][buy][rem];
    }
     
public:
    int maxProfit(int k, vector<int>& prices){
        int n=prices.size();
        memset(dp,-1,sizeof(dp));
        
        return fun(prices,0,n,1,k);
    }
};
