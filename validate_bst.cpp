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
   
    bool helper(TreeNode *root,long long mini,long long maxi){
        if(root==NULL)  return true;
        
        bool validate = root->val < maxi && root->val > mini;
        
        return validate && helper(root->left,mini,root->val) && helper(root->right,root->val,maxi);
    }
    
    bool isValidBST(TreeNode* root) {
        long mini = LLONG_MIN;
        long maxi = LLONG_MAX;
        
        return helper(root,mini,maxi);
        
    }
};