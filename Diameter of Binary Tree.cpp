/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
public:
    int height(TreeNode* root)
    {
      if(root == NULL) return 0;

      int left = height(root->left);
      int right = height(root->right);

      return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        // diameter through root will be leftHeight + rightHeight
        int leftHeight = height(root -> left);
        int rightHeight = height(root -> right);

        // diameter without passing through root
        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);


        //the final diameter will be max among all
        return max({leftDiameter, rightDiameter, (leftHeight + rightHeight)});
    }
};