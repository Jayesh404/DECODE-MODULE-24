# include<iostream>
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

    int level(TreeNode* root){
        if(root==NULL) return 0;
        else return max(1+level(root->left),1+level(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int leftLevel=level(root->left);
        int rightLevel=level(root->right);
        if(abs(leftLevel-rightLevel)>1) return false;
        else return isBalanced(root->right) && isBalanced(root->left);
    }
}; 