//226
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
/**
* Definition for a binary tree node.
struct Tree {
   int val;
   Tree* left;
   Tree* right;
   Tree(): val(0), left(nullptr), right(nullptr) {}
   Tree(x):
   Tree(x, Tree* left, Tree* right)
}
*/
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;

        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = temp;
        
        invertTree(root->right);
        invertTree(root->left);

        return root;
    }
};

//104 
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        int maxD = INT_MIN;
        int leftD, rightD;
        leftD = maxDepth(root->left) + 1;
        rightD = maxDepth(root->right) + 1;

        maxD = max(leftD, rightD);
        return maxD;
    }
};

// 110
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
    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }
    int check(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        int leftD = check(root->left);
        if (leftD == -1)
            return -1;
        int rightD = check(root->right);
        if (rightD == -1)
            return -1;
        if (abs(leftD - rightD) > 1)
            return -1;
        return 1 + max(leftD, rightD);
    }
};