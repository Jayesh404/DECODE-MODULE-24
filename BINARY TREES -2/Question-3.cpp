# include<iostream>
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
    // level(root->left);
    // level(root->right);
}

void displayLvl(Node* root,int target,int n=0){
    if(root==NULL) return;
    if(n==target) cout<<root->val<<" ";
    displayLvl(root->right,target,n+1);
    displayLvl(root->left,target,n+1);

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

    int levels=level(a);
    for(int i=0;i<levels;i++){
        displayLvl(a,i);
        cout<<endl;
    }

    return 0;
}