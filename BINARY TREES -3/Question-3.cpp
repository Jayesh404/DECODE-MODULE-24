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
    TreeNode* build(vector<int>& inorder,int inlo,int inhi, vector<int>& postorder,int postlo,int posthi){
        if(postlo>posthi) return NULL;
        TreeNode* root=new TreeNode(postorder[posthi]);
        if(postlo==posthi) return root;
        
        int i=inlo;
        while(i<=inhi){
            if(inorder[i]==postorder[posthi]) break;
            i++;
        }
        int leftCount=i-inlo;
        int rightCount=inhi-i;
        root->left=build(inorder,inlo,i-1,postorder,postlo,postlo+leftCount-1);
        root->right=build(inorder,i+1,inhi,postorder,postlo+leftCount,posthi-1);
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n= postorder.size();
        return build(inorder,0,n-1,postorder,0,n-1);
    }
};