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
// recursive - top bottom solution
class Solution {
    public:
    
    int calcDepthRecursive(TreeNode* root, int depth){
        int left = 0,right=0;
        int maxDepth=depth;
        while(1){
            if(root->left==NULL && root->right==NULL){
                return maxDepth;
            }
            if(root->left){
                left = calcDepthRecursive(root->left, 1+depth);
            }
            if(root->right){
                right = calcDepthRecursive(root->right, 1+depth);
            }
            maxDepth = max(left,right);
        }
        return maxDepth;
    }
    
    
    
  
    int maxDepth(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int maxLeft = maxDepth(root->left);
        int maxRight = maxDepth(root->right);  
        return 1+max(maxLeft, maxRight);
    }
};