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
class Solution 
{
public:
    vector<vector<int>> verticalOrder(TreeNode* root) 
    {
        // have a map <int,vector<int>> mp;
        //mp[0] = [3,15]
        //mp[-1] = [9]
        //mp[1] = [20]
        //mp[2] = [7]    
        
        // vector<pair<TreeNode*, int>> 
       
        vector<vector<int>> out;
         if(!root){
            return out;
        }
        vector<pair<TreeNode*, int>> curs;
        map<int,vector<int>> mp;
        
        curs.push_back(make_pair(root,0));
        while(!curs.empty()){
            vector<pair<TreeNode*,int>> tmp;
            for(auto cur:curs){
                mp[cur.second].push_back(cur.first->val);
                if(cur.first->left){
                   tmp.push_back(make_pair(cur.first->left,cur.second-1)) ;
                
                }
                if(cur.first->right){
                    tmp.push_back(make_pair(cur.first->right,cur.second+1)) ;
                    
                }
            }
             curs = tmp;
        }
        
        for(auto itr=mp.begin();itr!=mp.end();itr++){
            out.push_back(itr->second);
        }
        return out;
            
        
        
    }
};