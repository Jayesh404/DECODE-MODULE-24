# include<iostream>
#include<algorithm>
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
    int maxi=-1000000;
    int level(TreeNode* root){
        if(root==NULL) return 0;
        else return max(1+level(root->left),1+level(root->right));
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int dia=level(root->left)+level(root->right);
        maxi=max(dia,maxi);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return maxi;
    }
};