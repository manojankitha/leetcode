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
    int calcDepth(TreeNode* root,int depth){
        
        int left=0,right=0;
        if(root->left==NULL && root->right==NULL){
            return depth;
        }
        if(root->left){
            left = calcDepth(root->left,depth+1);
        }
        if(root->right){
            right = calcDepth(root->right,depth+1);
        }
        return max(left,right);
    }
    
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        return calcDepth(root,1);
        
        
        
        
        
    }
};