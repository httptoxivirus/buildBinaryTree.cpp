#include<iostream>
using namespace std;
class node {
public:
    int data;
    node *left, *right;
    //constructor with data
    node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root) {
    int data;
    cout<<"Enter the data ";
    cin>>data;
    // base case
    if(data == -1) return NULL;     //considering after -1 we don't want to insert anything :
    root = new node(data);
    cout<<"Enter the value to insert in left : ";
    node* left = buildTree(root->left);
    cout<<"Enter the value to insert in right : ";
    node* right = buildTree(root->right);
    return root;
}

int main() {
    node* root = NULL;
    root = buildTree(root);
}
