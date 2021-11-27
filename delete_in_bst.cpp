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
    
    TreeNode *lastR(TreeNode *root){
        while(root->right){
            root = root->right;
        }
        return root;
    }
    
    TreeNode *helper(TreeNode *root){
        if(root->left==NULL){
            return root->right;
        }
        if(root->right==NULL){
            return root->left;
        }
        TreeNode *rightChild = root->right;
        TreeNode *lastRight = lastR(root->left);
        lastRight->right = rightChild;
        
        return root->left;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        if(root->val == key){
            return helper(root);
        }
        TreeNode *temp = root;
        while(temp!=NULL){
            if(temp->val > key){
                if(temp->left && temp->left->val==key){
                    temp->left = helper(temp->left);
                }
                else{
                    temp = temp->left;
                }
            }
            else{
                if(temp->right && temp->right->val == key){
                    temp->right = helper(temp->right);
                }
                else{
                    temp = temp->right;
                }
            }
        }
        return root;
    }
};