// link: https://leetcode.com/problems/count-good-nodes-in-binary-tree/

class Solution {
private:
    int ans=0;
    
    void dfs(TreeNode *root, int max_){
        if(!root)
            return;
        if(root->val>=max_){
            ans++;
            max_=root->val;
        }
        
        dfs(root->left,max_);
        dfs(root->right,max_);
    }
    
public:
    int goodNodes(TreeNode* root) {
        int max_=INT_MIN;
        dfs(root,max_);
        
        return ans;
    }
};
