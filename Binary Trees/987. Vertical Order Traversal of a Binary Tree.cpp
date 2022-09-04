// Link:  https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

class Solution {
private:
    unordered_map<int,vector<pair<int,int>>> ump;   // horizontal level, <data, vertical level>
    int leftmost=0, rightmost=0;
    
    void solve(TreeNode *root, int hor, int ver){
        if(!root)
            return;
        ump[hor].push_back(make_pair(root->val,ver));
        if(hor<leftmost) leftmost=hor;
        if(hor>rightmost) rightmost=hor;
        
        solve(root->left,hor-1,ver+1);
        solve(root->right,hor+1,ver+1);
    }
    
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        
        solve(root,0,0);
        
        for(int i=leftmost;i<=rightmost;i++){
            vector<pair<int,int>> temp=ump[i];
            sort(temp.begin(),temp.end(),[](auto &a, auto &b){
                if(a.second==b.second)
                    return a.first<b.first;
                return a.second<b.second;
            });
                
            vector<int> res;
            for(auto j:temp){
                res.push_back(j.first);
            }
            ans.push_back(res);
        }
    
        return ans;
    }
};
