#include <iostream>

using namespace std;

struct BSTNode
{
    int data;
    BSTNode* left;
    BSTNode* right;
};

void inOrder(BSTNode* root)
{
  if (root==nullptr) return;
  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}

int Min(BSTNode* root)
{
    if(root==nullptr)
    {
        cout << "The tree is empty." << endl;
        return 0;
    }
    while(root->left!=nullptr)
    {
        root=root->left;
    }
    return root->data;
}

int Minrec(BSTNode* root)
{
    if(root==nullptr)
    {
        cout << "The tree is empty." << endl;
        return 0;
    }
    else if (root->left==nullptr)
    {
        return root->data;
    }
    return Minrec(root->left);
}

int Max(BSTNode* root)
{
    if(root==nullptr)
    {
        cout << "The tree is empty." << endl;
        return 0;
    }
    while(root->right!=nullptr)
    {
        root=root->right;
    }
    return root->data;
}


void insertrec(BSTNode*& root, int data)
{

    if(root==nullptr)
    {
        BSTNode* newnode= new BSTNode;
        newnode->data=data;
        newnode->left=nullptr;
        newnode->right=nullptr;
        root=newnode;
        return;
    }
    if(data<=root->data)
    {
        insertrec(root->left,data);
    }
    else
    {
        insertrec(root->right,data);
    }

}



int main()
{
    BSTNode* root = nullptr;
    inOrder(root);
    while(true)
    {
        int i;
        cout << ":";
        cin >> i;
        if(i==0) break;
        insertrec(root,i);
        inOrder(root);
        cout << endl;

    }

    cout << Max(root) << endl;
    cout << Minrec(root) << endl;

    return 0;
}
