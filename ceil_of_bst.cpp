/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    static int ceil = -1;
    if(node==NULL){
        return ceil;
    }
    if(node->data==x){
        ceil = x;
        return ceil;
    }
    else if(node->data>x){
        ceil = min(node->data,findCeil(node->left,x));
    }
    else{
		ceil = findCeil(node->right,x);
    }
}