# include<iostream>
# include <vector>
using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};

int level(Node* root){
    if(root==NULL) return 0;
    else return max(1+level(root->left),1+level(root->right));
}

void leftview(Node* root,vector<int>& ans,int lvl){
    if(root==NULL) return;
    ans[lvl]=root->val;
    leftview(root->right,ans,lvl+1);
    leftview(root->left,ans,lvl+1);

}

int main(){

    Node* a= new Node(1);
    Node* b= new Node(2);
    Node* c= new Node(3);
    Node* d= new Node(4);
    Node* e= new Node(5);
    Node* f= new Node(6);
    Node* g= new Node(7);

    a->right=c;
    a->left=b;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;

    vector<int> ans(level(a),0);

    leftview(a,ans,0);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}