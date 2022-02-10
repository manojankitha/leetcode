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
    // recursive approach
// private:
//     void postOrder(TreeNode *root, vector<int>& nodes){
//         if(root==NULL){
//             return;
//         }
//         postOrder(root->left,nodes);
//         postOrder(root->right,nodes);
//         nodes.push_back(root->val);
//     }
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> nodes;
//         postOrder(root, nodes);
//         return nodes;      
//     }
    
    // iterative approach
    public:
    vector<int> postorderTraversal(TreeNode* root){
        
        vector<int> po;
        if(root==NULL){
            return po;
        }
        stack<TreeNode*> st;
        TreeNode *curr = root;
        
        while(!st.empty() || curr!=NULL){
            if(curr!=NULL){
                st.push(curr);
                curr = curr->left;
            }else{
                TreeNode *temp = st.top()->right;
                if(temp == NULL){
                    temp = st.top();
                    st.pop();
                    po.push_back(temp->val);
                    while(!st.empty() && temp==st.top()->right){
                        temp = st.top();
                        st.pop();
                        po.push_back(temp->val);
                    }
                    
                }else{
                    curr = temp;
                }
            }
            
        }
        return po;
        
        
        
    }
};