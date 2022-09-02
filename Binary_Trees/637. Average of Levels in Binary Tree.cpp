//  Link: https://leetcode.com/problems/average-of-levels-in-binary-tree/

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root){
        vector<double> ans;
        queue<TreeNode *> q;
        q.push(root);
        long long curr;
        
        while(!q.empty()){
            curr=0;
            int s=q.size();
            for(int i=0;i<s;i++){
                curr+=q.front()->val;
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
            ans.push_back((double)curr/s);
        }
        
        return ans;
    }
};
