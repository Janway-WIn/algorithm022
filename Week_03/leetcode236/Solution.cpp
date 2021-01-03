class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)   return root;
        if (root == p || root == q) return root; 
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left != NULL && right != NULL)  return root;
        else if (left == NULL)  return right;
        else if (right == NULL) return left;
        else return NULL;
    }
}; //时间复杂度O（n）  空间复杂度O（n） 87.21%  46.00%
