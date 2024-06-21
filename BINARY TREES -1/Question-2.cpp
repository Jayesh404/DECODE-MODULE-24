# include<iostream>
# include<climits>
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

int mini(Node* root){
    if(root==NULL) return INT_MAX;
    else return min(min(root->val,mini(root->left)),mini(root->right));
}


int main(){

    Node* a= new Node(1);
    Node* b= new Node(2);
    Node* c= new Node(3);
    Node* d= new Node(44);
    Node* e= new Node(5);
    Node* f= new Node(6);
    Node* g= new Node(7);

    a->right=c;
    a->left=b;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;

    // maximum(a);
    // cout<<maxi;

    cout<<mini(a);

    return 0;
}