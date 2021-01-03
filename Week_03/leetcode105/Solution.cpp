class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pSize = preorder.size();
        int iSize = inorder.size();
        if (pSize == 0 || iSize == 0 || pSize != iSize) return NULL;
        unordered_map<int, int> m;
        for (int i = 0; i < pSize; i++) {
            m[inorder[i]] = i;
        }
        return helper(preorder, 0, pSize, inorder, 0, iSize, m);
    }

    TreeNode* helper(vector<int>& preorder, int pStart, int pEnd, vector<int>& inorder, int iStart, int iEnd, unordered_map<int, int>& m) {
        if (pStart == pEnd) return NULL;
        int rootVal = preorder[pStart];
        int rootInInorder = m[rootVal];
        int leftNum = rootInInorder - iStart;
        TreeNode* root = new TreeNode(rootVal);
        root->left = helper(preorder, pStart + 1, pStart + leftNum + 1, inorder, iStart, rootInInorder, m);
        root->right = helper(preorder, pStart + leftNum + 1, pEnd, inorder, rootInInorder + 1, iEnd, m);
        return root;
    }
}; //时间复杂度O（n）  空间复杂度O（n）
