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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> out;
        if(!root){
            return out;
        }
        
        queue<TreeNode*> que;
        que.push(root);
        
        while(!que.empty()){
            int s = que.size();
            pair<long,int> tmp;
            while(s--){
                TreeNode *popped = que.front();
                que.pop();
                if(tmp.second==0){
                    tmp = make_pair(popped->val,1);
                } else{
                    tmp.first+=popped->val;
                    tmp.second +=1;
                }
               
                if(popped->left){
                    que.push(popped->left);
                }
                if(popped->right){
                    que.push(popped->right);
                }
            }
            out.push_back(double(tmp.first)/tmp.second);
        }
        return out;
    }
};
        
