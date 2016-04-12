/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, int& r, int& n){
        r = root -> val;
        n = 0;
        
        if(root->left){
            int lr, ln;
            dfs(root->left, lr, ln);
            r += ln;
            n += max(ln,lr);
        }
        
        if(root->right){
            int rr, rn;
            dfs(root->right, rr, rn);
            r += rn;
            n += max(rn,rr);
        }
        
        
    }
    int rob(TreeNode* root) {
        int r, n;
        if(!root) return 0;
        dfs(root, r, n);
        return max(r, n);
    }
};