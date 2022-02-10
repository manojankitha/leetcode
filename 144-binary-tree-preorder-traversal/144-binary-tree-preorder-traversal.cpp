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
    private:
    void preOrder(TreeNode *root, vector<int> &nodes){
        if(root==NULL){
            return;
        }
        nodes.push_back(root->val);
        preOrder(root->left, nodes);
        preOrder(root->right, nodes);
    }
public:
    
    // iterative approach
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> out;
    //     if(root==NULL){
    //         return out;
    //     }
    //     stack<TreeNode*> st;
    //     st.push(root);
    //     while(!st.empty()){
    //         root = st.top();
    //         st.pop();
    //         out.push_back(root->val);
    //         if(root->right!=NULL){
    //             st.push(root->right);
    //         }
    //         if(root->left!=NULL){
    //             st.push(root->left);
    //         }
    //     }
    //    return out;
    // }
    
    // recursive approach
     vector<int> preorderTraversal(TreeNode* root) {
         vector<int> nodes;
         preOrder(root, nodes);
         return nodes;
        
    }
};