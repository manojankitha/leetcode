/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        
     vector<vector<int>> out;
        if(!root){
            return out;
        }
        
        queue<TreeNode*> que;
        que.push(root);
        
        while(!que.empty()){
            int s = que.size();
            vector<int> tmp;
            while(s--){
                TreeNode *popped = que.front();
                que.pop();
                tmp.push_back(popped->val);
                if(popped->left){
                    que.push(popped->left);
                }
                if(popped->right){
                    que.push(popped->right);
                }
            }
            out.push_back(tmp);
        }
        return out;
    }
};