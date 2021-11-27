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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode *temp = new TreeNode(val);
            return temp;
        }
        TreeNode *temp=root;
        TreeNode *node1 = new TreeNode(val);
        while(true){
            if(temp->val<val){
                if(temp->right==NULL){
                    temp->right = node1;
                    break;
                }
                else{
                    temp = temp->right;
                }
            }
            else{
                if(temp->left==NULL){
                    temp->left = node1;
                    break;
                }
                else{
                    temp = temp->left;
                }
            }
        }
        return root;
    }
};