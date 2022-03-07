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
        int calcDepthRecurse(TreeNode* root, int depth){
           
            int left = 0,right=0;
            while(1){
                if(root->left==NULL && root->right==NULL){
                    return depth;
                }
                if(root->left){
                    left=calcDepthRecurse(root->left,depth+1);
                }
                if(root->right){
                    right=calcDepthRecurse(root->right,depth+1);
                }
                return max(left,right);
            }
            
            
        }
    
    int calcDepthIterative(TreeNode* root){
        stack<pair<int,TreeNode*>> st;
        int res=0;
        if(root==NULL){
            return res;
        }
        st.push(make_pair(1,root));
        while(!st.empty()){
            int depth = st.top().first;
            res = max(depth,res);
            TreeNode* node = st.top().second;
            st.pop();
            if(node->left){
                st.push(make_pair(depth+1,node->left));
            }
            if(node->right){
                st.push(make_pair(depth+1,node->right));
            }
            
        }
        return res;
        
        
    }
    int maxDepth(TreeNode* root){
     
        //return calcDepthRecurse(root,1);
        return calcDepthIterative(root);
    }
};






