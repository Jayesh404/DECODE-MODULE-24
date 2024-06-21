# include<iostream>
# include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    bool helper(TreeNode* root,int sum){
        if(root==NULL) return false;
        if(root->left==NULL && root->right==NULL){
            if(root->val==sum) return true;
        }
        return helper(root->left,sum-(root->val)) || helper(root->right,sum-(root->val));

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root,targetSum);
    }
};