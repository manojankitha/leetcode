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


class Solution{
    public:
//     int calcDepthRecursive(TreeNode* root, int depth){
//         int left = 0,right=0;
//         while(1){
//             if(root->left==NULL && root->right==NULL){
//                 return depth;
//             }
//             if(root->left){
//                 left=calcDepthRecursive(root->left, depth+1);
//             }
//             if(root->right){
//                 right=calcDepthRecursive(root->right, depth+1);
//             }
//             depth = max(left,right);
//         }
//         return depth;
      
//     }    
 
    int maxDepth(TreeNode* root){
        if(!root){
            return 0;
        }
        int maxLeft = maxDepth(root->left);
        int maxRight = maxDepth(root->right);
        return max(maxLeft,maxRight)+1;
    }
};