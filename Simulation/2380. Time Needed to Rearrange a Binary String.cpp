// Link: https://leetcode.com/problems/time-needed-to-rearrange-a-binary-string/

class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n=s.length();
        bool clear=true;
        int ans=0;
        
        while(clear){
            clear=false;
            for(int i=0;i<n-1;i++){
                if(s[i]=='0' && s[i+1]=='1'){
                    swap(s[i],s[i+1]);
                    clear=true;
                    i++;
                }
            }
            if(clear)
                ans++;
        }
        
        return ans;
    }
};
