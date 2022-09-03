//  Link: https://leetcode.com/problems/numbers-with-same-consecutive-differences/

class Solution {
private:
    vector<int> ans;
    
    void dfs(int n, int k, int num){
        if(n==0){
            ans.push_back(num);
            return;
        }
        
        vector<int> digits;
        int tail=num%10;
        digits.push_back(tail+k);
        if(k!=0) digits.push_back(tail-k);
        
        for(int digit:digits){
            if(digit>=0 && digit<10){
                int next=num*10+digit;
                dfs(n-1,k,next);
            }
        }
    }
    
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int num=1;num<10;num++){
            dfs(n-1,k,num);
        }
        
        return ans;
    }
};
