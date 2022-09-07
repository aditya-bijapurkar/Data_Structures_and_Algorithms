// Link:  https://leetcode.com/problems/construct-string-from-binary-tree/

class Solution{
private:
    string ans="";
    
    void preorder(TreeNode *root){
        if(root==NULL){
            return;
        }
        
        ans+=to_string(root->val);
        if(root->left){
            ans+="(";
            preorder(root->left);
            ans+=")";
        }
        if(!root->left && root->right){
            ans+="()";
            ans+="(";
            preorder(root->right);
            ans+=")";
        }
        else if(root->right){
            ans+="(";
            preorder(root->right);
            ans+=")";
        }
    }
    
public:
    string tree2str(TreeNode* root) {
        preorder(root);
        return ans;
    }
};
