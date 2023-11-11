#include<iostream>
#include<queue>
using namespace std;
class node {
public:
    int data;
    node *left;
    node* right;
    
    //constructor with data
    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root) {
    int val;
    cout<<"Enter the data ";
    cin>>val;
    root = new node(val);
    // base case
    if(val == -1) return NULL;     //considering after -1 we don't want to insert anything :
    cout<<"Enter the value to insert in left : ";
    root->left = buildTree(root->left);
    cout<<"Enter the value to insert in right : ";
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()) {
        node* temp = q.front();
        q.pop();
        if(temp == NULL) {
            cout<<endl;
            if(!q.empty()) {    //iska mtlab abhi levels bxhe hain
                q.push(NULL);
            }
        }
        else {
            cout<<temp->data<<" ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}

void inorderTraversal(node* root) {
    // base case
    if(root == NULL) return;
    
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

int main() {
    node* root = NULL;
    root = buildTree(root);
    levelOrderTraversal(root);
    return 0;
}
