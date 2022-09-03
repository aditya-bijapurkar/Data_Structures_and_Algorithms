// Link: https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans=INT_MAX, count=0, n=blocks.length();
        
        for(int i=0;i<=n-k;i++){
            count=0;
            for(int j=i;j<k+i;j++){
                if(blocks[j]=='W')
                    count++;
            }
            ans=min(ans,count);
        }
        
        return ans;
    }
};
