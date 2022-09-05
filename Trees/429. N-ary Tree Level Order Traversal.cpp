//  Link: https://leetcode.com/problems/n-ary-tree-level-order-traversal/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<Node *> q;
        vector<int> temp;
        
        q.push(root);
        
        while(!q.empty()){
            temp.clear();
            int s=q.size();
            for(int i=0;i<s;i++){
                Node *curr=q.front();
                temp.push_back(curr->val);
                q.pop();
                
                int c=curr->children.size();
                for(int i=0;i<c;i++){
                    q.push(curr->children[i]);
                }
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};
