//  Link: https://leetcode.com/problems/find-the-town-judge/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int isTrusted[n+1], trusts[n+1];
        memset(isTrusted,0,sizeof(isTrusted));
        memset(trusts,0,sizeof(trusts));
        int k=trust.size();
        
        for(int i=0;i<k;i++){
            trusts[trust[i][0]]++;
            isTrusted[trust[i][1]]++;
        }
        
        for(int i=1;i<=n;i++){
            if(trusts[i]==0 && isTrusted[i]==n-1)
                return i;
        }
        
        return -1;
    }
};
