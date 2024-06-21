# include<iostream>
#include<algorithm>
# include<vector>
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
    void helper(TreeNode* root,vector<int>& arr,int target,int n=0){
        if(root==NULL) return;
        if(n==target) arr.push_back(root->val);
            helper(root->left,arr,target,n+1);
            helper(root->right,arr,target,n+1);
    
    }
    void helper2(TreeNode* root,vector<int>& arr,int target,int n=0){
        if(root==NULL) return;
        if(n==target) arr.push_back(root->val);
            helper2(root->right,arr,target,n+1);
            helper2(root->left,arr,target,n+1);
    
    }
    void lorder(TreeNode* root,vector<vector<int>>& ans){
        int n=level(root);
        for(int i=0;i<n;i++){
            vector<int> v;
            if(i%2==0) helper(root,v,i);
            else helper2(root,v,i);
            ans.push_back(v);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        lorder(root,ans);
        return ans;
    }
};