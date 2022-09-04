// Link:  https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

class Solution {
private:
    map<int,vector<pair<int,int>>> mp;   // horizontal level, <data, vertical level>
    
    void solve(TreeNode *root, int hor, int ver){
        if(!root)
            return;
        mp[hor].push_back(make_pair(root->val,ver));
        
        solve(root->left,hor-1,ver+1);
        solve(root->right,hor+1,ver+1);
    }
    
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        
        solve(root,0,0);
        
        for(auto i:mp){
            vector<pair<int,int>> temp=i.second;
            sort(temp.begin(),temp.end(),[](auto &a, auto &b){
                if(a.second==b.second)
                    return a.first<b.first;
                return a.second<b.second;
            });
                
            vector<int> res;
            for(auto i:temp){
                res.push_back(i.first);
            }
            ans.push_back(res);
        }
    
        return ans;
    }
};
