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

    TreeNode* build(vector<int>& preorder,int prelo,int prehi, vector<int>& postorder,int postlo,int posthi){
        if(prelo>prehi) return NULL;
        if(postlo>posthi) return NULL;

        TreeNode* root= new TreeNode(preorder[prelo]);
        if(prelo==prehi) return root;
        int i=prelo+1;
        while(i<prehi){
            if(preorder[i]==postorder[posthi-1]) break;
            i++;
        }
        int leftcount=i-prelo;
        root->left=build(preorder,prelo+1,prelo+leftcount-1,postorder,postlo,postlo+leftcount-2);
        root->right=build(preorder,prelo+leftcount,prehi,postorder,postlo+leftcount-1,posthi-1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n=preorder.size();
        return build(preorder,0,n-1,postorder,0,n-1);
    }
};